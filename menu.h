#pragma once
#include "xorstr.h"

class AimbotTab : public Tab {
public:
	Checkbox	  enable;
	Checkbox	  silent;
	Dropdown	  selection;
	Checkbox	  fov;
	Slider		  fov_amount;
	Dropdown	  weapon_select;

	MultiDropdown hitbox_general;
	MultiDropdown hitbox_history_general;
	MultiDropdown multipoint_general;
	Slider		  scale_general;
	Slider		  body_scale_general;
	Slider		  minimal_damage_general;
	Checkbox	  minimal_damage_hp_general;
	Checkbox	  penetrate_general;
	Slider		  penetrate_minimal_damage_general;
	Checkbox	  penetrate_minimal_damage_hp_general;

	MultiDropdown hitbox_auto;
	MultiDropdown hitbox_history_auto;
	MultiDropdown multipoint_auto;
	Slider		  scale_auto;
	Slider		  body_scale_auto;
	Slider		  minimal_damage_auto;
	Checkbox	  minimal_damage_hp_auto;
	Checkbox	  penetrate_auto;
	Slider		  penetrate_minimal_damage_auto;
	Checkbox	  penetrate_minimal_damage_hp_auto;

	MultiDropdown hitbox_awp;
	MultiDropdown hitbox_history_awp;
	MultiDropdown multipoint_awp;
	Slider		  scale_awp;
	Slider		  body_scale_awp;
	Slider		  minimal_damage_awp;
	Checkbox	  minimal_damage_hp_awp;
	Checkbox	  penetrate_awp;
	Slider		  penetrate_minimal_damage_awp;
	Checkbox	  penetrate_minimal_damage_hp_awp;

	MultiDropdown hitbox_scout;
	MultiDropdown hitbox_history_scout;
	MultiDropdown multipoint_scout;
	Slider		  scale_scout;
	Slider		  body_scale_scout;
	Slider		  minimal_damage_scout;
	Checkbox	  minimal_damage_hp_scout;
	Checkbox	  penetrate_scout;
	Slider		  penetrate_minimal_damage_scout;
	Checkbox	  penetrate_minimal_damage_hp_scout;

	MultiDropdown hitbox_pistols;
	MultiDropdown hitbox_history_pistols;
	MultiDropdown multipoint_pistols;
	Slider		  scale_pistols;
	Slider		  body_scale_pistols;
	Slider		  minimal_damage_pistols;
	Checkbox	  minimal_damage_hp_pistols;
	Checkbox	  penetrate_pistols;
	Slider		  penetrate_minimal_damage_pistols;
	Checkbox	  penetrate_minimal_damage_hp_pistols;

	Checkbox      knifebot;
	Checkbox	  zeusbot;
	Checkbox      debugaim;
	Colorpicker debugaimcol;
	Keybind       override_dmg_key;
	Slider        override_dmg_value;
	Checkbox      override;

	// col2.

	Checkbox      zoom;
	Checkbox      nospread;
	Checkbox      norecoil;
	Keybind       head_key;
	Checkbox      hitchance_general;
	Slider	      hitchance_amount_general;

	Checkbox      hitchance_auto;
	Slider	      hitchance_amount_auto;

	Checkbox      hitchance_awp;
	Slider	      hitchance_amount_awp;

	Checkbox      hitchance_scout;
	Slider	      hitchance_amount_scout;

	Checkbox      hitchance_pistols;
	Slider	      hitchance_amount_pistols;

	Checkbox      ignor_limbs;
	Checkbox      lagfix;

