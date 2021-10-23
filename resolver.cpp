#include "includes.h"

Resolver g_resolver{};;

LagRecord* Resolver::FindIdealRecord(AimPlayer* data) {
	LagRecord* first_valid, * current;

	if (data->m_records.empty())
		return nullptr;

	first_valid = nullptr;

	// iterate records.
	for (const auto& it : data->m_records) {
		if (it->dormant() || it->immune() || !it->valid())
			continue;

		// get current record.
		current = it.get();

		// first record that was valid, store it for later.
		if (!first_valid)
			first_valid = current;

		// try to find a record with a shot, lby update, walking or no anti-aim.
		if (it->m_shot || it->m_mode == Modes::RESOLVE_LAST_LBY || it->m_mode == Modes::RESOLVE_WALK || it->m_mode == Modes::RESOLVE_NONE)
			return current;
	}

	// none found above, return the first valid record if possible.
	return (first_valid) ? first_valid : nullptr;
}

LagRecord* Resolver::FindLastRecord(AimPlayer* data) {
	LagRecord* current;

	if (data->m_records.empty())
		return nullptr;

	// iterate records in reverse.
	for (auto it = data->m_records.crbegin(); it != data->m_records.crend(); ++it) {
		current = it->get();

		// if this record is valid.
		// we are done since we iterated in reverse.
		if (current->valid() && !current->immune() && !current->dormant())
			return current;
	}

	return nullptr;
}

void Resolver::OnBodyUpdate(Player* player, float value) {
	AimPlayer* data = &g_aimbot.m_players[player->index() - 1];

	// set data.
	data->m_old_body = data->m_body;
	data->m_body = value;
}

float Resolver::GetAwayAngle(LagRecord* record) {
	float  delta{ std::numeric_limits< float >::max() };
	vec3_t pos;
	ang_t  away;

	if (g_cl.m_net_pos.empty()) {
		math::VectorAngles(g_cl.m_local->m_vecOrigin() - record->m_pred_origin, away);
		return away.y;
	}

	float owd = (g_cl.m_latency / 2.f);

	float target = record->m_pred_time;

	// iterate all.
	for (const auto& net : g_cl.m_net_pos) {
		float dt = std::abs(target - net.m_time);

		// the best origin.
		if (dt < delta) {
			delta = dt;
			pos = net.m_pos;
		}
	}

	math::VectorAngles(pos - record->m_pred_origin, away);
	return away.y;
}

void Resolver::MatchShot(AimPlayer* data, LagRecord* record) {

	float shoot_time = -1.f;

	Weapon* weapon = data->m_player->GetActiveWeapon();
	if (weapon) {
		// with logging this time was always one tick behind.
		// so add one tick to the last shoot time.
		shoot_time = weapon->m_fLastShotTime() + g_csgo.m_globals->m_interval;
	}

	float delta = game::TIME_TO_TICKS(shoot_time) - game::TIME_TO_TICKS(record->m_sim_time);

	// this record has a shot on it.
	if (delta == 1)
	{
		record->m_shot = true;
	}
	else if (delta == 0)
	{
		record->m_shot = false;

		if (data->m_records.size() >= 2)
		{
			LagRecord* previous = data->m_records[1].get();

			if (previous && !previous->dormant())
				record->m_eye_angles.x = previous->m_eye_angles.x;
		}
	}
}



void Resolver::SetMode(LagRecord* record) {

	float speed = record->m_velocity.length_2d();

	if ((record->m_flags & FL_ONGROUND) && speed > 1.f && !record->m_fake_walk)
		record->m_mode = Modes::RESOLVE_WALK;

	// if on ground, not moving or fakewalking.
	if ((record->m_flags & FL_ONGROUND) && (speed < 1.f || record->m_fake_walk) && !g_input.GetKeyState(g_menu.main.aimbot.resolver_override.get()))
		record->m_mode = Modes::RESOLVE_STAND;
	// override
	if (g_input.GetKeyState(g_menu.main.aimbot.resolver_override.get()) && record->m_flags & FL_ONGROUND && (speed < 1.f || record->m_fake_walk))
		record->m_mode = Modes::RESOLVE_OVERRIDE;
	// if not on ground.
	else if (!(record->m_flags & FL_ONGROUND))
		record->m_mode = Modes::RESOLVE_AIR;
}

