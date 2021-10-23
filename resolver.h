#pragma once

class ShotRecord;

class Resolver {
public:
	enum Modes : size_t {
		RESOLVE_NONE = 0,
		RESOLVE_WALK,
		RESOLVE_STAND,
		RESOLVE_AIR,
		RESOLVE_LBY_UPDATE,
		RESOLVE_OVERRIDE,
		RESOLVE_LAST_LBY,
		RESOLVE_BRUTEFORCE,
		RESOLVE_FREESTAND,
		RESOLVE_STOPPED_MOVING
	};

public:
	LagRecord* FindIdealRecord(AimPlayer* data);
	LagRecord* FindLastRecord(AimPlayer* data);

	void OnBodyUpdate(Player* player, float value);
	float GetAwayAngle(LagRecord* record);
	void MatchShot(AimPlayer* data, LagRecord* record);
	void ResolveOverride(Player* player, LagRecord* record, AimPlayer* data);
	void SetMode(LagRecord* record);
	void ResolveAngles(Player* player, LagRecord* record);
	void ResolveWalk(AimPlayer* data, LagRecord* record);
	void ResolveStand(AimPlayer* data, LagRecord* record);
	void StandNS(AimPlayer* data, LagRecord* record);
	void ResolveAir(AimPlayer* data, LagRecord* record);
	bool can_backtrack(Player* entity);
	void AirNS(AimPlayer* data, LagRecord* record);
	void AntiFreestand(LagRecord* record);
	void ResolvePoses(Player* player, LagRecord* record);

public:
	std::array< vec3_t, 64 > m_impacts;
	std::string resolver_mode = "";
	int	   iPlayers[64];
};

extern Resolver g_resolver;