	Checkbox      safep;
	Checkbox	  correct;
	MultiDropdown baim1;
	MultiDropdown baim2;
	MultiDropdown head1;
	Slider        misses;
	Slider        baim_hp;
	Keybind       baim_key;
	Keybind       resolver_override;
	Keybind	      akuzytap;
	Keybind  disablefakelagonkey2;






public:
	void init() {
		// title.
		SetTitle(XOR("Ragebot"));

		enable.setup(XOR("Enable"), XOR("enable"));
		RegisterElement(&enable);

		silent.setup(XOR("Silent aimbot"), XOR("silent"));
		RegisterElement(&silent);

		selection.setup(XOR("Target selection"), XOR("selection"), { XOR("Distance"), XOR("Crosshair"), XOR("Damage"), XOR("Health"), XOR("Lag"), XOR("Height") });
		RegisterElement(&selection);

		weapon_select.setup(XOR("Weapon configs"), XOR("weapon_configs"), { XOR("General"), XOR("Auto"), XOR("Awp"), XOR("Scout"), XOR("Pistols") });
		RegisterElement(&weapon_select);

		/* General */

		hitbox_general.setup(XOR("Hitboxs"), XOR("hitbox_general"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Arms"), XOR("Legs"), XOR("Feet") });
		hitbox_general.AddShowCallback(callbacks::IsWeaponGeneral);
		RegisterElement(&hitbox_general);

		hitbox_history_general.setup(XOR("Backtrack"), XOR("hitbox_history_general"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Arms"), XOR("Legs"), XOR("Feet") });
		hitbox_history_general.AddShowCallback(callbacks::IsWeaponGeneral);
		RegisterElement(&hitbox_history_general);

		multipoint_general.setup(XOR("Multi-point"), XOR("multipoint_general"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Legs") });
		multipoint_general.AddShowCallback(callbacks::IsWeaponGeneral);
		RegisterElement(&multipoint_general);

		scale_general.setup("", XOR("hitbox_scale_general"), 1.f, 100.f, false, 0, 90.f, 1.f, XOR(L"%"));
		scale_general.AddShowCallback(callbacks::IsWeaponGeneral);
		scale_general.AddShowCallback(callbacks::IsMultipointOnGeneral);
		RegisterElement(&scale_general);

		body_scale_general.setup(XOR("Stomach hitbox scale"), XOR("body_hitbox_scale_general"), 1.f, 100.f, true, 0, 50.f, 1.f, XOR(L"%"));
		body_scale_general.AddShowCallback(callbacks::IsWeaponGeneral);
		body_scale_general.AddShowCallback(callbacks::IsMultipointBodyOnGeneral);
		RegisterElement(&body_scale_general);

		hitchance_general.setup(XOR("Minimum hitchance"), XOR("hitchance_general"));
		hitchance_general.AddShowCallback(callbacks::IsConfigMM);
		hitchance_general.AddShowCallback(callbacks::IsWeaponGeneral);
		RegisterElement(&hitchance_general);

		hitchance_amount_general.setup("", XOR("hitchance_amount_general"), 1.f, 100.f, false, 0, 50.f, 1.f, XOR(L"%"));
		hitchance_amount_general.AddShowCallback(callbacks::IsConfigMM);
		hitchance_amount_general.AddShowCallback(callbacks::IsWeaponGeneral);
		hitchance_amount_general.AddShowCallback(callbacks::IsHitchanceOnGeneral);
		RegisterElement(&hitchance_amount_general);

		hitchance_auto.setup(XOR("Minimum hitchance"), XOR("hitchance_auto"));
		hitchance_auto.AddShowCallback(callbacks::IsConfigMM);
		hitchance_auto.AddShowCallback(callbacks::IsWeaponAuto);
		RegisterElement(&hitchance_auto);

		hitchance_amount_auto.setup("", XOR("hitchance_amount_auto"), 1.f, 100.f, false, 0, 50.f, 1.f, XOR(L"%"));
		hitchance_amount_auto.AddShowCallback(callbacks::IsConfigMM);
		hitchance_amount_auto.AddShowCallback(callbacks::IsWeaponAuto);
		hitchance_amount_auto.AddShowCallback(callbacks::IsHitchanceOnAuto);
		RegisterElement(&hitchance_amount_auto);

		hitchance_awp.setup(XOR("Minimum hitchance"), XOR("hitchance_awp"));
		hitchance_awp.AddShowCallback(callbacks::IsConfigMM);
		hitchance_awp.AddShowCallback(callbacks::IsWeaponAWP);
		RegisterElement(&hitchance_awp);

		hitchance_amount_awp.setup("", XOR("hitchance_amount_awp"), 1.f, 100.f, false, 0, 50.f, 1.f, XOR(L"%"));
		hitchance_amount_awp.AddShowCallback(callbacks::IsConfigMM);
		hitchance_amount_awp.AddShowCallback(callbacks::IsHitchanceOnAWP);
		hitchance_amount_awp.AddShowCallback(callbacks::IsWeaponAWP);
		RegisterElement(&hitchance_amount_awp);

		hitchance_scout.setup(XOR("Minimum hitchance"), XOR("hitchance_scout"));
		hitchance_scout.AddShowCallback(callbacks::IsConfigMM);
		hitchance_scout.AddShowCallback(callbacks::IsWeaponScout);
		RegisterElement(&hitchance_scout);

		hitchance_amount_scout.setup("", XOR("hitchance_amount_scout"), 1.f, 100.f, false, 0, 50.f, 1.f, XOR(L"%"));
		hitchance_amount_scout.AddShowCallback(callbacks::IsConfigMM);
		hitchance_amount_scout.AddShowCallback(callbacks::IsHitchanceOnScout);
		hitchance_amount_scout.AddShowCallback(callbacks::IsWeaponScout);
		RegisterElement(&hitchance_amount_scout);

		hitchance_pistols.setup(XOR("Minimum hitchance"), XOR("hitchance_pistols"));
		hitchance_pistols.AddShowCallback(callbacks::IsConfigMM);
		hitchance_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		RegisterElement(&hitchance_pistols);

		hitchance_amount_pistols.setup("", XOR("hitchance_amount_pistols"), 1.f, 100.f, false, 0, 50.f, 1.f, XOR(L"%"));
		hitchance_amount_pistols.AddShowCallback(callbacks::IsConfigMM);
		hitchance_amount_pistols.AddShowCallback(callbacks::IsHitchanceOnPistols);
		hitchance_amount_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		RegisterElement(&hitchance_amount_pistols);

		minimal_damage_general.setup(XOR("Minimum damage"), XOR("minimal_damage_general"), 1.f, 100.f, true, 0, 40.f, 1.f);
		minimal_damage_general.AddShowCallback(callbacks::IsWeaponGeneral);
		RegisterElement(&minimal_damage_general);

		minimal_damage_hp_general.setup(XOR("Auto damage"), XOR("minimal_damage_hp_general"));
		minimal_damage_hp_general.AddShowCallback(callbacks::IsWeaponGeneral);
		minimal_damage_hp_general.AddShowCallback(callbacks::IsDamageVisibleGeneral);
		RegisterElement(&minimal_damage_hp_general);

		penetrate_general.setup(XOR("Automatic penetration"), XOR("penetrate_general"));
		penetrate_general.AddShowCallback(callbacks::IsWeaponGeneral);
		RegisterElement(&penetrate_general);

		penetrate_minimal_damage_general.setup("", XOR("penetrate_minimal_damage_general"), 1.f, 100.f, false, 0, 30.f, 1.f);
		penetrate_minimal_damage_general.AddShowCallback(callbacks::IsWeaponGeneral);
		penetrate_minimal_damage_general.AddShowCallback(callbacks::IsPenetrationOnGeneral);
		RegisterElement(&penetrate_minimal_damage_general);

		penetrate_minimal_damage_hp_general.setup(XOR("Auto damage"), XOR("penetrate_minimal_damage_hp_general"));
		penetrate_minimal_damage_hp_general.AddShowCallback(callbacks::IsWeaponGeneral);
		penetrate_minimal_damage_hp_general.AddShowCallback(callbacks::IsDamageInVisibleGeneral);
		penetrate_minimal_damage_hp_general.AddShowCallback(callbacks::IsPenetrationOnGeneral);
		RegisterElement(&penetrate_minimal_damage_hp_general);

		/* Auto */

		hitbox_auto.setup(XOR("Target hitbox"), XOR("hitbox_auto"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Arms"), XOR("Legs"), XOR("Feet") });
		hitbox_auto.AddShowCallback(callbacks::IsWeaponAuto);
		RegisterElement(&hitbox_auto);

		hitbox_history_auto.setup(XOR("Target hitbox history"), XOR("hitbox_history_auto"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Arms"), XOR("Legs"), XOR("Feet") });
		hitbox_history_auto.AddShowCallback(callbacks::IsWeaponAuto);
		RegisterElement(&hitbox_history_auto);

		multipoint_auto.setup(XOR("Multi-point"), XOR("multipoint_auto"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Legs") });
		multipoint_auto.AddShowCallback(callbacks::IsWeaponAuto);
		RegisterElement(&multipoint_auto);

		scale_auto.setup("", XOR("hitbox_scale_auto"), 1.f, 100.f, false, 0, 90.f, 1.f, XOR(L"%"));
		scale_auto.AddShowCallback(callbacks::IsWeaponAuto);
		scale_auto.AddShowCallback(callbacks::IsMultipointOnAuto);
		RegisterElement(&scale_auto);

		body_scale_auto.setup(XOR("Stomach hitbox scale"), XOR("body_hitbox_scale_auto"), 1.f, 100.f, true, 0, 50.f, 1.f, XOR(L"%"));
		body_scale_auto.AddShowCallback(callbacks::IsWeaponAuto);
		body_scale_auto.AddShowCallback(callbacks::IsMultipointBodyOnAuto);
		RegisterElement(&body_scale_auto);

		minimal_damage_auto.setup(XOR("Minimum damage"), XOR("minimal_damage_auto"), 1.f, 100.f, true, 0, 40.f, 1.f);
		minimal_damage_auto.AddShowCallback(callbacks::IsWeaponAuto);
		RegisterElement(&minimal_damage_auto);

		minimal_damage_hp_auto.setup(XOR("Auto damage"), XOR("minimal_damage_hp_auto"));
		minimal_damage_hp_auto.AddShowCallback(callbacks::IsWeaponAuto);
		minimal_damage_hp_auto.AddShowCallback(callbacks::IsDamageVisibleAuto);
		RegisterElement(&minimal_damage_hp_auto);

		penetrate_auto.setup(XOR("Automatic penetration"), XOR("penetrate_auto"));
		penetrate_auto.AddShowCallback(callbacks::IsWeaponAuto);
		RegisterElement(&penetrate_auto);

		penetrate_minimal_damage_auto.setup("", XOR("penetrate_minimal_damage_auto"), 1.f, 100.f, false, 0, 30.f, 1.f);
		penetrate_minimal_damage_auto.AddShowCallback(callbacks::IsWeaponAuto);
		penetrate_minimal_damage_auto.AddShowCallback(callbacks::IsPenetrationOnAuto);
		RegisterElement(&penetrate_minimal_damage_auto);

		penetrate_minimal_damage_hp_auto.setup(XOR("Auto damage"), XOR("penetrate_minimal_damage_hp_auto"));
		penetrate_minimal_damage_hp_auto.AddShowCallback(callbacks::IsWeaponAuto);
		penetrate_minimal_damage_hp_auto.AddShowCallback(callbacks::IsDamageInVisibleAuto);
		penetrate_minimal_damage_hp_auto.AddShowCallback(callbacks::IsPenetrationOnAuto);
		RegisterElement(&penetrate_minimal_damage_hp_auto);

		/* AWP */

		hitbox_awp.setup(XOR("Target hitbox"), XOR("hitbox_awp"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Arms"), XOR("Legs"), XOR("Feet") });
		hitbox_awp.AddShowCallback(callbacks::IsWeaponAWP);
		RegisterElement(&hitbox_awp);

		hitbox_history_awp.setup(XOR("Target hitbox history"), XOR("hitbox_history_awp"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Arms"), XOR("Legs"), XOR("Feet") });
		hitbox_history_awp.AddShowCallback(callbacks::IsWeaponAWP);
		RegisterElement(&hitbox_history_awp);

		multipoint_awp.setup(XOR("Multi-point"), XOR("multipoint_awp"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Legs") });
		multipoint_awp.AddShowCallback(callbacks::IsWeaponAWP);
		RegisterElement(&multipoint_awp);

		scale_awp.setup("", XOR("hitbox_scale_awp"), 1.f, 100.f, false, 0, 90.f, 1.f, XOR(L"%"));
		scale_awp.AddShowCallback(callbacks::IsWeaponAWP);
		scale_awp.AddShowCallback(callbacks::IsMultipointOnAWP);
		RegisterElement(&scale_awp);

		body_scale_awp.setup(XOR("Stomach hitbox scale"), XOR("body_hitbox_scale_awp"), 1.f, 100.f, true, 0, 50.f, 1.f, XOR(L"%"));
		body_scale_awp.AddShowCallback(callbacks::IsWeaponAWP);
		body_scale_awp.AddShowCallback(callbacks::IsMultipointBodyOnAWP);
		RegisterElement(&body_scale_awp);

		minimal_damage_awp.setup(XOR("Minimum damage"), XOR("minimal_damage_awp"), 1.f, 100.f, true, 0, 40.f, 1.f);
		minimal_damage_awp.AddShowCallback(callbacks::IsWeaponAWP);
		RegisterElement(&minimal_damage_awp);

		minimal_damage_hp_awp.setup(XOR("Auto damage"), XOR("minimal_damage_hp_awp"));
		minimal_damage_hp_awp.AddShowCallback(callbacks::IsWeaponAWP);
		minimal_damage_hp_awp.AddShowCallback(callbacks::IsDamageVisibleAWP);
		RegisterElement(&minimal_damage_hp_awp);

		penetrate_awp.setup(XOR("Automatic penetration"), XOR("penetrate_awp"));
		penetrate_awp.AddShowCallback(callbacks::IsWeaponAWP);
		RegisterElement(&penetrate_awp);

		penetrate_minimal_damage_awp.setup("", XOR("penetrate_minimal_damage_awp"), 1.f, 100.f, false, 0, 30.f, 1.f);
		penetrate_minimal_damage_awp.AddShowCallback(callbacks::IsWeaponAWP);
		penetrate_minimal_damage_awp.AddShowCallback(callbacks::IsPenetrationOnAWP);
		RegisterElement(&penetrate_minimal_damage_awp);

		penetrate_minimal_damage_hp_awp.setup(XOR("Auto damage"), XOR("penetrate_minimal_damage_hp_awp"));
		penetrate_minimal_damage_hp_awp.AddShowCallback(callbacks::IsWeaponAWP);
		penetrate_minimal_damage_hp_awp.AddShowCallback(callbacks::IsDamageInVisibleAWP);
		penetrate_minimal_damage_hp_awp.AddShowCallback(callbacks::IsPenetrationOnAWP);
		RegisterElement(&penetrate_minimal_damage_hp_awp);

		/* Scout */

		hitbox_scout.setup(XOR("Target hitbox"), XOR("hitbox_scout"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Arms"), XOR("Legs"), XOR("Feet") });
		hitbox_scout.AddShowCallback(callbacks::IsWeaponScout);
		RegisterElement(&hitbox_scout);

		hitbox_history_scout.setup(XOR("Target hitbox history"), XOR("hitbox_history_scout"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Arms"), XOR("Legs"), XOR("Feet") });
		hitbox_history_scout.AddShowCallback(callbacks::IsWeaponScout);
		RegisterElement(&hitbox_history_scout);

		multipoint_scout.setup(XOR("Multi-point"), XOR("multipoint_scout"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Legs") });
		multipoint_scout.AddShowCallback(callbacks::IsWeaponScout);
		RegisterElement(&multipoint_scout);

		scale_scout.setup("", XOR("hitbox_scale_scout"), 1.f, 100.f, false, 0, 90.f, 1.f, XOR(L"%"));
		scale_scout.AddShowCallback(callbacks::IsWeaponScout);
		scale_scout.AddShowCallback(callbacks::IsMultipointOnScout);
		RegisterElement(&scale_scout);

		body_scale_scout.setup(XOR("Stomach hitbox scale"), XOR("body_hitbox_scale_scout"), 1.f, 100.f, true, 0, 50.f, 1.f, XOR(L"%"));
		body_scale_scout.AddShowCallback(callbacks::IsWeaponScout);
		body_scale_scout.AddShowCallback(callbacks::IsMultipointBodyOnScout);
		RegisterElement(&body_scale_scout);

		minimal_damage_scout.setup(XOR("Minimum damage"), XOR("minimal_damage_scout"), 1.f, 100.f, true, 0, 40.f, 1.f);
		minimal_damage_scout.AddShowCallback(callbacks::IsWeaponScout);
		RegisterElement(&minimal_damage_scout);

		minimal_damage_hp_scout.setup(XOR("Auto damage"), XOR("minimal_damage_hp_scout"));
		minimal_damage_hp_scout.AddShowCallback(callbacks::IsWeaponScout);
		minimal_damage_hp_scout.AddShowCallback(callbacks::IsDamageVisibleScout);
		RegisterElement(&minimal_damage_hp_scout);

		penetrate_scout.setup(XOR("Automatic penetration"), XOR("penetrate_scout"));
		penetrate_scout.AddShowCallback(callbacks::IsWeaponScout);
		RegisterElement(&penetrate_scout);

		penetrate_minimal_damage_scout.setup("", XOR("penetrate_minimal_damage_scout"), 1.f, 100.f, false, 0, 30.f, 1.f);
		penetrate_minimal_damage_scout.AddShowCallback(callbacks::IsWeaponScout);
		penetrate_minimal_damage_scout.AddShowCallback(callbacks::IsPenetrationOnScout);
		RegisterElement(&penetrate_minimal_damage_scout);

		penetrate_minimal_damage_hp_scout.setup(XOR("Auto damage"), XOR("penetrate_minimal_damage_hp_scout"));
		penetrate_minimal_damage_hp_scout.AddShowCallback(callbacks::IsWeaponScout);
		penetrate_minimal_damage_hp_scout.AddShowCallback(callbacks::IsDamageInVisibleScout);
		penetrate_minimal_damage_hp_scout.AddShowCallback(callbacks::IsPenetrationOnScout);
		RegisterElement(&penetrate_minimal_damage_hp_scout);

		/* Pistols */

		hitbox_pistols.setup(XOR("Target hitbox"), XOR("hitbox_pistols"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Arms"), XOR("Legs"), XOR("Feet") });
		hitbox_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		RegisterElement(&hitbox_pistols);

		hitbox_history_pistols.setup(XOR("Target hitbox history"), XOR("hitbox_history_pistols"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Arms"), XOR("Legs"), XOR("Feet") });
		hitbox_history_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		RegisterElement(&hitbox_history_pistols);

		multipoint_pistols.setup(XOR("Multi-point"), XOR("multipoint_pistols"), { XOR("Head"), XOR("Chest"), XOR("Body"), XOR("Legs") });
		multipoint_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		RegisterElement(&multipoint_pistols);

		scale_pistols.setup("", XOR("hitbox_scale_pistols"), 1.f, 100.f, false, 0, 90.f, 1.f, XOR(L"%"));
		scale_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		scale_pistols.AddShowCallback(callbacks::IsMultipointOnPistols);
		RegisterElement(&scale_pistols);

		body_scale_pistols.setup(XOR("Stomach hitbox scale"), XOR("body_hitbox_scale_pistols"), 1.f, 100.f, true, 0, 50.f, 1.f, XOR(L"%"));
		body_scale_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		body_scale_pistols.AddShowCallback(callbacks::IsMultipointBodyOnPistols);
		RegisterElement(&body_scale_pistols);

		minimal_damage_pistols.setup(XOR("Minimum damage"), XOR("minimal_damage_pistols"), 1.f, 100.f, true, 0, 40.f, 1.f);
		minimal_damage_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		RegisterElement(&minimal_damage_pistols);

		minimal_damage_hp_pistols.setup(XOR("Auto damage"), XOR("minimal_damage_hp_pistols"));
		minimal_damage_hp_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		minimal_damage_hp_pistols.AddShowCallback(callbacks::IsDamageVisiblePistols);
		RegisterElement(&minimal_damage_hp_pistols);

		penetrate_pistols.setup(XOR("Automatic penetration"), XOR("penetrate_pistols"));
		penetrate_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		RegisterElement(&penetrate_pistols);

		penetrate_minimal_damage_pistols.setup("", XOR("penetrate_minimal_damage_pistols"), 1.f, 100.f, false, 0, 30.f, 1.f);
		penetrate_minimal_damage_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		penetrate_minimal_damage_pistols.AddShowCallback(callbacks::IsPenetrationOnPistols);
		RegisterElement(&penetrate_minimal_damage_pistols);

		penetrate_minimal_damage_hp_pistols.setup(XOR("Auto damage"), XOR("penetrate_minimal_damage_hp_pistols"));
		penetrate_minimal_damage_hp_pistols.AddShowCallback(callbacks::IsWeaponPistol);
		penetrate_minimal_damage_hp_pistols.AddShowCallback(callbacks::IsDamageInVisiblePistols);
		penetrate_minimal_damage_hp_pistols.AddShowCallback(callbacks::IsPenetrationOnPistols);
		RegisterElement(&penetrate_minimal_damage_hp_pistols);

		safep.setup(XOR("Prefer safe point"), XOR("safep"));
		RegisterElement(&safep);

		zoom.setup(XOR("Automatic scope"), XOR("zoom"));
		RegisterElement(&zoom);


		knifebot.setup(XOR("Knifebot"), XOR("knifebot"));
		RegisterElement(&knifebot);

		zeusbot.setup(XOR("Zeus bot"), XOR("zeusbot"));
		RegisterElement(&zeusbot);







		// col2.


		norecoil.setup(XOR("Remove recoil"), XOR("norecoil"));
		RegisterElement(&norecoil, 1);

		ignor_limbs.setup(XOR("Ignore limbs when moving"), XOR("ignor_limbs"));
		RegisterElement(&ignor_limbs, 1);

		lagfix.setup(XOR("Delay Shot"), XOR("lagfix"));
		RegisterElement(&lagfix, 1);

		correct.setup(XOR("Anti-Aim correction"), XOR("correct"));
		RegisterElement(&correct, 1);

		baim1.setup(XOR("Prefer body aim"), XOR("baim1"), { XOR("Always"), XOR("Lethal"), XOR("Lethal x2"), XOR("Fake"), XOR("In air"), XOR("After x misses") });
		RegisterElement(&baim1, 1);

		baim2.setup(XOR("Force body aim"), XOR("baim2"), { XOR("Always"), XOR("Health"), XOR("Fake"), XOR("In air"), XOR("After x misses") });
		RegisterElement(&baim2, 1);

		baim_hp.setup("", XOR("baim_hp"), 1.f, 50.f, false, 0, 20.f, 1.f, XOR(L"hp"));
		baim_hp.AddShowCallback(callbacks::IsBaimHealth);
		RegisterElement(&baim_hp, 1);

		misses.setup("", XOR("misses"), 1.f, 10.f, false, 0, 2.f, 1.f);
		misses.AddShowCallback(callbacks::IsAfterMisses);
		RegisterElement(&misses, 1);

		head1.setup(XOR("Prefer head aim"), XOR("head1"), { XOR("Always"), XOR("Running"), XOR("Resolved"), XOR("In air") });
		RegisterElement(&head1, 1);

		baim_key.setup(XOR("Force body aim"), XOR("body aim on key"));
		RegisterElement(&baim_key, 1);

		//head_key.setup(XOR("Force head aim"), XOR("head aim on key"));
		//RegisterElement(&head_key, 1);



		akuzytap.setup(XOR("Double tap"), XOR("doubletap"));
		akuzytap.SetToggleCallback(callbacks::ToggleDT);
		RegisterElement(&akuzytap, 1);




		override_dmg_key.setup(XOR("Min dmg override"), XOR("override_dmg"));
		override_dmg_key.SetToggleCallback(callbacks::ToggleDMG);
		RegisterElement(&override_dmg_key, 1);

		override_dmg_value.setup(" ", XOR("dmg_override"), 1.f, 100.f, false, 0, 1.f, 1.f, XOR(L"hp"));
		override_dmg_value.AddShowCallback(callbacks::IsOverrideDamage);
		RegisterElement(&override_dmg_value, 1);

		resolver_override.setup(XOR("Override resolver"), XOR("resolver_override"));
		RegisterElement(&resolver_override, 1);

		debugaim.setup(XOR("Show shot chams"), XOR("debugaim"));
		RegisterElement(&debugaim,1);

		debugaimcol.setup(XOR("Color"), XOR("debugaimcol"), colors::white);
		RegisterElement(&debugaimcol,1);

	}
};


class AntiAimTab : public Tab {
public:
	// col 1.
	Checkbox enable;
	Checkbox edge;
	Checkbox distortion;
	Slider   distortdelta;
	Dropdown mode;

	Dropdown pitch_stand;
	Dropdown yaw_stand;
	Slider   jitter_range_stand;
	Slider   rot_range_stand;
	Slider   rot_speed_stand;
	Slider   rand_update_stand;
	Dropdown dir_stand;
	Slider   dir_time_stand;
	Slider   dir_custom_stand;
	Checkbox dir_lock;
	//Checkbox pitch_fake_stand;
	Checkbox body_fake_stand_fakewalk;
	Dropdown base_angle_stand;
	Dropdown body_fake_stand;
	Slider	 body_fake_stand_custom;

	Dropdown pitch_walk;
	Dropdown yaw_walk;
	Slider   jitter_range_walk;
	Slider   rot_range_walk;
	Slider   rot_speed_walk;
	Slider   rand_update_walk;
	Dropdown dir_walk;
	Keybind  disablefakelagonkey;
	Slider	 dir_time_walk;
	Slider   dir_custom_walk;
	Dropdown base_angle_walk;

	Dropdown pitch_air;
	Dropdown yaw_air;
	Slider   jitter_range_air;
	Slider   rot_range_air;
	Slider   rot_speed_air;
	Slider   rand_update_air;
	Dropdown dir_air;
	Slider   dir_time_air;
	Slider   dir_custom_air;
	Dropdown base_angle_air;
	Dropdown body_fake_air;

	// col 2.
	Dropdown fake_yaw;
	Slider	 fake_relative;
	Slider	 fake_jitter_range;

	Checkbox      lag_enable;
	MultiDropdown lag_active;
	Dropdown      lag_mode;
	Slider        lag_limit;
	Checkbox      lag_land;

	Colorpicker   color_manul_antiaim;
	Checkbox	  manul_antiaim;
	Checkbox	  draw_angles;
	Checkbox	  draw_angles_chams;
	Colorpicker   color_draw_angles_chams;
	Slider        draw_angles_chams_blend;
	Keybind		  left;
	Keybind		  right;
	Keybind		  backward;
	Keybind		  fakeflick;
	Checkbox revoler_disable;

public:
	void init() {
		SetTitle(XOR("Anti-Aim"));

		enable.setup(XOR("Enable"), XOR("enable"));
		RegisterElement(&enable);

		edge.setup(XOR("Edge"), XOR("edge"));
		RegisterElement(&edge);
		
		distortion.setup(XOR("Distortion"), XOR("distortion"));
		RegisterElement(&distortion);

		distortdelta.setup(XOR("Distortion delta"), XOR("distortdelta"), 35.f, 240.f, true, 0, 75.f, 5.f, XOR(L"�"));
		RegisterElement(&distortdelta);

		mode.setup("", XOR("Mode"), { XOR("Stand"), XOR("Walk"), XOR("Air") }, false);
		RegisterElement(&mode);

		// stand.
		pitch_stand.setup(XOR("Pitch"), XOR("pitch_stnd"), { XOR("Off"), XOR("down"), XOR("Up"), XOR("Ideal") });
		pitch_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		RegisterElement(&pitch_stand);

		yaw_stand.setup(XOR("Yaw"), XOR("yaw_stnd"), { XOR("Off"), XOR("Direction"), XOR("Jitter"), XOR("Rotate"), XOR("Random") });
		yaw_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		RegisterElement(&yaw_stand);



		jitter_range_stand.setup("", XOR("jitter_range_stnd"), 1.f, 180.f, false, 0, 45.f, 5.f, XOR(L"�"));
		jitter_range_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		jitter_range_stand.AddShowCallback(callbacks::IsStandYawJitter);
		RegisterElement(&jitter_range_stand);

		rot_range_stand.setup("", XOR("rot_range_stnd"), 0.f, 360.f, false, 0, 360.f, 5.f, XOR(L"�"));
		rot_range_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		rot_range_stand.AddShowCallback(callbacks::IsStandYawRotate);
		RegisterElement(&rot_range_stand);

		rot_speed_stand.setup("", XOR("rot_speed_stnd"), 1.f, 100.f, false, 0, 10.f, 1.f, XOR(L"%"));
		rot_speed_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		rot_speed_stand.AddShowCallback(callbacks::IsStandYawRotate);
		RegisterElement(&rot_speed_stand);

		rand_update_stand.setup("", XOR("rand_update_stnd"), 0.f, 1.f, false, 1, 0.f, 0.1f);
		rand_update_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		rand_update_stand.AddShowCallback(callbacks::IsStandYawRnadom);
		RegisterElement(&rand_update_stand);

		dir_stand.setup(XOR("Direction"), XOR("dir_stnd"), { XOR("Auto"), XOR("Backwards"), XOR("Left"), XOR("Right"), XOR("Custom") });
		dir_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		dir_stand.AddShowCallback(callbacks::HasStandYaw);
		RegisterElement(&dir_stand);

		dir_time_stand.setup("", XOR("dir_time_stnd"), 0.f, 10.f, false, 0, 0.f, 1.f, XOR(L"s"));
		dir_time_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		dir_time_stand.AddShowCallback(callbacks::HasStandYaw);
		dir_time_stand.AddShowCallback(callbacks::IsStandDirAuto);
		RegisterElement(&dir_time_stand);

		dir_custom_stand.setup("", XOR("dir_custom_stnd"), -180.f, 180.f, false, 0, 0.f, 5.f, XOR(L"�"));
		dir_custom_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		dir_custom_stand.AddShowCallback(callbacks::HasStandYaw);
		dir_custom_stand.AddShowCallback(callbacks::IsStandDirCustom);
		RegisterElement(&dir_custom_stand);

		base_angle_stand.setup(XOR("Base angle"), XOR("base_angle_stand"), { XOR("Off"), XOR("Static"), XOR("Away crosshair"), XOR("Away distance") });
		base_angle_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		base_angle_stand.AddShowCallback(callbacks::HasStandYaw);
		RegisterElement(&base_angle_stand);

		dir_lock.setup(XOR("Lock direction"), XOR("dir_lock"));
		dir_lock.AddShowCallback(callbacks::IsAntiAimModeStand);
		dir_lock.AddShowCallback(callbacks::HasStandYaw);
		RegisterElement(&dir_lock);

		/*pitch_fake_stand.setup(XOR("fake up"), XOR("pitch_fake_stand"));
		pitch_fake_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		pitch_fake_stand.AddShowCallback(callbacks::HasStandYaw);
		RegisterElement(&pitch_fake_stand);*/

		body_fake_stand.setup(XOR("Fake body"), XOR("body_fake_stnd"), { XOR("off"), XOR("break logic"), XOR("random"), XOR("twist"), XOR("autistic"), XOR("custom") });
		body_fake_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		body_fake_stand.AddShowCallback(callbacks::HasStandYaw);
		RegisterElement(&body_fake_stand);

		body_fake_stand_custom.setup(XOR("lby custom"), XOR("body_fake_stand_custom"), -70, 70, false, 0, 0, 1.f, XOR(L"�"));
		body_fake_stand_custom.AddShowCallback(callbacks::IsAntiAimModeStand);
		//body_fake_stand_custom.AddShowCallback(callbacks::HasStandYaw);
		body_fake_stand_custom.AddShowCallback(callbacks::IsCustomLby);
		RegisterElement(&body_fake_stand_custom);

		/*dir_time_stand.setup("", XOR("dir_time_stnd"), 0.f, 10.f, false, 0, 0.f, 1.f, XOR(L"s"));
		dir_time_stand.AddShowCallback(callbacks::IsAntiAimModeStand);
		dir_time_stand.AddShowCallback(callbacks::HasStandYaw);
		dir_time_stand.AddShowCallback(callbacks::IsStandDirAuto);
		RegisterElement(&dir_time_stand);
		lag_limit.setup(XOR("limit"), XOR("lag_limit"), 2, 16, true, 0, 2, 1.f);*/


		// walk.
		pitch_walk.setup(XOR("Pitch"), XOR("pitch_walk"), { XOR("Off"), XOR("Down"), XOR("Up"), XOR("Ideal") });
		pitch_walk.AddShowCallback(callbacks::IsAntiAimModeWalk);
		RegisterElement(&pitch_walk);

		yaw_walk.setup(XOR("Yaw"), XOR("yaw_walk"), { XOR("Off"), XOR("Direction"), XOR("Jitter"), XOR("Rotate"), XOR("Random") });
		yaw_walk.AddShowCallback(callbacks::IsAntiAimModeWalk);
		RegisterElement(&yaw_walk);

		jitter_range_walk.setup("", XOR("jitter_range_walk"), 1.f, 180.f, false, 0, 45.f, 5.f, XOR(L"�"));
		jitter_range_walk.AddShowCallback(callbacks::IsAntiAimModeWalk);
		jitter_range_walk.AddShowCallback(callbacks::IsWalkYawJitter);
		RegisterElement(&jitter_range_walk);

		rot_range_walk.setup("", XOR("rot_range_walk"), 0.f, 360.f, false, 0, 360.f, 5.f, XOR(L"�"));
		rot_range_walk.AddShowCallback(callbacks::IsAntiAimModeWalk);
		rot_range_walk.AddShowCallback(callbacks::IsWalkYawRotate);
		RegisterElement(&rot_range_walk);

		rot_speed_walk.setup("", XOR("rot_speed_walk"), 1.f, 100.f, false, 0, 10.f, 1.f, XOR(L"%"));
		rot_speed_walk.AddShowCallback(callbacks::IsAntiAimModeWalk);
		rot_speed_walk.AddShowCallback(callbacks::IsWalkYawRotate);
		RegisterElement(&rot_speed_walk);

		rand_update_walk.setup("", XOR("rand_update_walk"), 0.f, 1.f, false, 1, 0.f, 0.1f);
		rand_update_walk.AddShowCallback(callbacks::IsAntiAimModeWalk);
		rand_update_walk.AddShowCallback(callbacks::IsWalkYawRandom);
		RegisterElement(&rand_update_walk);

		dir_walk.setup(XOR("Direction"), XOR("dir_walk"), { XOR("Auto"), XOR("Backwards"), XOR("Left"), XOR("Right"), XOR("Custom") });
		dir_walk.AddShowCallback(callbacks::IsAntiAimModeWalk);
		dir_walk.AddShowCallback(callbacks::WalkHasYaw);
		RegisterElement(&dir_walk);

		dir_time_walk.setup("", XOR("dir_time_walk"), 0.f, 10.f, false, 0, 0.f, 1.f, XOR(L"s"));
		dir_time_walk.AddShowCallback(callbacks::IsAntiAimModeWalk);
		dir_time_walk.AddShowCallback(callbacks::WalkHasYaw);
		dir_time_walk.AddShowCallback(callbacks::IsWalkDirAuto);
		RegisterElement(&dir_time_walk);

		dir_custom_walk.setup("", XOR("dir_custom_walk"), -180.f, 180.f, false, 0, 0.f, 5.f, XOR(L"�"));
		dir_custom_walk.AddShowCallback(callbacks::IsAntiAimModeWalk);
		dir_custom_walk.AddShowCallback(callbacks::WalkHasYaw);
		dir_custom_walk.AddShowCallback(callbacks::IsWalkDirCustom);
		RegisterElement(&dir_custom_walk);

		base_angle_walk.setup(XOR("Base angle"), XOR("base_angle_walk"), { XOR("Off"), XOR("Static"), XOR("Away crosshair"), XOR("Away distance") });
		base_angle_walk.AddShowCallback(callbacks::IsAntiAimModeWalk);
		base_angle_walk.AddShowCallback(callbacks::WalkHasYaw);
		RegisterElement(&base_angle_walk);

		// air.
		pitch_air.setup(XOR("Pitch"), XOR("pitch_air"), { XOR("Off"), XOR("Down"), XOR("Up"), XOR("Ideal") });
		pitch_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		RegisterElement(&pitch_air);

		yaw_air.setup(XOR("Yaw"), XOR("yaw_air"), { XOR("Off"), XOR("Direction"), XOR("Jitter"), XOR("Rotate"), XOR("Random") });
		yaw_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		RegisterElement(&yaw_air);

		jitter_range_air.setup("", XOR("jitter_range_air"), 1.f, 180.f, false, 0, 45.f, 5.f, XOR(L"�"));
		jitter_range_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		jitter_range_air.AddShowCallback(callbacks::IsAirYawJitter);
		RegisterElement(&jitter_range_air);

		rot_range_air.setup("", XOR("rot_range_air"), 0.f, 360.f, false, 0, 360.f, 5.f, XOR(L"�"));
		rot_range_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		rot_range_air.AddShowCallback(callbacks::IsAirYawRotate);
		RegisterElement(&rot_range_air);

		rot_speed_air.setup("", XOR("rot_speed_air"), 1.f, 100.f, false, 0, 10.f, 1.f, XOR(L"%"));
		rot_speed_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		rot_speed_air.AddShowCallback(callbacks::IsAirYawRotate);
		RegisterElement(&rot_speed_air);

		rand_update_air.setup("", XOR("rand_update_air"), 0.f, 1.f, false, 1, 0.f, 0.1f);
		rand_update_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		rand_update_air.AddShowCallback(callbacks::IsAirYawRandom);
		RegisterElement(&rand_update_air);

		dir_air.setup(XOR("Direction"), XOR("dir_air"), { XOR("Auto"), XOR("Backwards"), XOR("Left"), XOR("Right"), XOR("Custom") });
		dir_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		dir_air.AddShowCallback(callbacks::AirHasYaw);
		RegisterElement(&dir_air);

		dir_time_air.setup("", XOR("dir_time_air"), 0.f, 10.f, false, 0, 0.f, 1.f, XOR(L"s"));
		dir_time_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		dir_time_air.AddShowCallback(callbacks::AirHasYaw);
		dir_time_air.AddShowCallback(callbacks::IsAirDirAuto);
		RegisterElement(&dir_time_air);

		dir_custom_air.setup("", XOR("dir_custom_air"), -180.f, 180.f, false, 0, 0.f, 5.f, XOR(L"�"));
		dir_custom_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		dir_custom_air.AddShowCallback(callbacks::AirHasYaw);
		dir_custom_air.AddShowCallback(callbacks::IsAirDirCustom);
		RegisterElement(&dir_custom_air);

		base_angle_air.setup(XOR("Base angle"), XOR("base_angle_air"), { XOR("Off"), XOR("Static"), XOR("Away crosshair"), XOR("Away distance") });
		base_angle_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		base_angle_air.AddShowCallback(callbacks::AirHasYaw);
		RegisterElement(&base_angle_air);

		body_fake_air.setup(XOR("Fake body"), XOR("body_fake_air"), { XOR("off"), XOR("left"), XOR("right"), XOR("opposite"), XOR("random") });
		body_fake_air.AddShowCallback(callbacks::IsAntiAimModeAir);
		body_fake_air.AddShowCallback(callbacks::AirHasYaw);
		RegisterElement(&body_fake_air);


		// col2.
		fake_yaw.setup(XOR("Fake yaw"), XOR("fake_yaw"), { XOR("off"), XOR("default"), XOR("relative"), XOR("jitter"), XOR("rotate"), XOR("random"), XOR("spin"), XOR("breaker 90"), XOR("break") });
		RegisterElement(&fake_yaw, 1);

		fake_relative.setup("", XOR("fake_relative"), -90.f, 90.f, false, 0, 0.f, 5.f, XOR(L"�"));
		fake_relative.AddShowCallback(callbacks::IsFakeAntiAimRelative);
		RegisterElement(&fake_relative, 1);

		fake_jitter_range.setup("", XOR("fake_jitter_range"), 1.f, 90.f, false, 0, 0.f, 5.f, XOR(L"�"));
		fake_jitter_range.AddShowCallback(callbacks::IsFakeAntiAimJitter);
		RegisterElement(&fake_jitter_range, 1);

		// col 2.
		lag_enable.setup(XOR("Fake-lag"), XOR("lag_enable"));
		RegisterElement(&lag_enable, 1);

		lag_active.setup("", XOR("lag_active"), { XOR("stand"), XOR("move"), XOR("air"), XOR("crouch"), XOR("lby flick"), XOR("reloading"), XOR("velocity change"), XOR("weapon switch"), XOR("always") }, false);
		RegisterElement(&lag_active, 1);

		lag_mode.setup("", XOR("lag_mode"), { XOR("max"), XOR("break"), XOR("random"), XOR("break step") }, false);
		RegisterElement(&lag_mode, 1);

		lag_limit.setup(XOR("Limit"), XOR("lag_limit"), 2, 17, true, 0, 2, 1.f);
		RegisterElement(&lag_limit, 1);

		disablefakelagonkey.setup(XOR("No Fake-Lag"), XOR("disable fake-lag on key"));
		RegisterElement(&disablefakelagonkey, 1);



		lag_land.setup(XOR("On land"), XOR("lag_land"));
		RegisterElement(&lag_land, 1);

		revoler_disable.setup(XOR("Disable fake-lag with revolver"), XOR("revolver_disable"));
		RegisterElement(&revoler_disable, 1);

		manul_antiaim.setup(XOR("Manual Arrows"), XOR("manul_antiaim"));
		RegisterElement(&manul_antiaim, 1);

		color_manul_antiaim.setup(XOR("Manual anti-aim color"), XOR("color_manul_antiaim"), colors::burgundy);
		RegisterElement(&color_manul_antiaim, 1);

		draw_angles.setup(XOR("Draw angles"), XOR("draw_angles"));
		RegisterElement(&draw_angles, 1);

		draw_angles_chams.setup(XOR("Draw fake chams"), XOR("draw_angles_chams"));
		RegisterElement(&draw_angles_chams, 1);

		color_draw_angles_chams.setup(XOR("Fake chams color"), XOR("color_draw_angles_chams"), colors::purple);
		RegisterElement(&color_draw_angles_chams, 1);

		draw_angles_chams_blend.setup("", XOR("draw_angles_chams_blend"), 10.f, 100.f, false, 0, 50.f, 1.f, XOR(L"%"));
		RegisterElement(&draw_angles_chams_blend, 1);

		left.setup(XOR("Left"), XOR("left"));
		left.SetToggleCallback(callbacks::ToggleLeft);
		RegisterElement(&left, 1);

		right.setup(XOR("Right"), XOR("right"));
		right.SetToggleCallback(callbacks::ToggleRight);
		RegisterElement(&right, 1);

		backward.setup(XOR("Backward"), XOR("backward"));
		backward.SetToggleCallback(callbacks::ToggleBack);
		RegisterElement(&backward, 1);

	}
};

class PlayersTab : public Tab {
public:
	MultiDropdown box;
	Colorpicker   box_enemy;
	Colorpicker   box_friendly;
	Checkbox      dormant;
	Checkbox      offscreen;
	Colorpicker   offscreen_color;
	MultiDropdown name;
	Colorpicker   name_color;
	MultiDropdown health;
	MultiDropdown flags_enemy;
	MultiDropdown flags_friendly;
	MultiDropdown weapon;
	MultiDropdown weapon_mode;
	Checkbox      ammo;
	Checkbox      distance;
	Colorpicker   ammo_color;
	Checkbox      lby_update;
	Colorpicker   lby_update_color;

	// col2.
	MultiDropdown skeleton;
	Colorpicker   skeleton_enemy;
	Colorpicker   skeleton_friendly;


	// col2.
	Dropdown      chamstype;
	// chams general.
	Dropdown      chams_selection;

	// chams enemy.
	Checkbox      chams_enemy_enable;
	MultiDropdown chams_enemy;
	Dropdown      chams_enemy_mat;
	Colorpicker   chams_enemy_vis;
	Colorpicker   chams_enemy_invis;
	Checkbox      chams_enemy_wireframe;
	Slider        chams_enemy_blend;

	// chams history.
	Checkbox      chams_enemy_history_enable;
	Dropdown      chams_enemy_history_mat;
	Colorpicker   chams_enemy_history_col;
	Checkbox      chams_enemy_history_wireframe;
	Slider        chams_enemy_history_blend;

	// chams friendly.
	Checkbox      chams_friendly_enable;
	MultiDropdown chams_friendly;
	Dropdown      chams_friendly_mat;
	Colorpicker   chams_friendly_vis;
	Colorpicker   chams_friendly_invis;
	Checkbox      chams_friendly_wireframe;
	Slider        chams_friendly_blend;

	// chams local.
	Checkbox      chams_local_enable;
	Dropdown      chams_local_mat;
	Colorpicker   chams_local_col;
	Checkbox      chams_local_wireframe;
	Slider        chams_local_blend;
	Checkbox      chams_local_scope;
	
	MultiDropdown glow;
	Colorpicker   glow_enemy;
	Colorpicker   glow_friendly;
	Slider        glow_blend;
	Checkbox	  chams_local_draw_angles;
	Checkbox	  chams_local_draw_angles_chams;
	

public:
	void init() {
		SetTitle(XOR("Visuals"));

		box.setup(XOR("Boxes"), XOR("Box"), { XOR("Enemy"), XOR("Friendly") });
		RegisterElement(&box);

		box_enemy.setup(XOR("Box enemy color"), XOR("box_enemy"), colors::white);
		RegisterElement(&box_enemy);

		box_friendly.setup(XOR("Box friendly color"), XOR("Box_friendly"), colors::white);
		RegisterElement(&box_friendly);

		dormant.setup(XOR("Dormant enemies"), XOR("dormant"));
		RegisterElement(&dormant);

		offscreen.setup(XOR("Enemy offscreen esp"), XOR("offscreen"));
		RegisterElement(&offscreen);

		offscreen_color.setup(XOR("Offscreen esp color"), XOR("offscreen_color"), colors::white);
		RegisterElement(&offscreen_color);

		name.setup(XOR("Name"), XOR("Name"), { XOR("Enemy"), XOR("Friendly") });
		RegisterElement(&name);

		name_color.setup(XOR("Name color"), XOR("name_color"), colors::white);
		RegisterElement(&name_color);

		health.setup(XOR("Health"), XOR("health"), { XOR("Enemy"), XOR("Friendly") });
		RegisterElement(&health);

		flags_enemy.setup(XOR("Flags enemy"), XOR("flags_enemy"), { XOR("Money"), XOR("Armor"), XOR("Scoped"), XOR("Flashed"), XOR("Reloading"), XOR("Bomb"), XOR("Fake") });
		RegisterElement(&flags_enemy);

		flags_friendly.setup(XOR("Flags friendly"), XOR("Flags_friendly"), { XOR("Money"), XOR("Armor"), XOR("Scoped"), XOR("Flashed"), XOR("Reloading"), XOR("Bomb") });
		RegisterElement(&flags_friendly);

		weapon.setup(XOR("Weapon"), XOR("Weapon"), { XOR("Enemy"), XOR("Friendly") });
		RegisterElement(&weapon);

		weapon_mode.setup("", XOR("weapon_mode"), { XOR("Text"), XOR("Icon") }, false);
		RegisterElement(&weapon_mode);

		distance.setup(XOR("Distance"), XOR("distance"));
		RegisterElement(&distance);

		ammo.setup(XOR("Ammo"), XOR("ammo"));
		RegisterElement(&ammo);

		ammo_color.setup(XOR("Color"), XOR("ammo_color"), colors::light_blue);
		RegisterElement(&ammo_color);

		lby_update.setup(XOR("Lby update"), XOR("lby_update"));
		RegisterElement(&lby_update);

		lby_update_color.setup(XOR("Color"), XOR("lby_update_color"), colors::purple);
		RegisterElement(&lby_update_color);

		// col2.
		skeleton.setup(XOR("Skeleton"), XOR("skeleton"), { XOR("Enemy"), XOR("Friendly") });
		RegisterElement(&skeleton, 1);

		skeleton_enemy.setup(XOR("Enemy color"), XOR("skeleton_enemy"), { 255, 255, 255 });
		RegisterElement(&skeleton_enemy, 1);

		skeleton_friendly.setup(XOR("Friendly color"), XOR("skeleton_friendly"), { 255, 255, 255 });
		RegisterElement(&skeleton_friendly, 1);

	
		glow.setup(XOR("Glow"), XOR("glow"), { XOR("Enemy"), XOR("Friendly") });
		RegisterElement(&glow, 1);

		glow_enemy.setup(XOR("Enemy color"), XOR("glow_enemy"), { 180, 60, 120 });
		RegisterElement(&glow_enemy, 1);

		glow_friendly.setup(XOR("Friendly color"), XOR("glow_friendly"), { 150, 200, 60 });
		RegisterElement(&glow_friendly, 1);

		glow_blend.setup("", XOR("glow_blend"), 10.f, 100.f, false, 0, 60.f, 1.f, XOR(L"%"));
		RegisterElement(&glow_blend, 1);

		// chams selection.
		chams_selection.setup(XOR("Cham options"), XOR("chams_selection"), { XOR("enemy"), XOR("friendly"), XOR("local")});
		RegisterElement(&chams_selection, 1);

		// enemy chams.
		chams_enemy_enable.setup(XOR("Enable"), XOR("chams_enemy_enable"));
		chams_enemy_enable.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy_enable, 1);

		chams_enemy.setup(XOR("Enemy chams"), XOR("chams_enemy"), { XOR("visible"), XOR("invisible") });
		chams_enemy.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy, 1);

		chams_enemy_mat.setup(XOR("Enemy chams material"), XOR("chams_enemy_mat"), { XOR("default"), XOR("flat"), XOR("metallic"), XOR("outline"), XOR("ghost") });
		chams_enemy_mat.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy_mat, 1);

		chams_enemy_vis.setup(XOR("Color visible"), XOR("chams_enemy_vis"), { 150, 200, 60 });
		chams_enemy_vis.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy_vis, 1);

		chams_enemy_invis.setup(XOR("Color invisible"), XOR("chams_enemy_invis"), { 60, 180, 225 });
		chams_enemy_invis.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy_invis, 1);

		chams_enemy_wireframe.setup(XOR("Wireframe"), XOR("chams_enemy_wireframe"));
		chams_enemy_wireframe.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy_wireframe, 1);

		chams_enemy_blend.setup("", XOR("chams_enemy_blend"), 10.f, 100.f, false, 0, 100.f, 1.f, XOR(L"%"));
		chams_enemy_blend.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy_blend, 1);

		// history chams.
		chams_enemy_history_enable.setup(XOR("Enable backtrack chams"), XOR("chams_enemy_history_enable"));
		chams_enemy_history_enable.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy_history_enable, 1);

		chams_enemy_history_mat.setup(XOR("Backtrack chams material"), XOR("chams_enemy_history_mat"), { XOR("default"), XOR("flat"), XOR("metallic"), XOR("outline"), XOR("ghost") });
		chams_enemy_history_mat.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy_history_mat, 1);

		chams_enemy_history_col.setup(XOR("Color"), XOR("chams_history_col"), { 255, 255, 200 });
		chams_enemy_history_col.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy_history_col, 1);



		chams_enemy_history_blend.setup("", XOR("chams_history_blend"), 10.f, 100.f, false, 0, 100.f, 1.f, XOR(L"%"));
		chams_enemy_history_blend.AddShowCallback(callbacks::IsEnemyChams);
		RegisterElement(&chams_enemy_history_blend, 1);

		// friendly chams.
		chams_friendly_enable.setup(XOR("Enable"), XOR("chams_friendly_enable"));
		chams_friendly_enable.AddShowCallback(callbacks::IsFriendlyChams);
		RegisterElement(&chams_friendly_enable, 1);

		chams_friendly.setup(XOR("Teammate chams"), XOR("chams_friendly"), { XOR("visible"), XOR("invisible") });
		chams_friendly.AddShowCallback(callbacks::IsFriendlyChams);
		RegisterElement(&chams_friendly, 1);

		chams_friendly_mat.setup(XOR("Teammate chams material"), XOR("chams_friendly_mat"), { XOR("default"), XOR("flat"), XOR("metallic"), XOR("outline"), XOR("ghost") });
		chams_friendly_mat.AddShowCallback(callbacks::IsFriendlyChams);
		RegisterElement(&chams_friendly_mat, 1);

		chams_friendly_vis.setup(XOR("Color visible"), XOR("chams_friendly_vis"), { 255, 200, 0 });
		chams_friendly_vis.AddShowCallback(callbacks::IsFriendlyChams);
		RegisterElement(&chams_friendly_vis, 1);

		chams_friendly_invis.setup(XOR("Color invisible"), XOR("chams_friendly_invis"), { 255, 50, 0 });
		chams_friendly_invis.AddShowCallback(callbacks::IsFriendlyChams);
		RegisterElement(&chams_friendly_invis, 1);

		chams_friendly_wireframe.setup(XOR("Wireframe"), XOR("chams_friendly_wireframe"));
		chams_friendly_wireframe.AddShowCallback(callbacks::IsFriendlyChams);
		RegisterElement(&chams_friendly_wireframe, 1);

		chams_friendly_blend.setup("", XOR("chams_friendly_blend"), 10.f, 100.f, false, 0, 100.f, 1.f, XOR(L"%"));
		chams_friendly_blend.AddShowCallback(callbacks::IsFriendlyChams);
		RegisterElement(&chams_friendly_blend, 1);

		// local chams.
		chams_local_enable.setup(XOR("Enable"), XOR("chams_local_enable"));
		chams_local_enable.AddShowCallback(callbacks::IsLocalChams);
		RegisterElement(&chams_local_enable, 1);

		chams_local_mat.setup(XOR("Local chams material"), XOR("chams_local_mat"), { XOR("Default"), XOR("Flat"), XOR("Metallic"), XOR("Outline"), XOR("Ghost") });
		chams_local_mat.AddShowCallback(callbacks::IsLocalChams);
		RegisterElement(&chams_local_mat, 1);

		chams_local_col.setup(XOR("Color"), XOR("chams_local_col"), { 255, 255, 200 });
		chams_local_col.AddShowCallback(callbacks::IsLocalChams);
		RegisterElement(&chams_local_col, 1);

		chams_local_blend.setup("", XOR("chams_local_blend"), 10.f, 100.f, false, 0, 100.f, 1.f, XOR(L"%"));
		chams_local_blend.AddShowCallback(callbacks::IsLocalChams);
		RegisterElement(&chams_local_blend, 1);

		chams_local_wireframe.setup(XOR("Wireframe"), XOR("chams_local_wireframe"));
		chams_local_wireframe.AddShowCallback(callbacks::IsLocalChams);
		RegisterElement(&chams_local_wireframe, 1);

		chams_local_scope.setup(XOR("Transparent scope"), XOR("chams_local_scope"));
		chams_local_scope.AddShowCallback(callbacks::IsLocalChams);
		RegisterElement(&chams_local_scope, 1);

		chams_local_draw_angles.setup(XOR("chams"), XOR("chams_local_draw_angles"));
		chams_local_draw_angles.AddShowCallback(callbacks::IsFakeChams);
		RegisterElement(&chams_local_draw_angles, 1);

	

	
	}
};

class VisualsTab : public Tab {
public:
	Checkbox      distance;
	Checkbox      items;
	Colorpicker   item_color;
	Checkbox      ammo;
	Colorpicker   dropammo_color;
	Checkbox      proj;
	Colorpicker   proj_color;
	MultiDropdown proj_range;
	Colorpicker   proj_range_color;
	MultiDropdown planted_c4;
	Checkbox      disableteam;
	Dropdown	  world;
	Slider        night_darkness;
	Checkbox      transparent_props;
	Slider		  transparent_props_amount;
	Checkbox      enemy_radar;
	Dropdown      chamstype;

	Checkbox	FogOverride; // butt
	Colorpicker	FogColor; // color
	Slider		FogStart; // slider
	Slider		FogEnd; // slider
	Slider		Fogdensity; // slider
	//Colorpicker      glowcolor;

	Colorpicker      scope_color;
	Slider          scope_gap;
	Slider          scope_length;
	Checkbox      scope_invert;

	// col2.
	Checkbox      novisrecoil;
	Checkbox      nosmoke;
	Checkbox draw_damage;
	Checkbox      nofog;
	Checkbox      noflash;
	Checkbox      noscope;
	Checkbox      fov;
	Slider        fov_amt;
	Checkbox      fov_scoped;
	Checkbox      viewmodel_fov;
	Slider        viewmodel_fov_amt;
	Checkbox      spectators;
	Checkbox      force_xhair;
	Checkbox      spread_xhair;
	Colorpicker   spread_xhair_col;
	Slider        spread_xhair_blend;
	Checkbox      pen_crosshair;
	Checkbox      pen_damage;
	MultiDropdown indicators;
	Checkbox      tracers;
	Checkbox      impact_beams;
	Colorpicker   impact_beams_color;
	Colorpicker   impact_beams_hurt_color;
	Slider        impact_beams_time;
	Keybind       thirdperson;
	Slider		  thirdperson_distance;

public:
	void init() {
		SetTitle(XOR("Player Misc"));

		items.setup(XOR("Dropped weapons"), XOR("items"));
		RegisterElement(&items);

		distance.setup(XOR("Distance weapons"), XOR("distance"));
		RegisterElement(&distance);

		item_color.setup(XOR("Color"), XOR("item_color"), colors::white);
		RegisterElement(&item_color);

		ammo.setup(XOR("Dropped weapons ammo"), XOR("ammo"));
		RegisterElement(&ammo);

		dropammo_color.setup(XOR("Color"), XOR("dropammo_color"), colors::light_blue);
		RegisterElement(&dropammo_color);

		proj.setup(XOR("Projectiles"), XOR("proj"));
		RegisterElement(&proj);

		proj_color.setup(XOR("Color"), XOR("proj_color"), colors::white);
		RegisterElement(&proj_color);

		proj_range.setup(XOR("Projectile range"), XOR("proj_range"), { XOR("Molly"), XOR("Smoke") });
		RegisterElement(&proj_range);

		proj_range_color.setup(XOR("Color"), XOR("proj_range_color"), colors::burgundy);
		RegisterElement(&proj_range_color);

		planted_c4.setup(XOR("Planted c4"), XOR("planted_c4"), { XOR("On screen (2D)"), XOR("On bomb (3D)"), XOR("Bomb timer (2D)"), XOR("Bomb timer (3D)") });
		RegisterElement(&planted_c4);

		disableteam.setup(XOR("Do not render teammates"), XOR("disableteam"));
		RegisterElement(&disableteam);

		world.setup(XOR("World"), XOR("world"),  { XOR("Off"), XOR("Night "), XOR("Fullbright"),  });
		world.SetCallback(Visuals::ModulateWorld);
		RegisterElement(&world);

		night_darkness.setup("", XOR("night_darkness"), 0.f, 100.f, false, 0, 10.f, 1.f, XOR(L"%"));
		night_darkness.SetCallback(Visuals::ModulateWorld);
		night_darkness.AddShowCallback(callbacks::IsNightMode);
		RegisterElement(&night_darkness);

		

		transparent_props.setup(XOR("Transparent props"), XOR("transparent_props"));
		transparent_props.SetCallback(Visuals::ModulateWorld);
		RegisterElement(&transparent_props);

		transparent_props_amount.setup("", XOR("transparent_props_amount"), 0.f, 100.f, false, 0, 100.f, 1.f, XOR(L"%"));
		transparent_props_amount.SetCallback(Visuals::ModulateWorld);
		transparent_props_amount.AddShowCallback(callbacks::IsTransparentProps);
		RegisterElement(&transparent_props_amount);

		enemy_radar.setup(XOR("Force enemies on radar"), XOR("enemy_radar"));
		RegisterElement(&enemy_radar);




		//glowcolor.setup(XOR("glow chams color"), XOR("glowcolor"), colors::light_blue);
		//RegisterElement(&glowcolor, 1);

		// col2.
		novisrecoil.setup(XOR("Remove visual recoil"), XOR("novisrecoil"));
		RegisterElement(&novisrecoil, 1);

		nosmoke.setup(XOR("Remove smoke grenades"), XOR("nosmoke"));
		RegisterElement(&nosmoke, 1);

		nofog.setup(XOR("Remove fog"), XOR("nofog"));
		RegisterElement(&nofog, 1);

		noflash.setup(XOR("Remove flashbangs"), XOR("noflash"));
		RegisterElement(&noflash, 1);

		noscope.setup(XOR("Remove scope"), XOR("noscope"));
		RegisterElement(&noscope, 1);

		fov.setup(XOR("Override fov"), XOR("fov"));
		RegisterElement(&fov, 1);

		fov_amt.setup("", XOR("fov_amt"), 60.f, 140.f, false, 0, 90.f, 1.f, XOR(L"�"));
		RegisterElement(&fov_amt, 1);

		fov_scoped.setup(XOR("Override fov when scoped"), XOR("fov_scoped"));
		RegisterElement(&fov_scoped, 1);

		viewmodel_fov.setup(XOR("Override viewmodel fov"), XOR("viewmodel_fov"));
		RegisterElement(&viewmodel_fov, 1);

		viewmodel_fov_amt.setup("", XOR("viewmodel_fov_amt"), 60.f, 140.f, false, 0, 90.f, 1.f, XOR(L"�"));
		RegisterElement(&viewmodel_fov_amt, 1);

		spectators.setup(XOR("Spectator list"), XOR("spectators"));
		RegisterElement(&spectators, 1);

		force_xhair.setup(XOR("Force crosshair"), XOR("force_xhair"));
		RegisterElement(&force_xhair, 1);

		spread_xhair.setup(XOR("Visualize spread"), XOR("spread_xhair"));
		RegisterElement(&spread_xhair, 1);

		spread_xhair_col.setup(XOR("Visualize spread color"), XOR("spread_xhair_col"), colors::burgundy);
		RegisterElement(&spread_xhair_col, 1);

		spread_xhair_blend.setup("", XOR("spread_xhair_blend"), 10.f, 100.f, false, 0, 100.f, 1.f, XOR(L"%"));
		RegisterElement(&spread_xhair_blend, 1);

		pen_crosshair.setup(XOR("Penetration crosshair"), XOR("pen_xhair"));
		RegisterElement(&pen_crosshair, 1);

		pen_damage.setup(XOR("Penetration damage"), XOR("pen_damage"));
		RegisterElement(&pen_damage, 1);

		indicators.setup(XOR("Indicators"), XOR("indicators"), { XOR("Lby"), XOR("Lag compensation"), XOR("Ping"), XOR("Doubletap"), XOR("Bomb")});
		RegisterElement(&indicators, 1);

		tracers.setup(XOR("Grenade simulation"), XOR("tracers"));
		RegisterElement(&tracers, 1);

		draw_damage.setup(XOR("Draw damage"), XOR("draw_damage_damage"));
		RegisterElement(&draw_damage, 1);

		impact_beams.setup(XOR("Impact beams"), XOR("impact_beams"));
		RegisterElement(&impact_beams, 1);

		impact_beams_color.setup(XOR("Color"), XOR("impact_beams_color"), colors::light_blue);
		RegisterElement(&impact_beams_color, 1);

		impact_beams_hurt_color.setup(XOR("Hit color"), XOR("impact_beams_hurt_color"), colors::red);
		RegisterElement(&impact_beams_hurt_color, 1);

		impact_beams_time.setup(XOR("Impact beams thickness"), XOR("impact_beams_time"), 1.f, 10.f, true, 0, 1.f, 1.f, XOR(L""));
		RegisterElement(&impact_beams_time, 1);

		thirdperson.setup(XOR("Thirdperson"), XOR("thirdperson"));
		thirdperson.SetToggleCallback(callbacks::ToggleThirdPerson);
		RegisterElement(&thirdperson, 1);

		thirdperson_distance.setup(XOR(" "), XOR("thirdperson_distance"), 50.f, 300.f, false, 0, 150.f, 1.f, XOR(L"�"));
		RegisterElement(&thirdperson_distance, 1);
	}
};

class MovementTab : public Tab {
public:
	Checkbox bhop;
	Checkbox airduck;
	Checkbox autostrafe;
	Keybind  cstrafe;
	Keybind  astrafe;
	Keybind  zstrafe;
	Slider   z_freq;
	Slider   z_dist;

	Keybind  fakewalk;
	Slider   fakewalkspeed;
	Keybind  autopeek;
	Keybind  autostop;
	Checkbox autostop_always_on;
	Keybind       cripwalk;
	//Checkbox auto_stop_between_shots;

public:
	void init() {
		SetTitle(XOR("Movement"));

		bhop.setup(XOR("Automatic jump"), XOR("bhop"));
		RegisterElement(&bhop);

	

		autostrafe.setup(XOR("Automatic strafe"), XOR("autostrafe"));
		RegisterElement(&autostrafe);

		cstrafe.setup(XOR("C-strafe"), XOR("cstrafe"));
		RegisterElement(&cstrafe);

		astrafe.setup(XOR("A-strafe"), XOR("astrafe"));
		RegisterElement(&astrafe);

		zstrafe.setup(XOR("Z-strafe"), XOR("zstrafe"));
		RegisterElement(&zstrafe);

		z_freq.setup("", XOR("z_freq"), 1.f, 100.f, false, 0, 50.f, 0.5f, XOR(L"hz"));
		RegisterElement(&z_freq);

		z_dist.setup("", XOR("z_dist"), 1.f, 100.f, false, 0, 20.f, 0.5f, XOR(L"%"));
		RegisterElement(&z_dist);

		fakewalk.setup(XOR("Fake-walk"), XOR("fakewalk"));
		RegisterElement(&fakewalk, 1);

		fakewalkspeed.setup(XOR("Fake-walk speed"), XOR("fakewalkspeed"), 8.f, 24.f, true, 0, 16.f, 1.f, XOR(L"t"));
		RegisterElement(&fakewalkspeed, 1);

		autopeek.setup(XOR("Automatic peek"), XOR("autopeek"));
		RegisterElement(&autopeek, 1);

		autostop_always_on.setup(XOR("Quick stop"), XOR("auto_stop_always"));
		RegisterElement(&autostop_always_on, 1);

		autostop.setup(XOR("Quick stop"), XOR("autostop"));
		autostop.AddShowCallback(callbacks::AUTO_STOP);
		RegisterElement(&autostop, 1);


		cripwalk.setup(XOR("Autismwalk"), XOR("cripwalk"));
		RegisterElement(&cripwalk, 1);
	}
};

class SkinsTab : public Tab {
public:
	Checkbox enable;

	Edit     id_deagle;
	Checkbox stattrak_deagle;
	Slider   quality_deagle;
	Slider	 seed_deagle;

	Edit     id_elite;
	Checkbox stattrak_elite;
	Slider   quality_elite;
	Slider	 seed_elite;

	Edit     id_fiveseven;
	Checkbox stattrak_fiveseven;
	Slider   quality_fiveseven;
	Slider	 seed_fiveseven;

	Edit     id_glock;
	Checkbox stattrak_glock;
	Slider   quality_glock;
	Slider	 seed_glock;

	Edit     id_ak47;
	Checkbox stattrak_ak47;
	Slider   quality_ak47;
	Slider	 seed_ak47;

	Edit     id_aug;
	Checkbox stattrak_aug;
	Slider   quality_aug;
	Slider	 seed_aug;

	Edit     id_awp;
	Checkbox stattrak_awp;
	Slider   quality_awp;
	Slider	 seed_awp;

	Edit     id_famas;
	Checkbox stattrak_famas;
	Slider   quality_famas;
	Slider	 seed_famas;

	Edit     id_g3sg1;
	Checkbox stattrak_g3sg1;
	Slider   quality_g3sg1;
	Slider	 seed_g3sg1;

	Edit     id_galil;
	Checkbox stattrak_galil;
	Slider   quality_galil;
	Slider	 seed_galil;

	Edit     id_m249;
	Checkbox stattrak_m249;
	Slider   quality_m249;
	Slider	 seed_m249;

	Edit     id_m4a4;
	Checkbox stattrak_m4a4;
	Slider   quality_m4a4;
	Slider	 seed_m4a4;

	Edit     id_mac10;
	Checkbox stattrak_mac10;
	Slider   quality_mac10;
	Slider	 seed_mac10;

	Edit     id_p90;
	Checkbox stattrak_p90;
	Slider   quality_p90;
	Slider	 seed_p90;

	Edit     id_ump45;
	Checkbox stattrak_ump45;
	Slider   quality_ump45;
	Slider	 seed_ump45;

	Edit     id_xm1014;
	Checkbox stattrak_xm1014;
	Slider   quality_xm1014;
	Slider	 seed_xm1014;

	Edit     id_bizon;
	Checkbox stattrak_bizon;
	Slider   quality_bizon;
	Slider	 seed_bizon;

	Edit     id_mag7;
	Checkbox stattrak_mag7;
	Slider   quality_mag7;
	Slider	 seed_mag7;

	Edit     id_negev;
	Checkbox stattrak_negev;
	Slider   quality_negev;
	Slider	 seed_negev;

	Edit     id_sawedoff;
	Checkbox stattrak_sawedoff;
	Slider   quality_sawedoff;
	Slider	 seed_sawedoff;

	Edit     id_tec9;
	Checkbox stattrak_tec9;
	Slider   quality_tec9;
	Slider	 seed_tec9;

	Edit     id_p2000;
	Checkbox stattrak_p2000;
	Slider   quality_p2000;
	Slider	 seed_p2000;

	Edit     id_mp7;
	Checkbox stattrak_mp7;
	Slider   quality_mp7;
	Slider	 seed_mp7;

	Edit     id_mp9;
	Checkbox stattrak_mp9;
	Slider   quality_mp9;
	Slider	 seed_mp9;

	Edit     id_nova;
	Checkbox stattrak_nova;
	Slider   quality_nova;
	Slider	 seed_nova;

	Edit     id_p250;
	Checkbox stattrak_p250;
	Slider   quality_p250;
	Slider	 seed_p250;

	Edit     id_scar20;
	Checkbox stattrak_scar20;
	Slider   quality_scar20;
	Slider	 seed_scar20;

	Edit     id_sg553;
	Checkbox stattrak_sg553;
	Slider   quality_sg553;
	Slider	 seed_sg553;

	Edit     id_ssg08;
	Checkbox stattrak_ssg08;
	Slider   quality_ssg08;
	Slider	 seed_ssg08;

	Edit     id_m4a1s;
	Checkbox stattrak_m4a1s;
	Slider   quality_m4a1s;
	Slider	 seed_m4a1s;

	Edit     id_usps;
	Checkbox stattrak_usps;
	Slider   quality_usps;
	Slider	 seed_usps;

	Edit     id_cz75a;
	Checkbox stattrak_cz75a;
	Slider   quality_cz75a;
	Slider	 seed_cz75a;

	Edit     id_revolver;
	Checkbox stattrak_revolver;
	Slider   quality_revolver;
	Slider	 seed_revolver;

	Edit     id_bayonet;
	Checkbox stattrak_bayonet;
	Slider   quality_bayonet;
	Slider	 seed_bayonet;

	Edit     id_flip;
	Checkbox stattrak_flip;
	Slider   quality_flip;
	Slider	 seed_flip;

	Edit     id_gut;
	Checkbox stattrak_gut;
	Slider   quality_gut;
	Slider	 seed_gut;

	Edit     id_karambit;
	Checkbox stattrak_karambit;
	Slider   quality_karambit;
	Slider	 seed_karambit;

	Edit     id_m9;
	Checkbox stattrak_m9;
	Slider   quality_m9;
	Slider	 seed_m9;

	Edit     id_huntsman;
	Checkbox stattrak_huntsman;
	Slider   quality_huntsman;
	Slider	 seed_huntsman;

	Edit     id_falchion;
	Checkbox stattrak_falchion;
	Slider   quality_falchion;
	Slider	 seed_falchion;

	Edit     id_bowie;
	Checkbox stattrak_bowie;
	Slider   quality_bowie;
	Slider	 seed_bowie;

	Edit     id_butterfly;
	Checkbox stattrak_butterfly;
	Slider   quality_butterfly;
	Slider	 seed_butterfly;

	Edit     id_daggers;
	Checkbox stattrak_daggers;
	Slider   quality_daggers;
	Slider	 seed_daggers;

	// col 2.
	Dropdown knife;
	Dropdown glove;
	Edit	 glove_id;

public:
	void init() {
		SetTitle(XOR("Skin changer"));

		enable.setup(XOR("Enable"), XOR("skins_enable"));
		enable.SetCallback(callbacks::ForceFullUpdate);
		RegisterElement(&enable);

		// weapons...
		id_deagle.setup(XOR("Paintkit id"), XOR("id_deagle"), 3);
		id_deagle.SetCallback(callbacks::SkinUpdate);
		id_deagle.AddShowCallback(callbacks::DEAGLE);
		RegisterElement(&id_deagle);

		stattrak_deagle.setup(XOR("stattrak"), XOR("stattrak_deagle"));
		stattrak_deagle.SetCallback(callbacks::SkinUpdate);
		stattrak_deagle.AddShowCallback(callbacks::DEAGLE);
		RegisterElement(&stattrak_deagle);

		quality_deagle.setup(XOR("quality"), XOR("quality_deagle"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_deagle.SetCallback(callbacks::SkinUpdate);
		quality_deagle.AddShowCallback(callbacks::DEAGLE);
		RegisterElement(&quality_deagle);

		seed_deagle.setup(XOR("seed"), XOR("seed_deagle"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_deagle.SetCallback(callbacks::SkinUpdate);
		seed_deagle.AddShowCallback(callbacks::DEAGLE);
		RegisterElement(&seed_deagle);

		id_elite.setup(XOR("paintkit id"), XOR("id_elite"), 3);
		id_elite.SetCallback(callbacks::SkinUpdate);
		id_elite.AddShowCallback(callbacks::ELITE);
		RegisterElement(&id_elite);

		stattrak_elite.setup(XOR("stattrak"), XOR("stattrak_elite"));
		stattrak_elite.SetCallback(callbacks::SkinUpdate);
		stattrak_elite.AddShowCallback(callbacks::ELITE);
		RegisterElement(&stattrak_elite);

		quality_elite.setup(XOR("quality"), XOR("quality_elite"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_elite.SetCallback(callbacks::SkinUpdate);
		quality_elite.AddShowCallback(callbacks::ELITE);
		RegisterElement(&quality_elite);

		seed_elite.setup(XOR("seed"), XOR("seed_elite"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_elite.SetCallback(callbacks::SkinUpdate);
		seed_elite.AddShowCallback(callbacks::ELITE);
		RegisterElement(&seed_elite);

		id_fiveseven.setup(XOR("paintkit id"), XOR("id_fiveseven"), 3);
		id_fiveseven.SetCallback(callbacks::SkinUpdate);
		id_fiveseven.AddShowCallback(callbacks::FIVESEVEN);
		RegisterElement(&id_fiveseven);

		stattrak_fiveseven.setup(XOR("stattrak"), XOR("stattrak_fiveseven"));
		stattrak_fiveseven.SetCallback(callbacks::SkinUpdate);
		stattrak_fiveseven.AddShowCallback(callbacks::FIVESEVEN);
		RegisterElement(&stattrak_fiveseven);

		quality_fiveseven.setup(XOR("quality"), XOR("quality_fiveseven"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_fiveseven.SetCallback(callbacks::SkinUpdate);
		quality_fiveseven.AddShowCallback(callbacks::FIVESEVEN);
		RegisterElement(&quality_fiveseven);

		seed_fiveseven.setup(XOR("seed"), XOR("seed_fiveseven"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_fiveseven.SetCallback(callbacks::SkinUpdate);
		seed_fiveseven.AddShowCallback(callbacks::FIVESEVEN);
		RegisterElement(&seed_fiveseven);

		id_glock.setup(XOR("paintkit id"), XOR("id_glock"), 3);
		id_glock.SetCallback(callbacks::SkinUpdate);
		id_glock.AddShowCallback(callbacks::GLOCK);
		RegisterElement(&id_glock);

		stattrak_glock.setup(XOR("stattrak"), XOR("stattrak_glock"));
		stattrak_glock.SetCallback(callbacks::SkinUpdate);
		stattrak_glock.AddShowCallback(callbacks::GLOCK);
		RegisterElement(&stattrak_glock);

		quality_glock.setup(XOR("quality"), XOR("quality_glock"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_glock.SetCallback(callbacks::SkinUpdate);
		quality_glock.AddShowCallback(callbacks::GLOCK);
		RegisterElement(&quality_glock);

		seed_glock.setup(XOR("seed"), XOR("seed_glock"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_glock.SetCallback(callbacks::SkinUpdate);
		seed_glock.AddShowCallback(callbacks::GLOCK);
		RegisterElement(&seed_glock);

		id_ak47.setup(XOR("paintkit id"), XOR("id_ak47"), 3);
		id_ak47.SetCallback(callbacks::SkinUpdate);
		id_ak47.AddShowCallback(callbacks::AK47);
		RegisterElement(&id_ak47);

		stattrak_ak47.setup(XOR("stattrak"), XOR("stattrak_ak47"));
		stattrak_ak47.SetCallback(callbacks::SkinUpdate);
		stattrak_ak47.AddShowCallback(callbacks::AK47);
		RegisterElement(&stattrak_ak47);

		quality_ak47.setup(XOR("quality"), XOR("quality_ak47"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_ak47.SetCallback(callbacks::SkinUpdate);
		quality_ak47.AddShowCallback(callbacks::AK47);
		RegisterElement(&quality_ak47);

		seed_ak47.setup(XOR("seed"), XOR("seed_ak47"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_ak47.SetCallback(callbacks::SkinUpdate);
		seed_ak47.AddShowCallback(callbacks::AK47);
		RegisterElement(&seed_ak47);

		id_aug.setup(XOR("paintkit id"), XOR("id_aug"), 3);
		id_aug.SetCallback(callbacks::SkinUpdate);
		id_aug.AddShowCallback(callbacks::AUG);
		RegisterElement(&id_aug);

		stattrak_aug.setup(XOR("stattrak"), XOR("stattrak_aug"));
		stattrak_aug.SetCallback(callbacks::SkinUpdate);
		stattrak_aug.AddShowCallback(callbacks::AUG);
		RegisterElement(&stattrak_aug);

		quality_aug.setup(XOR("quality"), XOR("quality_aug"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_aug.SetCallback(callbacks::SkinUpdate);
		quality_aug.AddShowCallback(callbacks::AUG);
		RegisterElement(&quality_aug);

		seed_aug.setup(XOR("seed"), XOR("seed_aug"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_aug.SetCallback(callbacks::SkinUpdate);
		seed_aug.AddShowCallback(callbacks::AUG);
		RegisterElement(&seed_aug);

		id_awp.setup(XOR("paintkit id"), XOR("id_awp"), 3);
		id_awp.SetCallback(callbacks::SkinUpdate);
		id_awp.AddShowCallback(callbacks::AWP);
		RegisterElement(&id_awp);

		stattrak_awp.setup(XOR("stattrak"), XOR("stattrak_awp"));
		stattrak_awp.SetCallback(callbacks::SkinUpdate);
		stattrak_awp.AddShowCallback(callbacks::AWP);
		RegisterElement(&stattrak_awp);

		quality_awp.setup(XOR("quality"), XOR("quality_awp"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_awp.SetCallback(callbacks::SkinUpdate);
		quality_awp.AddShowCallback(callbacks::AWP);
		RegisterElement(&quality_awp);

		seed_awp.setup(XOR("seed"), XOR("seed_awp"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_awp.SetCallback(callbacks::SkinUpdate);
		seed_awp.AddShowCallback(callbacks::AWP);
		RegisterElement(&seed_awp);

		id_famas.setup(XOR("paintkit id"), XOR("id_famas"), 3);
		id_famas.SetCallback(callbacks::SkinUpdate);
		id_famas.AddShowCallback(callbacks::FAMAS);
		RegisterElement(&id_famas);

		stattrak_famas.setup(XOR("stattrak"), XOR("stattrak_famas"));
		stattrak_famas.SetCallback(callbacks::SkinUpdate);
		stattrak_famas.AddShowCallback(callbacks::FAMAS);
		RegisterElement(&stattrak_famas);

		quality_famas.setup(XOR("quality"), XOR("quality_famas"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_famas.SetCallback(callbacks::SkinUpdate);
		quality_famas.AddShowCallback(callbacks::FAMAS);
		RegisterElement(&quality_famas);

		seed_famas.setup(XOR("seed"), XOR("seed_famas"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_famas.SetCallback(callbacks::SkinUpdate);
		seed_famas.AddShowCallback(callbacks::FAMAS);
		RegisterElement(&seed_famas);

		id_g3sg1.setup(XOR("paintkit id"), XOR("id_g3sg1"), 3);
		id_g3sg1.SetCallback(callbacks::SkinUpdate);
		id_g3sg1.AddShowCallback(callbacks::G3SG1);
		RegisterElement(&id_g3sg1);

		stattrak_g3sg1.setup(XOR("stattrak"), XOR("stattrak_g3sg1"));
		stattrak_g3sg1.SetCallback(callbacks::SkinUpdate);
		stattrak_g3sg1.AddShowCallback(callbacks::G3SG1);
		RegisterElement(&stattrak_g3sg1);

		quality_g3sg1.setup(XOR("quality"), XOR("quality_g3sg1"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_g3sg1.SetCallback(callbacks::SkinUpdate);
		quality_g3sg1.AddShowCallback(callbacks::G3SG1);
		RegisterElement(&quality_g3sg1);

		seed_g3sg1.setup(XOR("seed"), XOR("seed_g3sg1"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_g3sg1.SetCallback(callbacks::SkinUpdate);
		seed_g3sg1.AddShowCallback(callbacks::G3SG1);
		RegisterElement(&seed_g3sg1);

		id_galil.setup(XOR("paintkit id"), XOR("id_galil"), 3);
		id_galil.SetCallback(callbacks::SkinUpdate);
		id_galil.AddShowCallback(callbacks::GALIL);
		RegisterElement(&id_galil);

		stattrak_galil.setup(XOR("stattrak"), XOR("stattrak_galil"));
		stattrak_galil.SetCallback(callbacks::SkinUpdate);
		stattrak_galil.AddShowCallback(callbacks::GALIL);
		RegisterElement(&stattrak_galil);

		quality_galil.setup(XOR("quality"), XOR("quality_galil"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_galil.SetCallback(callbacks::SkinUpdate);
		quality_galil.AddShowCallback(callbacks::GALIL);
		RegisterElement(&quality_galil);

		seed_galil.setup(XOR("seed"), XOR("seed_galil"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_galil.SetCallback(callbacks::SkinUpdate);
		seed_galil.AddShowCallback(callbacks::GALIL);
		RegisterElement(&seed_galil);

		id_m249.setup(XOR("paintkit id"), XOR("id_m249"), 3);
		id_m249.SetCallback(callbacks::SkinUpdate);
		id_m249.AddShowCallback(callbacks::M249);
		RegisterElement(&id_m249);

		stattrak_m249.setup(XOR("stattrak"), XOR("stattrak_m249"));
		stattrak_m249.SetCallback(callbacks::SkinUpdate);
		stattrak_m249.AddShowCallback(callbacks::M249);
		RegisterElement(&stattrak_m249);

		quality_m249.setup(XOR("quality"), XOR("quality_m249"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_m249.SetCallback(callbacks::SkinUpdate);
		quality_m249.AddShowCallback(callbacks::M249);
		RegisterElement(&quality_m249);

		seed_m249.setup(XOR("seed"), XOR("seed_m249"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_m249.SetCallback(callbacks::SkinUpdate);
		seed_m249.AddShowCallback(callbacks::M249);
		RegisterElement(&seed_m249);

		id_m4a4.setup(XOR("paintkit id"), XOR("id_m4a4"), 3);
		id_m4a4.SetCallback(callbacks::SkinUpdate);
		id_m4a4.AddShowCallback(callbacks::M4A4);
		RegisterElement(&id_m4a4);

		stattrak_m4a4.setup(XOR("stattrak"), XOR("stattrak_m4a4"));
		stattrak_m4a4.SetCallback(callbacks::SkinUpdate);
		stattrak_m4a4.AddShowCallback(callbacks::M4A4);
		RegisterElement(&stattrak_m4a4);

		quality_m4a4.setup(XOR("quality"), XOR("quality_m4a4"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_m4a4.SetCallback(callbacks::SkinUpdate);
		quality_m4a4.AddShowCallback(callbacks::M4A4);
		RegisterElement(&quality_m4a4);

		seed_m4a4.setup(XOR("seed"), XOR("seed_m4a4"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_m4a4.SetCallback(callbacks::SkinUpdate);
		seed_m4a4.AddShowCallback(callbacks::M4A4);
		RegisterElement(&seed_m4a4);

		id_mac10.setup(XOR("paintkit id"), XOR("id_mac10"), 3);
		id_mac10.SetCallback(callbacks::SkinUpdate);
		id_mac10.AddShowCallback(callbacks::MAC10);
		RegisterElement(&id_mac10);

		stattrak_mac10.setup(XOR("stattrak"), XOR("stattrak_mac10"));
		stattrak_mac10.SetCallback(callbacks::SkinUpdate);
		stattrak_mac10.AddShowCallback(callbacks::MAC10);
		RegisterElement(&stattrak_mac10);

		quality_mac10.setup(XOR("quality"), XOR("quality_mac10"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_mac10.SetCallback(callbacks::SkinUpdate);
		quality_mac10.AddShowCallback(callbacks::MAC10);
		RegisterElement(&quality_mac10);

		seed_mac10.setup(XOR("seed"), XOR("seed_mac10"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_mac10.SetCallback(callbacks::SkinUpdate);
		seed_mac10.AddShowCallback(callbacks::MAC10);
		RegisterElement(&seed_mac10);

		id_p90.setup(XOR("paintkit id"), XOR("id_p90"), 3);
		id_p90.SetCallback(callbacks::SkinUpdate);
		id_p90.AddShowCallback(callbacks::P90);
		RegisterElement(&id_p90);

		stattrak_p90.setup(XOR("stattrak"), XOR("stattrak_p90"));
		stattrak_p90.SetCallback(callbacks::SkinUpdate);
		stattrak_p90.AddShowCallback(callbacks::P90);
		RegisterElement(&stattrak_p90);

		quality_p90.setup(XOR("quality"), XOR("quality_p90"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_p90.SetCallback(callbacks::SkinUpdate);
		quality_p90.AddShowCallback(callbacks::P90);
		RegisterElement(&quality_p90);

		seed_p90.setup(XOR("seed"), XOR("seed_p90"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_p90.SetCallback(callbacks::SkinUpdate);
		seed_p90.AddShowCallback(callbacks::P90);
		RegisterElement(&seed_p90);

		id_ump45.setup(XOR("paintkit id"), XOR("id_ump45"), 3);
		id_ump45.SetCallback(callbacks::SkinUpdate);
		id_ump45.AddShowCallback(callbacks::UMP45);
		RegisterElement(&id_ump45);

		stattrak_ump45.setup(XOR("stattrak"), XOR("stattrak_ump45"));
		stattrak_ump45.SetCallback(callbacks::SkinUpdate);
		stattrak_ump45.AddShowCallback(callbacks::UMP45);
		RegisterElement(&stattrak_ump45);

		quality_ump45.setup(XOR("quality"), XOR("quality_ump45"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_ump45.SetCallback(callbacks::SkinUpdate);
		quality_ump45.AddShowCallback(callbacks::UMP45);
		RegisterElement(&quality_ump45);

		seed_ump45.setup(XOR("seed"), XOR("seed_ump45"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_ump45.SetCallback(callbacks::SkinUpdate);
		seed_ump45.AddShowCallback(callbacks::UMP45);
		RegisterElement(&seed_ump45);

		id_xm1014.setup(XOR("paintkit id"), XOR("id_xm1014"), 3);
		id_xm1014.SetCallback(callbacks::SkinUpdate);
		id_xm1014.AddShowCallback(callbacks::XM1014);
		RegisterElement(&id_xm1014);

		stattrak_xm1014.setup(XOR("stattrak"), XOR("stattrak_xm1014"));
		stattrak_xm1014.SetCallback(callbacks::SkinUpdate);
		stattrak_xm1014.AddShowCallback(callbacks::XM1014);
		RegisterElement(&stattrak_xm1014);

		quality_xm1014.setup(XOR("quality"), XOR("quality_xm1014"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_xm1014.SetCallback(callbacks::SkinUpdate);
		quality_xm1014.AddShowCallback(callbacks::XM1014);
		RegisterElement(&quality_xm1014);

		seed_xm1014.setup(XOR("seed"), XOR("seed_xm1014"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_xm1014.SetCallback(callbacks::SkinUpdate);
		seed_xm1014.AddShowCallback(callbacks::XM1014);
		RegisterElement(&seed_xm1014);

		id_bizon.setup(XOR("paintkit id"), XOR("id_bizon"), 3);
		id_bizon.SetCallback(callbacks::SkinUpdate);
		id_bizon.AddShowCallback(callbacks::BIZON);
		RegisterElement(&id_bizon);

		stattrak_bizon.setup(XOR("stattrak"), XOR("stattrak_bizon"));
		stattrak_bizon.SetCallback(callbacks::SkinUpdate);
		stattrak_bizon.AddShowCallback(callbacks::BIZON);
		RegisterElement(&stattrak_bizon);

		quality_bizon.setup(XOR("quality"), XOR("quality_bizon"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_bizon.SetCallback(callbacks::SkinUpdate);
		quality_bizon.AddShowCallback(callbacks::BIZON);
		RegisterElement(&quality_bizon);

		seed_bizon.setup(XOR("seed"), XOR("seed_bizon"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_bizon.SetCallback(callbacks::SkinUpdate);
		seed_bizon.AddShowCallback(callbacks::BIZON);
		RegisterElement(&seed_bizon);

		id_mag7.setup(XOR("paintkit id"), XOR("id_mag7"), 3);
		id_mag7.SetCallback(callbacks::SkinUpdate);
		id_mag7.AddShowCallback(callbacks::MAG7);
		RegisterElement(&id_mag7);

		stattrak_mag7.setup(XOR("stattrak"), XOR("stattrak_mag7"));
		stattrak_mag7.SetCallback(callbacks::SkinUpdate);
		stattrak_mag7.AddShowCallback(callbacks::MAG7);
		RegisterElement(&stattrak_mag7);

		quality_mag7.setup(XOR("quality"), XOR("quality_mag7"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_mag7.SetCallback(callbacks::SkinUpdate);
		quality_mag7.AddShowCallback(callbacks::MAG7);
		RegisterElement(&quality_mag7);

		seed_mag7.setup(XOR("seed"), XOR("seed_mag7"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_mag7.SetCallback(callbacks::SkinUpdate);
		seed_mag7.AddShowCallback(callbacks::MAG7);
		RegisterElement(&seed_mag7);

		id_negev.setup(XOR("paintkit id"), XOR("id_negev"), 3);
		id_negev.SetCallback(callbacks::SkinUpdate);
		id_negev.AddShowCallback(callbacks::NEGEV);
		RegisterElement(&id_negev);

		stattrak_negev.setup(XOR("stattrak"), XOR("stattrak_negev"));
		stattrak_negev.SetCallback(callbacks::SkinUpdate);
		stattrak_negev.AddShowCallback(callbacks::NEGEV);
		RegisterElement(&stattrak_negev);

		quality_negev.setup(XOR("quality"), XOR("quality_negev"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_negev.SetCallback(callbacks::SkinUpdate);
		quality_negev.AddShowCallback(callbacks::NEGEV);
		RegisterElement(&quality_negev);

		seed_negev.setup(XOR("seed"), XOR("seed_negev"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_negev.SetCallback(callbacks::SkinUpdate);
		seed_negev.AddShowCallback(callbacks::NEGEV);
		RegisterElement(&seed_negev);

		id_sawedoff.setup(XOR("paintkit id"), XOR("id_sawedoff"), 3);
		id_sawedoff.SetCallback(callbacks::SkinUpdate);
		id_sawedoff.AddShowCallback(callbacks::SAWEDOFF);
		RegisterElement(&id_sawedoff);

		stattrak_sawedoff.setup(XOR("stattrak"), XOR("stattrak_sawedoff"));
		stattrak_sawedoff.SetCallback(callbacks::SkinUpdate);
		stattrak_sawedoff.AddShowCallback(callbacks::SAWEDOFF);
		RegisterElement(&stattrak_sawedoff);

		quality_sawedoff.setup(XOR("quality"), XOR("quality_sawedoff"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_sawedoff.SetCallback(callbacks::SkinUpdate);
		quality_sawedoff.AddShowCallback(callbacks::SAWEDOFF);
		RegisterElement(&quality_sawedoff);

		seed_sawedoff.setup(XOR("seed"), XOR("seed_sawedoff"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_sawedoff.SetCallback(callbacks::SkinUpdate);
		seed_sawedoff.AddShowCallback(callbacks::SAWEDOFF);
		RegisterElement(&seed_sawedoff);

		id_tec9.setup(XOR("paintkit id"), XOR("id_tec9"), 3);
		id_tec9.SetCallback(callbacks::SkinUpdate);
		id_tec9.AddShowCallback(callbacks::TEC9);
		RegisterElement(&id_tec9);

		stattrak_tec9.setup(XOR("stattrak"), XOR("stattrak_tec9"));
		stattrak_tec9.SetCallback(callbacks::SkinUpdate);
		stattrak_tec9.AddShowCallback(callbacks::TEC9);
		RegisterElement(&stattrak_tec9);

		quality_tec9.setup(XOR("quality"), XOR("quality_tec9"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_tec9.SetCallback(callbacks::SkinUpdate);
		quality_tec9.AddShowCallback(callbacks::TEC9);
		RegisterElement(&quality_tec9);

		seed_tec9.setup(XOR("seed"), XOR("seed_tec9"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_tec9.SetCallback(callbacks::SkinUpdate);
		seed_tec9.AddShowCallback(callbacks::TEC9);
		RegisterElement(&seed_tec9);

		id_p2000.setup(XOR("paintkit id"), XOR("id_p2000"), 3);
		id_p2000.SetCallback(callbacks::SkinUpdate);
		id_p2000.AddShowCallback(callbacks::P2000);
		RegisterElement(&id_p2000);

		stattrak_p2000.setup(XOR("stattrak"), XOR("stattrak_p2000"));
		stattrak_p2000.SetCallback(callbacks::SkinUpdate);
		stattrak_p2000.AddShowCallback(callbacks::P2000);
		RegisterElement(&stattrak_p2000);

		quality_p2000.setup(XOR("quality"), XOR("quality_p2000"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_p2000.SetCallback(callbacks::SkinUpdate);
		quality_p2000.AddShowCallback(callbacks::P2000);
		RegisterElement(&quality_p2000);

		seed_p2000.setup(XOR("seed"), XOR("seed_p2000"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_p2000.SetCallback(callbacks::SkinUpdate);
		seed_p2000.AddShowCallback(callbacks::P2000);
		RegisterElement(&seed_p2000);

		id_mp7.setup(XOR("paintkit id"), XOR("id_mp7"), 3);
		id_mp7.SetCallback(callbacks::SkinUpdate);
		id_mp7.AddShowCallback(callbacks::MP7);
		RegisterElement(&id_mp7);

		stattrak_mp7.setup(XOR("stattrak"), XOR("stattrak_mp7"));
		stattrak_mp7.SetCallback(callbacks::SkinUpdate);
		stattrak_mp7.AddShowCallback(callbacks::MP7);
		RegisterElement(&stattrak_mp7);

		quality_mp7.setup(XOR("quality"), XOR("quality_mp7"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_mp7.SetCallback(callbacks::SkinUpdate);
		quality_mp7.AddShowCallback(callbacks::MP7);
		RegisterElement(&quality_mp7);

		seed_mp7.setup(XOR("seed"), XOR("seed_mp7"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_mp7.SetCallback(callbacks::SkinUpdate);
		seed_mp7.AddShowCallback(callbacks::MP7);
		RegisterElement(&seed_mp7);

		id_mp9.setup(XOR("paintkit id"), XOR("id_mp9"), 3);
		id_mp9.SetCallback(callbacks::SkinUpdate);
		id_mp9.AddShowCallback(callbacks::MP9);
		RegisterElement(&id_mp9);

		stattrak_mp9.setup(XOR("stattrak"), XOR("stattrak_mp9"));
		stattrak_mp9.SetCallback(callbacks::SkinUpdate);
		stattrak_mp9.AddShowCallback(callbacks::MP9);
		RegisterElement(&stattrak_mp9);

		quality_mp9.setup(XOR("quality"), XOR("quality_mp9"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_mp9.SetCallback(callbacks::SkinUpdate);
		quality_mp9.AddShowCallback(callbacks::MP9);
		RegisterElement(&quality_mp9);

		seed_mp9.setup(XOR("seed"), XOR("seed_mp9"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_mp9.SetCallback(callbacks::SkinUpdate);
		seed_mp9.AddShowCallback(callbacks::MP9);
		RegisterElement(&seed_mp9);

		id_nova.setup(XOR("paintkit id"), XOR("id_nova"), 3);
		id_nova.SetCallback(callbacks::SkinUpdate);
		id_nova.AddShowCallback(callbacks::NOVA);
		RegisterElement(&id_nova);

		stattrak_nova.setup(XOR("stattrak"), XOR("stattrak_nova"));
		stattrak_nova.SetCallback(callbacks::SkinUpdate);
		stattrak_nova.AddShowCallback(callbacks::NOVA);
		RegisterElement(&stattrak_nova);

		quality_nova.setup(XOR("quality"), XOR("quality_nova"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_nova.SetCallback(callbacks::SkinUpdate);
		quality_nova.AddShowCallback(callbacks::NOVA);
		RegisterElement(&quality_nova);

		seed_nova.setup(XOR("seed"), XOR("seed_nova"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_nova.SetCallback(callbacks::SkinUpdate);
		seed_nova.AddShowCallback(callbacks::NOVA);
		RegisterElement(&seed_nova);

		id_p250.setup(XOR("paintkit id"), XOR("id_p250"), 3);
		id_p250.SetCallback(callbacks::SkinUpdate);
		id_p250.AddShowCallback(callbacks::P250);
		RegisterElement(&id_p250);

		stattrak_p250.setup(XOR("stattrak"), XOR("stattrak_p250"));
		stattrak_p250.SetCallback(callbacks::SkinUpdate);
		stattrak_p250.AddShowCallback(callbacks::P250);
		RegisterElement(&stattrak_p250);

		quality_p250.setup(XOR("quality"), XOR("quality_p250"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_p250.SetCallback(callbacks::SkinUpdate);
		quality_p250.AddShowCallback(callbacks::P250);
		RegisterElement(&quality_p250);

		seed_p250.setup(XOR("seed"), XOR("seed_p250"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_p250.SetCallback(callbacks::SkinUpdate);
		seed_p250.AddShowCallback(callbacks::P250);
		RegisterElement(&seed_p250);

		id_scar20.setup(XOR("paintkit id"), XOR("id_scar20"), 3);
		id_scar20.SetCallback(callbacks::SkinUpdate);
		id_scar20.AddShowCallback(callbacks::SCAR20);
		RegisterElement(&id_scar20);

		stattrak_scar20.setup(XOR("stattrak"), XOR("stattrak_scar20"));
		stattrak_scar20.SetCallback(callbacks::SkinUpdate);
		stattrak_scar20.AddShowCallback(callbacks::SCAR20);
		RegisterElement(&stattrak_scar20);

		quality_scar20.setup(XOR("quality"), XOR("quality_scar20"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_scar20.SetCallback(callbacks::SkinUpdate);
		quality_scar20.AddShowCallback(callbacks::SCAR20);
		RegisterElement(&quality_scar20);

		seed_scar20.setup(XOR("seed"), XOR("seed_scar20"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_scar20.SetCallback(callbacks::SkinUpdate);
		seed_scar20.AddShowCallback(callbacks::SCAR20);
		RegisterElement(&seed_scar20);

		id_sg553.setup(XOR("paintkit id"), XOR("id_sg553"), 3);
		id_sg553.SetCallback(callbacks::SkinUpdate);
		id_sg553.AddShowCallback(callbacks::SG553);
		RegisterElement(&id_sg553);

		stattrak_sg553.setup(XOR("stattrak"), XOR("stattrak_sg553"));
		stattrak_sg553.SetCallback(callbacks::SkinUpdate);
		stattrak_sg553.AddShowCallback(callbacks::SG553);
		RegisterElement(&stattrak_sg553);

		quality_sg553.setup(XOR("quality"), XOR("quality_sg553"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_sg553.SetCallback(callbacks::SkinUpdate);
		quality_sg553.AddShowCallback(callbacks::SG553);
		RegisterElement(&quality_sg553);

		seed_sg553.setup(XOR("seed"), XOR("seed_sg553"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_sg553.SetCallback(callbacks::SkinUpdate);
		seed_sg553.AddShowCallback(callbacks::SG553);
		RegisterElement(&seed_sg553);

		id_ssg08.setup(XOR("paintkit id"), XOR("id_ssg08"), 3);
		id_ssg08.SetCallback(callbacks::SkinUpdate);
		id_ssg08.AddShowCallback(callbacks::SSG08);
		RegisterElement(&id_ssg08);

		stattrak_ssg08.setup(XOR("stattrak"), XOR("stattrak_ssg08"));
		stattrak_ssg08.SetCallback(callbacks::SkinUpdate);
		stattrak_ssg08.AddShowCallback(callbacks::SSG08);
		RegisterElement(&stattrak_ssg08);

		quality_ssg08.setup(XOR("quality"), XOR("quality_ssg08"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_ssg08.SetCallback(callbacks::SkinUpdate);
		quality_ssg08.AddShowCallback(callbacks::SSG08);
		RegisterElement(&quality_ssg08);

		seed_ssg08.setup(XOR("seed"), XOR("seed_ssg08"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_ssg08.SetCallback(callbacks::SkinUpdate);
		seed_ssg08.AddShowCallback(callbacks::SSG08);
		RegisterElement(&seed_ssg08);

		id_m4a1s.setup(XOR("paintkit id"), XOR("id_m4a1s"), 3);
		id_m4a1s.SetCallback(callbacks::SkinUpdate);
		id_m4a1s.AddShowCallback(callbacks::M4A1S);
		RegisterElement(&id_m4a1s);

		stattrak_m4a1s.setup(XOR("stattrak"), XOR("stattrak_m4a1s"));
		stattrak_m4a1s.SetCallback(callbacks::SkinUpdate);
		stattrak_m4a1s.AddShowCallback(callbacks::M4A1S);
		RegisterElement(&stattrak_m4a1s);

		quality_m4a1s.setup(XOR("quality"), XOR("quality_m4a1s"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_m4a1s.SetCallback(callbacks::SkinUpdate);
		quality_m4a1s.AddShowCallback(callbacks::M4A1S);
		RegisterElement(&quality_m4a1s);

		seed_m4a1s.setup(XOR("seed"), XOR("seed_m4a1s"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_m4a1s.SetCallback(callbacks::SkinUpdate);
		seed_m4a1s.AddShowCallback(callbacks::M4A1S);
		RegisterElement(&seed_m4a1s);

		id_usps.setup(XOR("paintkit id"), XOR("id_usps"), 3);
		id_usps.SetCallback(callbacks::SkinUpdate);
		id_usps.AddShowCallback(callbacks::USPS);
		RegisterElement(&id_usps);

		stattrak_usps.setup(XOR("stattrak"), XOR("stattrak_usps"));
		stattrak_usps.SetCallback(callbacks::SkinUpdate);
		stattrak_usps.AddShowCallback(callbacks::USPS);
		RegisterElement(&stattrak_usps);

		quality_usps.setup(XOR("quality"), XOR("quality_usps"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_usps.SetCallback(callbacks::SkinUpdate);
		quality_usps.AddShowCallback(callbacks::USPS);
		RegisterElement(&quality_usps);

		seed_usps.setup(XOR("seed"), XOR("seed_usps"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_usps.SetCallback(callbacks::SkinUpdate);
		seed_usps.AddShowCallback(callbacks::USPS);
		RegisterElement(&seed_usps);

		id_cz75a.setup(XOR("paintkit id"), XOR("id_cz75a"), 3);
		id_cz75a.SetCallback(callbacks::SkinUpdate);
		id_cz75a.AddShowCallback(callbacks::CZ75A);
		RegisterElement(&id_cz75a);

		stattrak_cz75a.setup(XOR("stattrak"), XOR("stattrak_cz75a"));
		stattrak_cz75a.SetCallback(callbacks::SkinUpdate);
		stattrak_cz75a.AddShowCallback(callbacks::CZ75A);
		RegisterElement(&stattrak_cz75a);

		quality_cz75a.setup(XOR("quality"), XOR("quality_cz75a"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_cz75a.SetCallback(callbacks::SkinUpdate);
		quality_cz75a.AddShowCallback(callbacks::CZ75A);
		RegisterElement(&quality_cz75a);

		seed_cz75a.setup(XOR("seed"), XOR("seed_cz75a"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_cz75a.SetCallback(callbacks::SkinUpdate);
		seed_cz75a.AddShowCallback(callbacks::CZ75A);
		RegisterElement(&seed_cz75a);

		id_revolver.setup(XOR("paintkit id"), XOR("id_revolver"), 3);
		id_revolver.SetCallback(callbacks::SkinUpdate);
		id_revolver.AddShowCallback(callbacks::REVOLVER);
		RegisterElement(&id_revolver);

		stattrak_revolver.setup(XOR("stattrak"), XOR("stattrak_revolver"));
		stattrak_revolver.SetCallback(callbacks::SkinUpdate);
		stattrak_revolver.AddShowCallback(callbacks::REVOLVER);
		RegisterElement(&stattrak_revolver);

		quality_revolver.setup(XOR("quality"), XOR("quality_revolver"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_revolver.SetCallback(callbacks::SkinUpdate);
		quality_revolver.AddShowCallback(callbacks::REVOLVER);
		RegisterElement(&quality_revolver);

		seed_revolver.setup(XOR("seed"), XOR("seed_revolver"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_revolver.SetCallback(callbacks::SkinUpdate);
		seed_revolver.AddShowCallback(callbacks::REVOLVER);
		RegisterElement(&seed_revolver);

		id_bayonet.setup(XOR("paintkit id"), XOR("id_bayonet"), 3);
		id_bayonet.SetCallback(callbacks::SkinUpdate);
		id_bayonet.AddShowCallback(callbacks::KNIFE_BAYONET);
		RegisterElement(&id_bayonet);

		stattrak_bayonet.setup(XOR("stattrak"), XOR("stattrak_bayonet"));
		stattrak_bayonet.SetCallback(callbacks::SkinUpdate);
		stattrak_bayonet.AddShowCallback(callbacks::KNIFE_BAYONET);
		RegisterElement(&stattrak_bayonet);

		quality_bayonet.setup(XOR("quality"), XOR("quality_bayonet"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_bayonet.SetCallback(callbacks::SkinUpdate);
		quality_bayonet.AddShowCallback(callbacks::KNIFE_BAYONET);
		RegisterElement(&quality_bayonet);

		seed_bayonet.setup(XOR("seed"), XOR("seed_bayonet"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_bayonet.SetCallback(callbacks::SkinUpdate);
		seed_bayonet.AddShowCallback(callbacks::KNIFE_BAYONET);
		RegisterElement(&seed_bayonet);

		id_flip.setup(XOR("paintkit id"), XOR("id_flip"), 3);
		id_flip.SetCallback(callbacks::SkinUpdate);
		id_flip.AddShowCallback(callbacks::KNIFE_FLIP);
		RegisterElement(&id_flip);

		stattrak_flip.setup(XOR("stattrak"), XOR("stattrak_flip"));
		stattrak_flip.SetCallback(callbacks::SkinUpdate);
		stattrak_flip.AddShowCallback(callbacks::KNIFE_FLIP);
		RegisterElement(&stattrak_flip);

		quality_flip.setup(XOR("quality"), XOR("quality_flip"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_flip.SetCallback(callbacks::SkinUpdate);
		quality_flip.AddShowCallback(callbacks::KNIFE_FLIP);
		RegisterElement(&quality_flip);

		seed_flip.setup(XOR("seed"), XOR("seed_flip"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_flip.SetCallback(callbacks::SkinUpdate);
		seed_flip.AddShowCallback(callbacks::KNIFE_FLIP);
		RegisterElement(&seed_flip);

		id_gut.setup(XOR("paintkit id"), XOR("id_gut"), 3);
		id_gut.SetCallback(callbacks::SkinUpdate);
		id_gut.AddShowCallback(callbacks::KNIFE_GUT);
		RegisterElement(&id_gut);

		stattrak_gut.setup(XOR("stattrak"), XOR("stattrak_gut"));
		stattrak_gut.SetCallback(callbacks::SkinUpdate);
		stattrak_gut.AddShowCallback(callbacks::KNIFE_GUT);
		RegisterElement(&stattrak_gut);

		quality_gut.setup(XOR("quality"), XOR("quality_gut"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_gut.SetCallback(callbacks::SkinUpdate);
		quality_gut.AddShowCallback(callbacks::KNIFE_GUT);
		RegisterElement(&quality_gut);

		seed_gut.setup(XOR("seed"), XOR("seed_gut"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_gut.SetCallback(callbacks::SkinUpdate);
		seed_gut.AddShowCallback(callbacks::KNIFE_GUT);
		RegisterElement(&seed_gut);

		id_karambit.setup(XOR("paintkit id"), XOR("id_karambit"), 3);
		id_karambit.SetCallback(callbacks::SkinUpdate);
		id_karambit.AddShowCallback(callbacks::KNIFE_KARAMBIT);
		RegisterElement(&id_karambit);

		stattrak_karambit.setup(XOR("stattrak"), XOR("stattrak_karambit"));
		stattrak_karambit.SetCallback(callbacks::SkinUpdate);
		stattrak_karambit.AddShowCallback(callbacks::KNIFE_KARAMBIT);
		RegisterElement(&stattrak_karambit);

		quality_karambit.setup(XOR("quality"), XOR("quality_karambit"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_karambit.SetCallback(callbacks::SkinUpdate);
		quality_karambit.AddShowCallback(callbacks::KNIFE_KARAMBIT);
		RegisterElement(&quality_karambit);

		seed_karambit.setup(XOR("seed"), XOR("seed_karambit"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_karambit.SetCallback(callbacks::SkinUpdate);
		seed_karambit.AddShowCallback(callbacks::KNIFE_KARAMBIT);
		RegisterElement(&seed_karambit);

		id_m9.setup(XOR("paintkit id"), XOR("id_m9"), 3);
		id_m9.SetCallback(callbacks::SkinUpdate);
		id_m9.AddShowCallback(callbacks::KNIFE_M9_BAYONET);
		RegisterElement(&id_m9);

		stattrak_m9.setup(XOR("stattrak"), XOR("stattrak_m9"));
		stattrak_m9.SetCallback(callbacks::SkinUpdate);
		stattrak_m9.AddShowCallback(callbacks::KNIFE_M9_BAYONET);
		RegisterElement(&stattrak_m9);

		quality_m9.setup(XOR("quality"), XOR("quality_m9"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_m9.SetCallback(callbacks::SkinUpdate);
		quality_m9.AddShowCallback(callbacks::KNIFE_M9_BAYONET);
		RegisterElement(&quality_m9);

		seed_m9.setup(XOR("seed"), XOR("seed_m9"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_m9.SetCallback(callbacks::SkinUpdate);
		seed_m9.AddShowCallback(callbacks::KNIFE_M9_BAYONET);
		RegisterElement(&seed_m9);

		id_huntsman.setup(XOR("paintkit id"), XOR("id_huntsman"), 3);
		id_huntsman.SetCallback(callbacks::SkinUpdate);
		id_huntsman.AddShowCallback(callbacks::KNIFE_HUNTSMAN);
		RegisterElement(&id_huntsman);

		stattrak_huntsman.setup(XOR("stattrak"), XOR("stattrak_huntsman"));
		stattrak_huntsman.SetCallback(callbacks::SkinUpdate);
		stattrak_huntsman.AddShowCallback(callbacks::KNIFE_HUNTSMAN);
		RegisterElement(&stattrak_huntsman);

		quality_huntsman.setup(XOR("quality"), XOR("quality_huntsman"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_huntsman.SetCallback(callbacks::SkinUpdate);
		quality_huntsman.AddShowCallback(callbacks::KNIFE_HUNTSMAN);
		RegisterElement(&quality_huntsman);

		seed_huntsman.setup(XOR("seed"), XOR("seed_huntsman"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_huntsman.SetCallback(callbacks::SkinUpdate);
		seed_huntsman.AddShowCallback(callbacks::KNIFE_HUNTSMAN);
		RegisterElement(&seed_huntsman);

		id_falchion.setup(XOR("paintkit id"), XOR("id_falchion"), 3);
		id_falchion.SetCallback(callbacks::SkinUpdate);
		id_falchion.AddShowCallback(callbacks::KNIFE_FALCHION);
		RegisterElement(&id_falchion);

		stattrak_falchion.setup(XOR("stattrak"), XOR("stattrak_falchion"));
		stattrak_falchion.SetCallback(callbacks::SkinUpdate);
		stattrak_falchion.AddShowCallback(callbacks::KNIFE_FALCHION);
		RegisterElement(&stattrak_falchion);

		quality_falchion.setup(XOR("quality"), XOR("quality_falchion"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_falchion.SetCallback(callbacks::SkinUpdate);
		quality_falchion.AddShowCallback(callbacks::KNIFE_FALCHION);
		RegisterElement(&quality_falchion);

		seed_falchion.setup(XOR("seed"), XOR("seed_falchion"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_falchion.SetCallback(callbacks::SkinUpdate);
		seed_falchion.AddShowCallback(callbacks::KNIFE_FALCHION);
		RegisterElement(&seed_falchion);

		id_bowie.setup(XOR("paintkit id"), XOR("id_bowie"), 3);
		id_bowie.SetCallback(callbacks::SkinUpdate);
		id_bowie.AddShowCallback(callbacks::KNIFE_BOWIE);
		RegisterElement(&id_bowie);

		stattrak_bowie.setup(XOR("stattrak"), XOR("stattrak_bowie"));
		stattrak_bowie.SetCallback(callbacks::SkinUpdate);
		stattrak_bowie.AddShowCallback(callbacks::KNIFE_BOWIE);
		RegisterElement(&stattrak_bowie);

		quality_bowie.setup(XOR("quality"), XOR("quality_bowie"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_bowie.SetCallback(callbacks::SkinUpdate);
		quality_bowie.AddShowCallback(callbacks::KNIFE_BOWIE);
		RegisterElement(&quality_bowie);

		seed_bowie.setup(XOR("seed"), XOR("seed_bowie"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_bowie.SetCallback(callbacks::SkinUpdate);
		seed_bowie.AddShowCallback(callbacks::KNIFE_BOWIE);
		RegisterElement(&seed_bowie);

		id_butterfly.setup(XOR("paintkit id"), XOR("id_butterfly"), 3);
		id_butterfly.SetCallback(callbacks::SkinUpdate);
		id_butterfly.AddShowCallback(callbacks::KNIFE_BUTTERFLY);
		RegisterElement(&id_butterfly);

		stattrak_butterfly.setup(XOR("stattrak"), XOR("stattrak_butterfly"));
		stattrak_butterfly.SetCallback(callbacks::SkinUpdate);
		stattrak_butterfly.AddShowCallback(callbacks::KNIFE_BUTTERFLY);
		RegisterElement(&stattrak_butterfly);

		quality_butterfly.setup(XOR("quality"), XOR("quality_butterfly"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_butterfly.SetCallback(callbacks::SkinUpdate);
		quality_butterfly.AddShowCallback(callbacks::KNIFE_BUTTERFLY);
		RegisterElement(&quality_butterfly);

		seed_butterfly.setup(XOR("seed"), XOR("seed_butterfly"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_butterfly.SetCallback(callbacks::SkinUpdate);
		seed_butterfly.AddShowCallback(callbacks::KNIFE_BUTTERFLY);
		RegisterElement(&seed_butterfly);

		id_daggers.setup(XOR("paintkit id"), XOR("id_daggers"), 3);
		id_daggers.SetCallback(callbacks::SkinUpdate);
		id_daggers.AddShowCallback(callbacks::KNIFE_SHADOW_DAGGERS);
		RegisterElement(&id_daggers);

		stattrak_daggers.setup(XOR("stattrak"), XOR("stattrak_daggers"));
		stattrak_daggers.SetCallback(callbacks::SkinUpdate);
		stattrak_daggers.AddShowCallback(callbacks::KNIFE_SHADOW_DAGGERS);
		RegisterElement(&stattrak_daggers);

		quality_daggers.setup(XOR("quality"), XOR("quality_daggers"), 1.f, 100.f, true, 0, 100.f, 1.f, XOR(L"%"));
		quality_daggers.SetCallback(callbacks::SkinUpdate);
		quality_daggers.AddShowCallback(callbacks::KNIFE_SHADOW_DAGGERS);
		RegisterElement(&quality_daggers);

		seed_daggers.setup(XOR("seed"), XOR("seed_daggers"), 0.f, 255.f, true, 0, 0.f, 1.f);
		seed_daggers.SetCallback(callbacks::SkinUpdate);
		seed_daggers.AddShowCallback(callbacks::KNIFE_SHADOW_DAGGERS);
		RegisterElement(&seed_daggers);

		// col 2.
		knife.setup(XOR("Knife model"), XOR("skins_knife_model"), { XOR("off"), XOR("bayonet"), XOR("bowie"), XOR("butterfly"), XOR("falchion"), XOR("flip"), XOR("gut"), XOR("huntsman"), XOR("karambit"), XOR("m9 bayonet"), XOR("daggers") });
		knife.SetCallback(callbacks::SkinUpdate);
		RegisterElement(&knife, 1);

		glove.setup(XOR("Glove model"), XOR("skins_glove_model"), { XOR("off"), XOR("bloodhound"), XOR("sport"), XOR("driver"), XOR("handwraps"), XOR("moto"), XOR("specialist") });
		glove.SetCallback(callbacks::ForceFullUpdate);
		RegisterElement(&glove, 1);

		glove_id.setup(XOR("Glove paintkit id"), XOR("skins_glove_id"), 2);
		glove_id.SetCallback(callbacks::ForceFullUpdate);
		RegisterElement(&glove_id, 1);
	}
};

class MiscTab : public Tab {
public:
	// col1.

	Checkbox skyboxchange;
	Dropdown skybox;
	Checkbox clantag;
	Checkbox unlock;
	Dropdown hitsounds;
	Checkbox hitmarker;
	Checkbox hitmarkers;
	Checkbox ragdoll_force;
	Checkbox killfeed;
	Checkbox forceimpact;
	Checkbox slide_walk;
	Checkbox killsay;
	Checkbox watermark;
	

	Checkbox ranks;
	MultiDropdown buy1;
	MultiDropdown buy2;
	MultiDropdown buy3;
	Slider offscreen_mode;
	Slider offscreen_mode1;

	// col2.
	Colorpicker menu_color;

	MultiDropdown notifications;
	Dropdown mode;
	Dropdown config;
	Keybind  key1;
	Keybind  key2;
	Keybind  key3;
	Keybind  key4;
	Keybind  key5;
	Keybind  key6;
	Button   save;
	Button   load;
	Checkbox   HiddenCvar;
	Keybind       last_tick_defuse;
	Checkbox	  fake_latency_always;
	Keybind       fake_latency;
	Slider		  fake_latency_amt;

public:
	void init() {
		SetTitle(XOR("misc"));

		buy1.setup(XOR("auto buy items"), XOR("auto_buy1"),
			{
				XOR("galilar"),
				XOR("famas"),
				XOR("ak47"),
				XOR("m4a1"),
				XOR("m4a1_silencer"),
				XOR("ssg08"),
				XOR("aug"),
				XOR("sg556"),
				XOR("awp"),
				XOR("scar20"),
				XOR("g3sg1"),
				XOR("nova"),
				XOR("xm1014"),
				XOR("mag7"),
				XOR("m249"),
				XOR("negev"),
				XOR("mac10"),
				XOR("mp9"),
				XOR("mp7"),
				XOR("ump45"),
				XOR("p90"),
				XOR("bizon"),
			});
		RegisterElement(&buy1);

		buy2.setup("", XOR("auto_buy2"),
			{
				XOR("glock"),
				XOR("hkp2000"),
				XOR("usp_silencer"),
				XOR("elite"),
				XOR("p250"),
				XOR("tec9"),
				XOR("fn57"),
				XOR("deagle"),
			}, false);
		RegisterElement(&buy2);

		buy3.setup("", XOR("auto_buy3"),
			{
				XOR("vest"),
				XOR("vesthelm"),
				XOR("taser"),
				XOR("defuser"),
				XOR("heavyarmor"),
				XOR("molotov"),
				XOR("incgrenade"),
				XOR("decoy"),
				XOR("flashbang"),
				XOR("hegrenade"),
				XOR("smokegrenade"),
			}, false);
		RegisterElement(&buy3);

		notifications.setup(XOR("Logs"), XOR("notifications"), { XOR("Matchmaking"), XOR("Damage"), XOR("Hurt"), XOR("Buy"), XOR("Bomb"), XOR("Defuse") });
		RegisterElement(&notifications);

		last_tick_defuse.setup(XOR("Last second defuse"), XOR("last_tick_defuse"));
		RegisterElement(&last_tick_defuse);

		fake_latency.setup(XOR("Ping spike"), XOR("fake_latency"));
		fake_latency.SetToggleCallback(callbacks::ToggleFakeLatency);
		RegisterElement(&fake_latency);

		fake_latency_amt.setup("", XOR("fake_latency_amt"), 50.f, 1000.f, false, 0, 200.f, 50.f, XOR(L"ms"));
		RegisterElement(&fake_latency_amt);

		void init();
		SetTitle(XOR("Misc"));

		menu_color.setup(XOR("Menu color"), XOR("menu_color"), colors::burgundy, &g_gui.m_color);
		RegisterElement(&menu_color);


		config.setup(XOR("Cfg"), XOR("cfg"), { XOR("1"), XOR("2"), XOR("3"), XOR("4"), XOR("5") });
		config.RemoveFlags(ElementFlags::SAVE);
		RegisterElement(&config, 1);

		key1.setup(XOR("Config key 1"), XOR("cfg_key1"));
		key1.RemoveFlags(ElementFlags::SAVE);
		key1.SetCallback(callbacks::SaveHotkeys);
		key1.AddShowCallback(callbacks::IsConfig1);
		key1.SetToggleCallback(callbacks::ConfigLoad1);
		RegisterElement(&key1, 1);

		key2.setup(XOR("Config key 2"), XOR("cfg_key2"));
		key2.RemoveFlags(ElementFlags::SAVE);
		key2.SetCallback(callbacks::SaveHotkeys);
		key2.AddShowCallback(callbacks::IsConfig2);
		key2.SetToggleCallback(callbacks::ConfigLoad2);
		RegisterElement(&key2, 1);

		key3.setup(XOR("Config key 3"), XOR("cfg_key3"));
		key3.RemoveFlags(ElementFlags::SAVE);
		key3.SetCallback(callbacks::SaveHotkeys);
		key3.AddShowCallback(callbacks::IsConfig3);
		key3.SetToggleCallback(callbacks::ConfigLoad3);
		RegisterElement(&key3, 1);

		key4.setup(XOR("Config key 4"), XOR("cfg_key4"));
		key4.RemoveFlags(ElementFlags::SAVE);
		key4.SetCallback(callbacks::SaveHotkeys);
		key4.AddShowCallback(callbacks::IsConfig4);
		key4.SetToggleCallback(callbacks::ConfigLoad4);
		RegisterElement(&key4, 1);

		key5.setup(XOR("Config key 5"), XOR("cfg_key5"));
		key5.RemoveFlags(ElementFlags::SAVE);
		key5.SetCallback(callbacks::SaveHotkeys);
		key5.AddShowCallback(callbacks::IsConfig5);
		key5.SetToggleCallback(callbacks::ConfigLoad5);
		RegisterElement(&key5, 1);

		key6.setup(XOR("Config key 6"), XOR("cfg_key6"));
		key6.RemoveFlags(ElementFlags::SAVE);
		key6.SetCallback(callbacks::SaveHotkeys);
		key6.AddShowCallback(callbacks::IsConfig6);
		key6.SetToggleCallback(callbacks::ConfigLoad6);
		RegisterElement(&key6, 1);

		save.setup(XOR("Save config"));
		save.SetCallback(callbacks::ConfigSave);
		RegisterElement(&save, 1);

		load.setup(XOR("Load config"));
		load.SetCallback(callbacks::ConfigLoad);
		RegisterElement(&load, 1);

		


		// col2.
		skyboxchange.setup(XOR("Skybox changer"), XOR("skyboxchange"));
		RegisterElement(&skyboxchange, 1);

		//		mode.setup(XOR("safety mode"), XOR("mode"), { XOR("matchmaking"), XOR("no-spread") });
		//		RegisterElement(&mode, 1);

		skybox.setup(XOR("Skyboxes"), XOR("skybox"), { XOR("Tibet"),XOR("Embassy"),XOR("Italy"),XOR("Daylight"),XOR("Cloudy"),XOR("Night 1"),XOR("Night 2"),XOR("Night Flat"),XOR("Day HD"),XOR("Day"),XOR("Rural"),XOR("Vertigo HD"),XOR("Vertigo Blue HD"),XOR("Vertigo"),XOR("Vietnam"),XOR("Dusty Sky"),XOR("Jungle"),XOR("Nuke"),XOR("Office") });
		skybox.AddShowCallback(callbacks::IsSkyBoxChange);

		RegisterElement(&skybox, 1);

		clantag.setup(XOR("Clan-tag spammer"), XOR("clantag"));
		RegisterElement(&clantag, 1);

		unlock.setup(XOR("Inventory unlocker"), XOR("unlock_inventory"));
		RegisterElement(&unlock, 1);

		forceimpact.setup(XOR("Bullet impacts"), XOR("forceimpact"));
		RegisterElement(&forceimpact, 1);

		hitmarker.setup(XOR("Hitmarker"), XOR("hitmarker"));
		RegisterElement(&hitmarker, 1);

		hitsounds.setup(XOR("Hitmarker sound"), XOR("hitsounds"), { XOR("off"), XOR("arena switch"), XOR("opera"), XOR("bameware"), XOR("dopium"), XOR("bubble"), XOR("cod"), XOR("fatality"), XOR("pop") });
		RegisterElement(&hitsounds, 1);

		ragdoll_force.setup(XOR("Force ragdolls"), XOR("ragdoll_force"));
		RegisterElement(&ragdoll_force, 1);

		ranks.setup(XOR("Reveal ranks"), XOR("ranks"));
		RegisterElement(&ranks, 1);

		killfeed.setup(XOR("Extended killfeed"), XOR("killfeed"));
		killfeed.SetCallback(callbacks::ToggleKillfeed);
		RegisterElement(&killfeed, 1);

		slide_walk.setup(XOR("Stanky legs"), XOR("slide_walk"));
		RegisterElement(&slide_walk, 1);


		killsay.setup(XOR("Killsay"), XOR("killsay"));
		RegisterElement(&killsay, 1);

		watermark.setup(XOR("Watermark"), XOR("watermark"));
		RegisterElement(&watermark, 1);

		offscreen_mode.setup(XOR("Arrow size"), XOR("offscreen_mode"), 20.f, 200.f, true, 0, 100.f, 1.f, XOR(L""));
		RegisterElement(&offscreen_mode);

		offscreen_mode1.setup(XOR("Arrow Distance"), XOR("offscreen_mode1"), 20.f, 200.f, true, 0, 200.f, 1.f, XOR(L""));
		RegisterElement(&offscreen_mode1);

		HiddenCvar.setup(XOR("Unlock Cvars"), XOR("HiddenCvar"));
		HiddenCvar.SetCallback(callbacks::HiddenCvar);
		RegisterElement(&HiddenCvar, 1);

	}
};


class MainForm : public Form {
public:
	// aimbot.
	AimbotTab    aimbot;
	AntiAimTab   antiaim;

	// visuals.
	PlayersTab	 players;
	VisualsTab	 visuals;

	// misc.
	MovementTab  movement;
	SkinsTab     skins;
	MiscTab	     misc;

public:
	void init() {
		SetPosition(50, 50);
		SetSize(630, 500);

		// aim.
		RegisterTab(&aimbot);
		aimbot.init();

		RegisterTab(&antiaim);
		antiaim.init();

		// visuals.
		RegisterTab(&players);
		players.init();

		RegisterTab(&visuals);
		visuals.init();

		// misc.
		RegisterTab(&movement);
		movement.init();

		RegisterTab(&skins);
		skins.init();

		RegisterTab(&misc);
		misc.init();


	}
};

class Menu {
public:
	MainForm main;

public:
	void init() {

		Colorpicker::init();	// points here, so this was the second injection crash problem, moved here to fix bound bug, look at colorpicker init

		main.init();

		g_gui.RegisterForm(&main, VK_INSERT);
	}
};

extern Menu g_menu;