void Resolver::ResolveAngles(Player* player, LagRecord* record) {
	AimPlayer* data = &g_aimbot.m_players[player->index() - 1];

	// mark this record if it contains a shot.
	MatchShot(data, record);

	// next up mark this record with a resolver mode that will be used.
	SetMode(record);

	// we arrived here we can do the acutal resolve.
	if (record->m_mode == Modes::RESOLVE_WALK)
		ResolveWalk(data, record);

	else if (record->m_mode == Modes::RESOLVE_STAND && !(g_input.GetKeyState(g_menu.main.aimbot.resolver_override.get())))
		ResolveStand(data, record);

	else if (record->m_mode == Modes::RESOLVE_OVERRIDE || (g_input.GetKeyState(g_menu.main.aimbot.resolver_override.get())))
		ResolveOverride(player, record, data);

	else if (record->m_mode == Modes::RESOLVE_AIR)
		ResolveAir(data, record);

	// normalize the eye angles, doesn't really matter but its clean.
	math::NormalizeAngle(record->m_eye_angles.y);
}

void Resolver::AntiFreestand(LagRecord* record) {
	// constants
	constexpr float STEP{ 4.f };
	constexpr float RANGE{ 32.f };

	// best target.
	vec3_t enemypos = record->m_player->GetShootPosition();
	float away = GetAwayAngle(record);

	// construct vector of angles to test.
	std::vector< AdaptiveAngle > angles{ };
	angles.emplace_back(away - 180.f);
	angles.emplace_back(away + 90.f);
	angles.emplace_back(away - 90.f);

	// start the trace at the your shoot pos.
	vec3_t start = g_cl.m_local->GetShootPosition();

	// see if we got any valid result.
	// if this is false the path was not obstructed with anything.
	bool valid{ false };

	// iterate vector of angles.
	for (auto it = angles.begin(); it != angles.end(); ++it) {

		// compute the 'rough' estimation of where our head will be.
		vec3_t end{ enemypos.x + std::cos(math::deg_to_rad(it->m_yaw)) * RANGE,
			enemypos.y + std::sin(math::deg_to_rad(it->m_yaw)) * RANGE,
			enemypos.z };

		// draw a line for debugging purposes.
		// g_csgo.m_debug_overlay->AddLineOverlay( start, end, 255, 0, 0, true, 0.1f );

		// compute the direction.
		vec3_t dir = end - start;
		float len = dir.normalize();

		// should never happen.
		if (len <= 0.f)
			continue;

		// step thru the total distance, 4 units per step.
		for (float i{ 0.f }; i < len; i += STEP) {
			// get the current step position.
			vec3_t point = start + (dir * i);

			// get the contents at this point.
			int contents = g_csgo.m_engine_trace->GetPointContents(point, MASK_SHOT_HULL);

			// contains nothing that can stop a bullet.
			if (!(contents & MASK_SHOT_HULL))
				continue;

			float mult = 1.f;

			// over 50% of the total length, prioritize this shit.
			if (i > (len * 0.5f))
				mult = 1.25f;

			// over 90% of the total length, prioritize this shit.
			if (i > (len * 0.75f))
				mult = 1.25f;

			// over 90% of the total length, prioritize this shit.
			if (i > (len * 0.9f))
				mult = 2.f;

			// append 'penetrated distance'.
			it->m_dist += (STEP * mult);

			// mark that we found anything.
			valid = true;
		}
	}

	if (!valid) {
		return;
	}

	// put the most distance at the front of the container.
	std::sort(angles.begin(), angles.end(),
		[](const AdaptiveAngle& a, const AdaptiveAngle& b) {
			return a.m_dist > b.m_dist;
		});

	// the best angle should be at the front now.
	AdaptiveAngle* best = &angles.front();

	record->m_eye_angles.y = best->m_yaw;
}

void Resolver::ResolveOverride(Player* player, LagRecord* record, AimPlayer* data) {

	// get predicted away angle for the player.
	float away = GetAwayAngle(record);

	// pointer for easy access.
	LagRecord* move = &data->m_walk_record;

	C_AnimationLayer* curr = &record->m_layers[3];
	int act = data->m_player->GetSequenceActivity(curr->m_sequence);

	if (g_input.GetKeyState(g_menu.main.aimbot.resolver_override.get())) {
		ang_t                          viewangles;
		g_csgo.m_engine->GetViewAngles(viewangles);

		//auto yaw = math::clamp (g_cl.m_local->GetAbsOrigin(), Player->origin()).y;
		const float at_target_yaw = math::CalcAngle(g_cl.m_local->m_vecOrigin(), player->m_vecOrigin()).y;

		if (fabs(math::NormalizedAngle(viewangles.y - at_target_yaw)) > 30.f)
			return ResolveStand(data, record);

		record->m_eye_angles.y = (math::NormalizedAngle(viewangles.y - at_target_yaw) > 0) ? at_target_yaw + 90.f : at_target_yaw - 90.f;

		//return UTILS::GetLBYRotatedYaw(entity->m_flLowerBodyYawTarget(), (math::NormalizedAngle(viewangles.y - at_target_yaw) > 0) ? at_target_yaw + 90.f : at_target_yaw - 90.f);

		record->m_mode = Modes::RESOLVE_OVERRIDE;
	}

	bool did_lby_flick{ false };

	if (data->m_body != data->m_old_body)
	{
		record->m_eye_angles.y = record->m_body;

		data->m_body_update = record->m_anim_time + 1.1f;

		iPlayers[record->m_player->index()] = false;
		record->m_mode = Modes::RESOLVE_LAST_LBY;
	}
	else
	{
		// LBY SHOULD HAVE UPDATED HERE.
		if (record->m_anim_time >= data->m_body_update) {
			// only shoot the LBY flick 3 times.
			// if we happen to miss then we most likely mispredicted
			if (data->m_body_index < 1) {
				// set angles to current LBY.
				record->m_eye_angles.y = record->m_body;

				data->m_body_update = record->m_anim_time + 1.1f;

				// set the resolve mode.
				iPlayers[record->m_player->index()] = false;
				record->m_mode = Modes::RESOLVE_LAST_LBY;
			}
		}
	}
}

void Resolver::ResolveWalk(AimPlayer* data, LagRecord* record) {
	// apply lby to eyeangles.
	if (data->m_missed_shots > 4 && data->m_missed_shots < 8) {
		AntiFreestand(record); // Fuck this shit throw that retards head behind the wall
		record->m_mode = RESOLVE_WALK;
		data->resolver_mode = XOR("WALKING ANTIFREESTAND");
	}
	else {
		record->m_eye_angles.y = record->m_body;
		record->m_mode = RESOLVE_WALK;
		data->resolver_mode = XOR("WALKING");
	}

	// delay body update.
	data->m_body_update = record->m_anim_time + 0.22f;

	// reset stand and body index.
	data->m_moving_index = 0;
	data->m_stand_index = 0;
	data->m_stand_index2 = 0;
	data->m_body_index = 0;
	data->m_freestanding_index = 0;
	data->m_lby_delta_index = 0;

	// copy the last record that this player was walking
	// we need it later on because it gives us crucial data.
	std::memcpy(&data->m_walk_record, record, sizeof(LagRecord));
}

bool CheckSequence(Player* player, int sequence, bool checklayers = false, int layerstocheck = 15) //decent check could be improved - stolen from cthulhu (sopmk)
{
	// sanity pls
	if (!player || !player->alive())
		return false;

	for (int i = 0; i < checklayers ? layerstocheck : 15; i++) //Check layers
	{
		auto layer = player->m_AnimOverlay()[i];

		if (player->GetSequenceActivity(layer.m_sequence) == sequence) //Check for sequence 
			return true;
	}

	return false; // well this uh 
}

bool CheckLBY(Player* player, LagRecord* record, LagRecord* prev_record) // I would recommend a sequence check -LoOsE (note from sopmk: sequence checks arent always effective, as some lby breakers suppress 979, hence why i'm checking animation values too)
{
	if (player->m_vecVelocity().length_2d() > 1.1f)
		return false; // cant break here

	bool choking = fabs(player->m_flSimulationTime() - player->m_flOldSimulationTime()) > g_csgo.m_globals->m_interval;

	for (int i = 0; i < 13; i++)
	{
		auto layer = record->m_layers[i];
		auto prev_layer = prev_record->m_layers[i];

		// make sure that the animation happened
		if (layer.m_cycle != prev_layer.m_cycle)
		{
			if (layer.m_cycle > 0.9 || layer.m_weight == 1.f) // triggered layer
			{
				if (i == 3) // adjust layer sanity check. If it is the adjust layer, they are most likely breaking LBY
					return true;

				// lby flick lol!
				if (choking && fabs(math::NormalizedAngle(record->m_body - prev_record->m_body)) > 5.f)
					return true;
			}
			else if (choking) // for improper LBY breakers
			{
				if (player->GetSequenceActivity(layer.m_sequence) == 979)
				{
					if (player->GetSequenceActivity(prev_layer.m_sequence) == 979)
					{
						return true; // we can be pretty sure that they are breaking LBY
					}
				}
			}
		}
	}
}

void Resolver::ResolveStand(AimPlayer* data, LagRecord* record) {

	// get predicted away angle for the player.
	float away = GetAwayAngle(record);

	// pointer for easy access.
	LagRecord* move = &data->m_walk_record;
	float delta = record->m_anim_time - move->m_anim_time;

	// we have a valid moving record.
	if (move->m_sim_time > 0.f && !move->dormant() && !record->dormant()) {
		vec3_t delta = move->m_origin - record->m_origin;

		// check if moving record is close.
		if (delta.length() <= 100.f) {
			// indicate that we are using the moving lby.
			data->m_moved = true;
		}
	}

	if (delta < .22f) // can't flick if they moved .22 seconds ago so its just their lby
	{
		record->m_eye_angles.y = move->m_body;

		record->m_mode = Modes::RESOLVE_STOPPED_MOVING;
		record->m_resolver_mode = "STOPPED";
	}
	else if (data->m_body != data->m_old_body && data->m_body_index <= 5) // flick prediction, has .22 flick predict
	{
		record->m_eye_angles.y = data->m_body;

		data->m_body_update = record->m_anim_time + 1.1f;
		iPlayers[record->m_player->index()] = false;
		record->m_mode = Modes::RESOLVE_LBY_UPDATE;
		record->m_resolver_mode = "LBY UPDATE";
	}
	else if (data->m_moved && data->m_moving_index < 1) // last moving if we havn't missed it
	{
		record->m_eye_angles.y = move->m_body;

		record->m_mode = Modes::RESOLVE_LAST_LBY;
		record->m_resolver_mode = "LAST MOVING";
	}
	else if (!data->m_moved || data->m_moving_index >= 1 && data->m_freestanding_index <= 3) // freestanding if we have gone through that shit or missed last moving
	{
		AntiFreestand(record);

		record->m_mode = Modes::RESOLVE_FREESTAND;
		record->m_resolver_mode = "FREESTANDING";
	}
	else // bruteforce as a last fallback
	{
		switch (data->m_stand_index2 % 4)
		{
		case 0:
			record->m_eye_angles.y = away + 180;
			break;

		case 1:
			record->m_eye_angles.y = away - 110;
			break;

		case 2:
			record->m_eye_angles.y = away + 110;
			break;

		case 3:
			record->m_eye_angles.y = away;
			break;
		}

		record->m_mode = Modes::RESOLVE_BRUTEFORCE;
		record->m_resolver_mode = "BRUTEFORCE";
	}
}




void Resolver::ResolveAir(AimPlayer* data, LagRecord* record) {

	// else run our matchmaking air resolver.
	if (record->m_velocity.length_2d() < 60.f) {
		record->m_mode = Modes::RESOLVE_STAND;

		// invoke our stand resolver.
		ResolveStand(data, record);

		return;
	}

	// try to predict the direction of the player based on his velocity direction.
	// this should be a rough estimation of where he is looking.
	float velyaw = math::rad_to_deg(std::atan2(record->m_velocity.y, record->m_velocity.x));

	switch (data->m_missed_shots % 3) {
	case 0:
		record->m_eye_angles.y = velyaw + 180.f;
		break;

	case 1:
		record->m_eye_angles.y = velyaw - 90.f;
		break;

	case 2:
		record->m_eye_angles.y = velyaw + 90.f;
		break;
	}

	record->m_resolver_mode = "AIR";
}

void Resolver::StandNS(AimPlayer* data, LagRecord* record) {
	// get away angles.
	float away = GetAwayAngle(record);

	switch (data->m_shots % 8) {
	case 0:
		record->m_eye_angles.y = away + 180.f;
		break;

	case 1:
		record->m_eye_angles.y = away + 90.f;
		break;

	case 2:
		record->m_eye_angles.y = away - 90.f;
		break;

	case 3:
		record->m_eye_angles.y = away + 45.f;
		break;
	case 4:
		record->m_eye_angles.y = away - 45.f;
		break;

	case 5:
		record->m_eye_angles.y = away + 135.f;
		break;

	case 6:
		record->m_eye_angles.y = away - 135.f;
		break;

	case 7:
		record->m_eye_angles.y = away + 0.f;
		break;

	default:
		break;
	}

	// force LBY to not fuck any pose and do a true bruteforce.
	record->m_body = record->m_eye_angles.y;
}

void Resolver::AirNS(AimPlayer* data, LagRecord* record) {
	// get away angles.
	float away = GetAwayAngle(record);

	switch (data->m_missed_shots % 9) {
	case 0:
		record->m_eye_angles.y = away + 180.f;
		break;

	case 1:
		record->m_eye_angles.y = away + 150.f;
		break;
	case 2:
		record->m_eye_angles.y = away - 150.f;
		break;

	case 3:
		record->m_eye_angles.y = away + 165.f;
		break;

	case 4:
		record->m_eye_angles.y = away - 165.f;
		break;

	case 5:
		record->m_eye_angles.y = away + 135.f;
		break;

	case 6:
		record->m_eye_angles.y = away - 135.f;
		break;

	case 7:
		record->m_eye_angles.y = away + 90.f;
		break;

	case 8:
		record->m_eye_angles.y = away - 90.f;
		break;

	default:
		break;
	}
}

void Resolver::ResolvePoses(Player* player, LagRecord* record) {
	AimPlayer* data = &g_aimbot.m_players[player->index() - 1];

	// only do this bs when in air.
	if (record->m_mode == Modes::RESOLVE_AIR) {
		// ang = pose min + pose val x ( pose range )

		// lean_yaw
		player->m_flPoseParameter()[2] = g_csgo.RandomInt(0, 4) * 0.25f;

		// body_yaw
		player->m_flPoseParameter()[11] = g_csgo.RandomInt(1, 3) * 0.25f;
	}
}
bool Resolver::can_backtrack(Player* entity) {
	float lby_update_time = entity->m_flSimulationTime();
	float current_time = g_csgo.m_globals->m_curtime;

	return ((current_time - lby_update_time) <= 0.2f);
}

std::array<bool, 64> faking_angles = { false };