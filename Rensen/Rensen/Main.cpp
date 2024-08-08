#include "Head.h"
#include "CS2_SDK.h"
const float Rensen_Version = 4.30;//程序版本
const string Rensen_ReleaseDate = "[2024-08-08 18:15]";//程序发布日期时间
namespace Control_Var//套用到菜单的调试变量 (例如功能开关)
{
	EasyGUI::EasyGUI GUI_VAR; EasyGUI::EasyGUI_IO GUI_IO; BOOL Menu_Open = true;//菜单初始化变量
	const string UI_LocalConfigPath = "Rensen.cfg";
	const string UI_DefaultConfig = "1\n6\n1\n1\n0\n1\n1\n100\n1\n1\n0\n100\n0\n0\n100\n0\n1\n100\n5\n1\n5\n0\n1\n150\n1\n0.015\n0.004\n1\n1\n2\n1\n500\n1\n0\n0\n1\n1\n0\n1\n0\n1\n1\n1\n1\n40\n80\n0\n255\n255\n255\n255\n1\n1\n1\n4\n260\n180\n26\n11\n1\n1\n1000\n10\n1\n1\n5\n5\n1\n1\n0\n0\n1\n1\n1\n0\n0\n1\n160\n800\n350\n0\n45\n0\n200\n200\n255\n250\n200\n200\n255\n2\n0\n1\n1\n4\n10\n10\n0\n1\n2\n10\n1\n500\n1\n1\n4\n1\n3\n1\n10\n100\n1\n1\n0\n1\n1\n50\n1\n6\n0\n5\n1\n5\n0\n1\n\n13\n0\n1\n9\n1\n255\n0\n100\n0\n400\n40\n250\n40\n";//默认参数
	//----------------------------------------------------------------------------------------------
	BOOL UI_Visual_Res_2560, UI_Visual_Res_1920, UI_Visual_Res_1280, UI_Visual_Res_960;
	BOOL UI_Visual_Radar_Show;
	BOOL UI_Misc_LoadCloudConfig;
	BOOL UI_Setting_OPENLINKAuthor;
	BOOL UI_Setting_SaveLocalConfig;
	BOOL UI_Setting_StartCS, UI_Setting_QuitCS;
	BOOL UI_Setting_GithubRepositories;
	BOOL UI_Setting_RestartMenu;
	BOOL UI_Setting_Unload;
	//以上变量不需要纳入参数------------------------------------------------------------------------
	BOOL UI_Legit_Aimbot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 1));
	int UI_Legit_Aimbot_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 2));
	BOOL UI_Legit_Aimbot_JudgingWall = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 3));
	BOOL UI_Legit_Aimbot_RemoveRecoil = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 4));
	BOOL UI_Legit_Aimbot_TriggerOnAim = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 5));
	BOOL UI_Legit_Aimbot_AutoShoot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 6));
	BOOL UI_Legit_Aimbot_AutoStop = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 7));
	int UI_Legit_Aimbot_AutoShootDelay = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 8));
	BOOL UI_Legit_AdaptiveAimbot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 9));
	BOOL UI_Legit_Armory_ShowAimbotRange = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 10));
	BOOL UI_Legit_Armory_BodyAim_PISTOL = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 11));
	int UI_Legit_Armory_Range_PISTOL = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 12));
	float UI_Legit_Armory_Smooth_PISTOL = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 13));
	BOOL UI_Legit_Armory_BodyAim_RIFLE = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 14));
	int UI_Legit_Armory_Range_RIFLE = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 15));
	float UI_Legit_Armory_Smooth_RIFLE = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 16));
	BOOL UI_Legit_Armory_BodyAim_SNIPER = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 17));
	int UI_Legit_Armory_Range_SNIPER = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 18));
	float UI_Legit_Armory_Smooth_SNIPER = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 19));
	BOOL UI_Legit_Triggerbot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 20));
	int UI_Legit_Triggerbot_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 21));
	BOOL UI_Legit_Triggerbot_AnyTarget = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 22));
	int UI_Legit_Triggerbot_ShootDelay = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 23));
	int UI_Legit_Triggerbot_ShootDuration = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 24));
	BOOL UI_Legit_PreciseAim = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 25));
	float UI_Legit_PreciseAim_DefaultSensitivity = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 26));
	float UI_Legit_PreciseAim_EnableSensitivity = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 27));
	BOOL UI_Legit_RemoveRecoil = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 28));
	BOOL UI_Legit_RemoveRecoil_LateralRepair = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 29));
	int UI_Legit_RemoveRecoil_StartBullet = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 30));
	BOOL UI_Legit_Backtracking = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 31));
	int UI_Legit_Backtracking_MaximumTime = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 32));
	BOOL UI_Visual_ESP = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 33));
	int UI_Visual_ESP_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 34));
	BOOL UI_Visual_ESP_Box = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 35));
	BOOL UI_Visual_ESP_Health = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 36));
	BOOL UI_Visual_ESP_ActiveWeapon = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 37));
	BOOL UI_Visual_ESP_Line = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 38));
	BOOL UI_Visual_ESP_Skeleton = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 39));
	BOOL UI_Visual_ESP_HeadDot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 40));
	BOOL UI_Visual_ESP_State = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 41));
	BOOL UI_Visual_ESP_Name = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 42));
	BOOL UI_Visual_ESP_Drops = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 43));
	BOOL UI_Visual_ESP_OutFOV = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 44));
	int UI_Visual_ESP_OutFOV_Size = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 45));
	int UI_Visual_ESP_OutFOV_Radius = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 46));
	BOOL UI_Visual_ESP_CustomColor = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 47));
	Variable::Vector4 UI_Visual_ESP_CustomColor_Color = { Variable::string_int_(System::Get_File(UI_LocalConfigPath, 48)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 49)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 50)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 51)) };
	int UI_Visual_ESP_DrawDelay = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 52));
	BOOL UI_Visual_Radar = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 53));
	BOOL UI_Visual_Radar_FollowAngle = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 54));
	float UI_Visual_Radar_Range = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 55));
	int UI_Visual_Radar_Size = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 56));
	int UI_Visual_Radar_Alpha = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 57));
	Variable::Vector2 UI_Visual_Radar_Pos = { Variable::string_int_(System::Get_File(UI_LocalConfigPath, 58)), Variable::string_int_(System::Get_File(UI_LocalConfigPath, 59)) };
	BOOL UI_Misc_BunnyHop = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 60));
	BOOL UI_Misc_HitSound = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 61));
	int UI_Misc_HitSound_Tone = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 62));
	int	UI_Misc_HitSound_Length = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 63));
	BOOL UI_Visual_HitMark = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 64));
	BOOL UI_Visual_HitMark_Damage = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 65));
	int UI_Visual_HitMark_Range = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 66));
	int UI_Visual_HitMark_Length = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 67));
	BOOL UI_Misc_AutoKnife = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 68));
	BOOL UI_Misc_AutoTaser = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 69));
	int UI_Misc_AutoKnife_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 70));
	int UI_Misc_AutoTaser_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 71));
	BOOL UI_Misc_Watermark = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 72));
	BOOL UI_Misc_SniperCrosshair = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 73));
	BOOL UI_Misc_TeamCheck = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 74));
	BOOL UI_Misc_LockGameWindow = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 75));
	BOOL UI_Debug_ShowDebugWindow = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 76));
	BOOL UI_Misc_Sonar = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 77));
	int UI_Misc_Sonar_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 78));
	int UI_Misc_Sonar_Range_Far = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 79));
	int UI_Misc_Sonar_Range_Near = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 80));
	int UI_Misc_SelectedConfig = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 81));
	int UI_Setting_MenuKey = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 82));
	BOOL UI_Setting_CustomColor = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 83));
	Variable::Vector4 UI_Setting_MainColor = { Variable::string_int_(System::Get_File(UI_LocalConfigPath, 84)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 85)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 86)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 87)) };
	Variable::Vector4 UI_Visual_HitMark_Color = { Variable::string_int_(System::Get_File(UI_LocalConfigPath, 88)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 89)),Variable::string_int_(System::Get_File(UI_LocalConfigPath, 90)) };
	int UI_Visual_HitMark_Thickness = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 91));
	BOOL UI_Legit_Triggerbot_ShootWhenAccurate = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 92));
	BOOL UI_Misc_AntiAFKKick = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 93));
	BOOL UI_Legit_MagnetAim = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 94));
	float UI_Legit_MagnetAim_Smooth = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 95));
	float UI_Legit_AdaptiveAimbot_InitialSmooth = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 96));
	int UI_Misc_SniperCrosshair_Size = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 97));
	BOOL UI_Spoof_Spoof = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 98));
	BOOL UI_Spoof_AimbotTeam = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 99));
	int UI_Spoof_AimbotTeam_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 100));
	float UI_Spoof_AimbotTeam_Smooth = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 101));
	BOOL UI_Spoof_IncreaseRecoil = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 102));
	int UI_Spoof_IncreaseRecoil_Value = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 103));
	BOOL UI_Spoof_DropC4 = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 104));
	BOOL UI_Spoof_FakeAntiAim = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 105));
	int UI_Spoof_FakeAntiAim_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 106));
	BOOL UI_Spoof_KillDropSniper = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 107));
	float UI_Setting_MenuAnimation = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 108));
	BOOL UI_Visual_HitMark_KillEffect = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 109));
	int UI_Visual_HitMark_KillEffect_Quantity = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 110));
	int UI_Visual_HitMark_KillEffect_Range = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 111));
	int UI_Visual_ESP_Skeleton_Thickness = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 112));
	BOOL UI_Misc_ByPassOBS = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 113));
	BOOL UI_Misc_SavePerformance = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 114));
	BOOL UI_Legit_Aimbot_AutoScope = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 115));
	BOOL UI_Misc_NightMode = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 116));
	int UI_Misc_NightMode_Alpha = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 117));
	BOOL UI_Spoof_LearnPlayer = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 118));
	int UI_Spoof_LearnPlayer_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 119));
	BOOL UI_Misc_AutoPeek = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 120));
	int UI_Misc_AutoPeek_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 121));
	BOOL UI_Spoof_FakeRageBot = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 122));
	int UI_Spoof_FakeRageBot_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 123));
	int UI_Spoof_FakeRageBot_Target = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 124));
	BOOL UI_Misc_QuickStop = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 125));
	string UI_Setting_MenuFont = System::Get_File(UI_LocalConfigPath, 126);
	int UI_Setting_MenuFontSize = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 127));
	BOOL UI_Misc_AutoKillCeasefire = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 128));
	BOOL UI_Misc_CursorESP = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 129));
	int UI_Misc_CursorESP_Key = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 130));
	BOOL UI_Legit_Armory_HitSiteParser = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 131));
	int UI_Visual_ESP_DrawAlpha = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 132));
	BOOL UI_Legit_Armory_BodyAim_SHOTGUN = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 133));
	int UI_Legit_Armory_Range_SHOTGUN = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 134));
	float UI_Legit_Armory_Smooth_SHOTGUN = Variable::string_float_(System::Get_File(UI_LocalConfigPath, 135));
	int UI_Legit_Armory_TriggerDistance_SHOTGUN = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 136));
	int UI_Legit_MagnetAim_Range = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 137));
	int UI_Legit_Backtracking_MinimumTime = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 138));
	int UI_Legit_RemoveRecoil_Sensitive = Variable::string_int_(System::Get_File(UI_LocalConfigPath, 139));
	//----------------------------------------------------------------------------------------------
	void SaveLocalConfig() noexcept//保存本地参数
	{
		System::Create_File(UI_LocalConfigPath,
			to_string(UI_Legit_Aimbot) + "\n" +
			to_string(UI_Legit_Aimbot_Key) + "\n" +
			to_string(UI_Legit_Aimbot_JudgingWall) + "\n" +
			to_string(UI_Legit_Aimbot_RemoveRecoil) + "\n" +
			to_string(UI_Legit_Aimbot_TriggerOnAim) + "\n" +
			to_string(UI_Legit_Aimbot_AutoShoot) + "\n" +
			to_string(UI_Legit_Aimbot_AutoStop) + "\n" +
			to_string(UI_Legit_Aimbot_AutoShootDelay) + "\n" +
			to_string(UI_Legit_AdaptiveAimbot) + "\n" +
			to_string(UI_Legit_Armory_ShowAimbotRange) + "\n" +
			to_string(UI_Legit_Armory_BodyAim_PISTOL) + "\n" +
			to_string(UI_Legit_Armory_Range_PISTOL) + "\n" +
			to_string(UI_Legit_Armory_Smooth_PISTOL) + "\n" +
			to_string(UI_Legit_Armory_BodyAim_RIFLE) + "\n" +
			to_string(UI_Legit_Armory_Range_RIFLE) + "\n" +
			to_string(UI_Legit_Armory_Smooth_RIFLE) + "\n" +
			to_string(UI_Legit_Armory_BodyAim_SNIPER) + "\n" +
			to_string(UI_Legit_Armory_Range_SNIPER) + "\n" +
			to_string(UI_Legit_Armory_Smooth_SNIPER) + "\n" +
			to_string(UI_Legit_Triggerbot) + "\n" +
			to_string(UI_Legit_Triggerbot_Key) + "\n" +
			to_string(UI_Legit_Triggerbot_AnyTarget) + "\n" +
			to_string(UI_Legit_Triggerbot_ShootDelay) + "\n" +
			to_string(UI_Legit_Triggerbot_ShootDuration) + "\n" +
			to_string(UI_Legit_PreciseAim) + "\n" +
			to_string(UI_Legit_PreciseAim_DefaultSensitivity) + "\n" +
			to_string(UI_Legit_PreciseAim_EnableSensitivity) + "\n" +
			to_string(UI_Legit_RemoveRecoil) + "\n" +
			to_string(UI_Legit_RemoveRecoil_LateralRepair) + "\n" +
			to_string(UI_Legit_RemoveRecoil_StartBullet) + "\n" +
			to_string(UI_Legit_Backtracking) + "\n" +
			to_string(UI_Legit_Backtracking_MaximumTime) + "\n" +
			to_string(UI_Visual_ESP) + "\n" +
			to_string(UI_Visual_ESP_Key) + "\n" +
			to_string(UI_Visual_ESP_Box) + "\n" +
			to_string(UI_Visual_ESP_Health) + "\n" +
			to_string(UI_Visual_ESP_ActiveWeapon) + "\n" +
			to_string(UI_Visual_ESP_Line) + "\n" +
			to_string(UI_Visual_ESP_Skeleton) + "\n" +
			to_string(UI_Visual_ESP_HeadDot) + "\n" +
			to_string(UI_Visual_ESP_State) + "\n" +
			to_string(UI_Visual_ESP_Name) + "\n" +
			to_string(UI_Visual_ESP_Drops) + "\n" +
			to_string(UI_Visual_ESP_OutFOV) + "\n" +
			to_string(UI_Visual_ESP_OutFOV_Size) + "\n" +
			to_string(UI_Visual_ESP_OutFOV_Radius) + "\n" +
			to_string(UI_Visual_ESP_CustomColor) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.r) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.g) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.b) + "\n" +
			to_string(UI_Visual_ESP_CustomColor_Color.a) + "\n" +
			to_string(UI_Visual_ESP_DrawDelay) + "\n" +
			to_string(UI_Visual_Radar) + "\n" +
			to_string(UI_Visual_Radar_FollowAngle) + "\n" +
			to_string(UI_Visual_Radar_Range) + "\n" +
			to_string(UI_Visual_Radar_Size) + "\n" +
			to_string(UI_Visual_Radar_Alpha) + "\n" +
			to_string(UI_Visual_Radar_Pos.x) + "\n" +
			to_string(UI_Visual_Radar_Pos.y) + "\n" +
			to_string(UI_Misc_BunnyHop) + "\n" +
			to_string(UI_Misc_HitSound) + "\n" +
			to_string(UI_Misc_HitSound_Tone) + "\n" +
			to_string(UI_Misc_HitSound_Length) + "\n" +
			to_string(UI_Visual_HitMark) + "\n" +
			to_string(UI_Visual_HitMark_Damage) + "\n" +
			to_string(UI_Visual_HitMark_Range) + "\n" +
			to_string(UI_Visual_HitMark_Length) + "\n" +
			to_string(UI_Misc_AutoKnife) + "\n" +
			to_string(UI_Misc_AutoTaser) + "\n" +
			to_string(UI_Misc_AutoKnife_Key) + "\n" +
			to_string(UI_Misc_AutoTaser_Key) + "\n" +
			to_string(UI_Misc_Watermark) + "\n" +
			to_string(UI_Misc_SniperCrosshair) + "\n" +
			to_string(UI_Misc_TeamCheck) + "\n" +
			to_string(UI_Misc_LockGameWindow) + "\n" +
			to_string(UI_Debug_ShowDebugWindow) + "\n" +
			to_string(UI_Misc_Sonar) + "\n" +
			to_string(UI_Misc_Sonar_Key) + "\n" +
			to_string(UI_Misc_Sonar_Range_Far) + "\n" +
			to_string(UI_Misc_Sonar_Range_Near) + "\n" +
			to_string(UI_Misc_SelectedConfig) + "\n" +
			to_string(UI_Setting_MenuKey) + "\n" +
			to_string(UI_Setting_CustomColor) + "\n" +
			to_string(UI_Setting_MainColor.r) + "\n" +
			to_string(UI_Setting_MainColor.g) + "\n" +
			to_string(UI_Setting_MainColor.b) + "\n" +
			to_string(UI_Setting_MainColor.a) + "\n" +
			to_string(UI_Visual_HitMark_Color.r) + "\n" +
			to_string(UI_Visual_HitMark_Color.g) + "\n" +
			to_string(UI_Visual_HitMark_Color.b) + "\n" +
			to_string(UI_Visual_HitMark_Thickness) + "\n" +
			to_string(UI_Legit_Triggerbot_ShootWhenAccurate) + "\n" +
			to_string(UI_Misc_AntiAFKKick) + "\n" +
			to_string(UI_Legit_MagnetAim) + "\n" +
			to_string(UI_Legit_MagnetAim_Smooth) + "\n" +
			to_string(UI_Legit_AdaptiveAimbot_InitialSmooth) + "\n" +
			to_string(UI_Misc_SniperCrosshair_Size) + "\n" +
			to_string(UI_Spoof_Spoof) + "\n" +
			to_string(UI_Spoof_AimbotTeam) + "\n" +
			to_string(UI_Spoof_AimbotTeam_Key) + "\n" +
			to_string(UI_Spoof_AimbotTeam_Smooth) + "\n" +
			to_string(UI_Spoof_IncreaseRecoil) + "\n" +
			to_string(UI_Spoof_IncreaseRecoil_Value) + "\n" +
			to_string(UI_Spoof_DropC4) + "\n" +
			to_string(UI_Spoof_FakeAntiAim) + "\n" +
			to_string(UI_Spoof_FakeAntiAim_Key) + "\n" +
			to_string(UI_Spoof_KillDropSniper) + "\n" +
			to_string(UI_Setting_MenuAnimation) + "\n" +
			to_string(UI_Visual_HitMark_KillEffect) + "\n" +
			to_string(UI_Visual_HitMark_KillEffect_Quantity) + "\n" +
			to_string(UI_Visual_HitMark_KillEffect_Range) + "\n" +
			to_string(UI_Visual_ESP_Skeleton_Thickness) + "\n" +
			to_string(UI_Misc_ByPassOBS) + "\n" +
			to_string(UI_Misc_SavePerformance) + "\n" +
			to_string(UI_Legit_Aimbot_AutoScope) + "\n" +
			to_string(UI_Misc_NightMode) + "\n" +
			to_string(UI_Misc_NightMode_Alpha) + "\n" +
			to_string(UI_Spoof_LearnPlayer) + "\n" +
			to_string(UI_Spoof_LearnPlayer_Key) + "\n" +
			to_string(UI_Misc_AutoPeek) + "\n" +
			to_string(UI_Misc_AutoPeek_Key) + "\n" +
			to_string(UI_Spoof_FakeRageBot) + "\n" +
			to_string(UI_Spoof_FakeRageBot_Key) + "\n" +
			to_string(UI_Spoof_FakeRageBot_Target) + "\n" +
			to_string(UI_Misc_QuickStop) + "\n" +
			UI_Setting_MenuFont + "\n" +
			to_string(UI_Setting_MenuFontSize) + "\n" +
			to_string(UI_Misc_AutoKillCeasefire) + "\n" +
			to_string(UI_Misc_CursorESP) + "\n" +
			to_string(UI_Misc_CursorESP_Key) + "\n" +
			to_string(UI_Legit_Armory_HitSiteParser) + "\n" +
			to_string(UI_Visual_ESP_DrawAlpha) + "\n" +
			to_string(UI_Legit_Armory_BodyAim_SHOTGUN) + "\n" +
			to_string(UI_Legit_Armory_Range_SHOTGUN) + "\n" +
			to_string(UI_Legit_Armory_Smooth_SHOTGUN) + "\n" +
			to_string(UI_Legit_Armory_TriggerDistance_SHOTGUN) + "\n" +
			to_string(UI_Legit_MagnetAim_Range) + "\n" +
			to_string(UI_Legit_Backtracking_MinimumTime) + "\n" +
			to_string(UI_Legit_RemoveRecoil_Sensitive) + "\n"
		);
	}
	void LoadCloudConfig(string FileName = "", string NormalURL = "https://github.com/Coslly/Rensen/blob/main/Cloud%20Files/") noexcept//加载Github云参数
	{
		System::URL_READ URL_CONFIG = { "Cache_CloudConfig" };
		if (URL_CONFIG.StoreMem(NormalURL + FileName + (string)".cfg?raw=true"))
		{
			UI_Legit_Aimbot = Variable::string_int_(URL_CONFIG.Read(1));
			UI_Legit_Aimbot_Key = Variable::string_int_(URL_CONFIG.Read(2));
			UI_Legit_Aimbot_JudgingWall = Variable::string_int_(URL_CONFIG.Read(3));
			UI_Legit_Aimbot_RemoveRecoil = Variable::string_int_(URL_CONFIG.Read(4));
			UI_Legit_Aimbot_TriggerOnAim = Variable::string_int_(URL_CONFIG.Read(5));
			UI_Legit_Aimbot_AutoShoot = Variable::string_int_(URL_CONFIG.Read(6));
			UI_Legit_Aimbot_AutoStop = Variable::string_int_(URL_CONFIG.Read(7));
			UI_Legit_Aimbot_AutoShootDelay = Variable::string_int_(URL_CONFIG.Read(8));
			UI_Legit_AdaptiveAimbot = Variable::string_int_(URL_CONFIG.Read(9));
			UI_Legit_Armory_ShowAimbotRange = Variable::string_int_(URL_CONFIG.Read(10));
			UI_Legit_Armory_BodyAim_PISTOL = Variable::string_int_(URL_CONFIG.Read(11));
			UI_Legit_Armory_Range_PISTOL = Variable::string_int_(URL_CONFIG.Read(12));
			UI_Legit_Armory_Smooth_PISTOL = Variable::string_float_(URL_CONFIG.Read(13));
			UI_Legit_Armory_BodyAim_RIFLE = Variable::string_int_(URL_CONFIG.Read(14));
			UI_Legit_Armory_Range_RIFLE = Variable::string_int_(URL_CONFIG.Read(15));
			UI_Legit_Armory_Smooth_RIFLE = Variable::string_float_(URL_CONFIG.Read(16));
			UI_Legit_Armory_BodyAim_SNIPER = Variable::string_int_(URL_CONFIG.Read(17));
			UI_Legit_Armory_Range_SNIPER = Variable::string_int_(URL_CONFIG.Read(18));
			UI_Legit_Armory_Smooth_SNIPER = Variable::string_float_(URL_CONFIG.Read(19));
			UI_Legit_Triggerbot = Variable::string_int_(URL_CONFIG.Read(20));
			UI_Legit_Triggerbot_Key = Variable::string_int_(URL_CONFIG.Read(21));
			UI_Legit_Triggerbot_AnyTarget = Variable::string_int_(URL_CONFIG.Read(22));
			UI_Legit_Triggerbot_ShootDelay = Variable::string_int_(URL_CONFIG.Read(23));
			UI_Legit_Triggerbot_ShootDuration = Variable::string_int_(URL_CONFIG.Read(24));
			UI_Legit_PreciseAim = Variable::string_int_(URL_CONFIG.Read(25));
			UI_Legit_PreciseAim_DefaultSensitivity = Variable::string_float_(URL_CONFIG.Read(26));
			UI_Legit_PreciseAim_EnableSensitivity = Variable::string_float_(URL_CONFIG.Read(27));
			UI_Legit_RemoveRecoil = Variable::string_int_(URL_CONFIG.Read(28));
			UI_Legit_RemoveRecoil_LateralRepair = Variable::string_int_(URL_CONFIG.Read(29));
			UI_Legit_RemoveRecoil_StartBullet = Variable::string_int_(URL_CONFIG.Read(30));
			UI_Legit_Backtracking = Variable::string_int_(URL_CONFIG.Read(31));
			UI_Legit_Backtracking_MaximumTime = Variable::string_int_(URL_CONFIG.Read(32));
			UI_Visual_ESP = Variable::string_int_(URL_CONFIG.Read(33));
			UI_Visual_ESP_Key = Variable::string_int_(URL_CONFIG.Read(34));
			UI_Visual_ESP_Box = Variable::string_int_(URL_CONFIG.Read(35));
			UI_Visual_ESP_Health = Variable::string_int_(URL_CONFIG.Read(36));
			UI_Visual_ESP_ActiveWeapon = Variable::string_int_(URL_CONFIG.Read(37));
			UI_Visual_ESP_Line = Variable::string_int_(URL_CONFIG.Read(38));
			UI_Visual_ESP_Skeleton = Variable::string_int_(URL_CONFIG.Read(39));
			UI_Visual_ESP_HeadDot = Variable::string_int_(URL_CONFIG.Read(40));
			UI_Visual_ESP_State = Variable::string_int_(URL_CONFIG.Read(41));
			UI_Visual_ESP_Name = Variable::string_int_(URL_CONFIG.Read(42));
			UI_Visual_ESP_Drops = Variable::string_int_(URL_CONFIG.Read(43));
			UI_Visual_ESP_OutFOV = Variable::string_int_(URL_CONFIG.Read(44));
			UI_Visual_ESP_OutFOV_Size = Variable::string_int_(URL_CONFIG.Read(45));
			UI_Visual_ESP_OutFOV_Radius = Variable::string_int_(URL_CONFIG.Read(46));
			UI_Visual_ESP_CustomColor = Variable::string_int_(URL_CONFIG.Read(47));
			UI_Visual_ESP_CustomColor_Color = { Variable::string_int_(URL_CONFIG.Read(48)),Variable::string_int_(URL_CONFIG.Read(49)),Variable::string_int_(URL_CONFIG.Read(50)),Variable::string_int_(URL_CONFIG.Read(51)) };
			UI_Visual_ESP_DrawDelay = Variable::string_int_(URL_CONFIG.Read(52));
			UI_Visual_Radar = Variable::string_int_(URL_CONFIG.Read(53));
			UI_Visual_Radar_FollowAngle = Variable::string_int_(URL_CONFIG.Read(54));
			UI_Visual_Radar_Range = Variable::string_float_(URL_CONFIG.Read(55));
			UI_Visual_Radar_Size = Variable::string_int_(URL_CONFIG.Read(56));
			UI_Visual_Radar_Alpha = Variable::string_int_(URL_CONFIG.Read(57));
			UI_Visual_Radar_Pos = { Variable::string_int_(URL_CONFIG.Read(58)), Variable::string_int_(URL_CONFIG.Read(59)) };
			UI_Misc_BunnyHop = Variable::string_int_(URL_CONFIG.Read(60));
			UI_Misc_HitSound = Variable::string_int_(URL_CONFIG.Read(61));
			UI_Misc_HitSound_Tone = Variable::string_int_(URL_CONFIG.Read(62));
			UI_Misc_HitSound_Length = Variable::string_int_(URL_CONFIG.Read(63));
			UI_Visual_HitMark = Variable::string_int_(URL_CONFIG.Read(64));
			UI_Visual_HitMark_Damage = Variable::string_int_(URL_CONFIG.Read(65));
			UI_Visual_HitMark_Range = Variable::string_int_(URL_CONFIG.Read(66));
			UI_Visual_HitMark_Length = Variable::string_int_(URL_CONFIG.Read(67));
			UI_Misc_AutoKnife = Variable::string_int_(URL_CONFIG.Read(68));
			UI_Misc_AutoTaser = Variable::string_int_(URL_CONFIG.Read(69));
			UI_Misc_AutoKnife_Key = Variable::string_int_(URL_CONFIG.Read(70));
			UI_Misc_AutoTaser_Key = Variable::string_int_(URL_CONFIG.Read(71));
			UI_Misc_Watermark = Variable::string_int_(URL_CONFIG.Read(72));
			UI_Misc_SniperCrosshair = Variable::string_int_(URL_CONFIG.Read(73));
			UI_Misc_TeamCheck = Variable::string_int_(URL_CONFIG.Read(74));
			UI_Misc_LockGameWindow = Variable::string_int_(URL_CONFIG.Read(75));
			UI_Debug_ShowDebugWindow = Variable::string_int_(URL_CONFIG.Read(76));
			UI_Misc_Sonar = Variable::string_int_(URL_CONFIG.Read(77));
			UI_Misc_Sonar_Key = Variable::string_int_(URL_CONFIG.Read(78));
			UI_Misc_Sonar_Range_Far = Variable::string_int_(URL_CONFIG.Read(79));
			UI_Misc_Sonar_Range_Near = Variable::string_int_(URL_CONFIG.Read(80));
			UI_Misc_SelectedConfig = Variable::string_int_(URL_CONFIG.Read(81));
			UI_Setting_MenuKey = Variable::string_int_(URL_CONFIG.Read(82));
			UI_Setting_CustomColor = Variable::string_int_(URL_CONFIG.Read(83));
			UI_Setting_MainColor = { Variable::string_int_(URL_CONFIG.Read(84)),Variable::string_int_(URL_CONFIG.Read(85)),Variable::string_int_(URL_CONFIG.Read(86)),Variable::string_int_(URL_CONFIG.Read(87)) };
			UI_Visual_HitMark_Color = { Variable::string_int_(URL_CONFIG.Read(88)) ,Variable::string_int_(URL_CONFIG.Read(89)) ,Variable::string_int_(URL_CONFIG.Read(90)) };
			UI_Visual_HitMark_Thickness = Variable::string_int_(URL_CONFIG.Read(91));
			UI_Legit_Triggerbot_ShootWhenAccurate = Variable::string_int_(URL_CONFIG.Read(92));
			UI_Misc_AntiAFKKick = Variable::string_int_(URL_CONFIG.Read(93));
			UI_Legit_MagnetAim = Variable::string_int_(URL_CONFIG.Read(94));
			UI_Legit_MagnetAim_Smooth = Variable::string_float_(URL_CONFIG.Read(95));
			UI_Legit_AdaptiveAimbot_InitialSmooth = Variable::string_float_(URL_CONFIG.Read(96));
			UI_Misc_SniperCrosshair_Size = Variable::string_int_(URL_CONFIG.Read(97));
			UI_Spoof_Spoof = Variable::string_int_(URL_CONFIG.Read(98));
			UI_Spoof_AimbotTeam = Variable::string_int_(URL_CONFIG.Read(99));
			UI_Spoof_AimbotTeam_Key = Variable::string_int_(URL_CONFIG.Read(100));
			UI_Spoof_AimbotTeam_Smooth = Variable::string_float_(URL_CONFIG.Read(101));
			UI_Spoof_IncreaseRecoil = Variable::string_int_(URL_CONFIG.Read(102));
			UI_Spoof_IncreaseRecoil_Value = Variable::string_int_(URL_CONFIG.Read(103));
			UI_Spoof_DropC4 = Variable::string_int_(URL_CONFIG.Read(104));
			UI_Spoof_FakeAntiAim = Variable::string_int_(URL_CONFIG.Read(105));
			UI_Spoof_FakeAntiAim_Key = Variable::string_int_(URL_CONFIG.Read(106));
			UI_Spoof_KillDropSniper = Variable::string_int_(URL_CONFIG.Read(107));
			UI_Setting_MenuAnimation = Variable::string_float_(URL_CONFIG.Read(108));
			UI_Visual_HitMark_KillEffect = Variable::string_int_(URL_CONFIG.Read(109));
			UI_Visual_HitMark_KillEffect_Quantity = Variable::string_int_(URL_CONFIG.Read(110));
			UI_Visual_HitMark_KillEffect_Range = Variable::string_int_(URL_CONFIG.Read(111));
			UI_Visual_ESP_Skeleton_Thickness = Variable::string_int_(URL_CONFIG.Read(112));
			UI_Misc_ByPassOBS = Variable::string_int_(URL_CONFIG.Read(113));
			UI_Misc_SavePerformance = Variable::string_int_(URL_CONFIG.Read(114));
			UI_Legit_Aimbot_AutoScope = Variable::string_int_(URL_CONFIG.Read(115));
			UI_Misc_NightMode = Variable::string_int_(URL_CONFIG.Read(116));
			UI_Misc_NightMode_Alpha = Variable::string_int_(URL_CONFIG.Read(117));
			UI_Spoof_LearnPlayer = Variable::string_int_(URL_CONFIG.Read(118));
			UI_Spoof_LearnPlayer_Key = Variable::string_int_(URL_CONFIG.Read(119));
			UI_Misc_AutoPeek = Variable::string_int_(URL_CONFIG.Read(120));
			UI_Misc_AutoPeek_Key = Variable::string_int_(URL_CONFIG.Read(121));
			UI_Spoof_FakeRageBot = Variable::string_int_(URL_CONFIG.Read(122));
			UI_Spoof_FakeRageBot_Key = Variable::string_int_(URL_CONFIG.Read(123));
			UI_Spoof_FakeRageBot_Target = Variable::string_int_(URL_CONFIG.Read(124));
			UI_Misc_QuickStop = Variable::string_int_(URL_CONFIG.Read(125));
			UI_Setting_MenuFont = URL_CONFIG.Read(126);
			UI_Setting_MenuFontSize = Variable::string_int_(URL_CONFIG.Read(127));
			UI_Misc_AutoKillCeasefire = Variable::string_int_(URL_CONFIG.Read(128));
			UI_Misc_CursorESP = Variable::string_int_(URL_CONFIG.Read(129));
			UI_Misc_CursorESP_Key = Variable::string_int_(URL_CONFIG.Read(130));
			UI_Legit_Armory_HitSiteParser = Variable::string_int_(URL_CONFIG.Read(131));
			UI_Visual_ESP_DrawAlpha = Variable::string_int_(URL_CONFIG.Read(132));
			UI_Legit_Armory_BodyAim_SHOTGUN = Variable::string_int_(URL_CONFIG.Read(133));
			UI_Legit_Armory_Range_SHOTGUN = Variable::string_int_(URL_CONFIG.Read(134));
			UI_Legit_Armory_Smooth_SHOTGUN = Variable::string_float_(URL_CONFIG.Read(135));
			UI_Legit_Armory_TriggerDistance_SHOTGUN = Variable::string_int_(URL_CONFIG.Read(136));
			UI_Legit_MagnetAim_Range = Variable::string_int_(URL_CONFIG.Read(137));
			UI_Legit_Backtracking_MinimumTime = Variable::string_int_(URL_CONFIG.Read(138));
			UI_Legit_RemoveRecoil_Sensitive = Variable::string_int_(URL_CONFIG.Read(139));
			URL_CONFIG.Release();
		}
	}
	//----------------------------------------------------------------------------------------------
	namespace Debug_Control_Var//测试调试用的控件变量 (按钮 滑条 选择框 按键选择框 控制台控件)
	{
		int SelectPlayer; string SystemCommand; BOOL SendSystemCommand, ClearCommand;
		BOOL Checkbox_1, Checkbox_2;
		int KeySelector_1, KeySelector_2, Slider_1;
		float Slider_2;
		BOOL Button_1, Button_2;
		int Checkbox_Quantity = 1; vector<BOOL> Checkbox_Value(100);
	}
}
using namespace Control_Var;
void Thread_Menu() noexcept//菜单线程 (提供给使用者丰富的自定义选项)
{
	System::Log("Load Thread: Thread_Menu()");
	GUI_VAR.Window_Create(1200, 1000, "Rensen", true);//创建置顶GUI绘制窗口
	while (true)
	{
		GUI_VAR.Window_SetTitle(System::Rand_String(10));//随机菜单窗口标题
		Window::Set_LimitWindowShow(GUI_VAR.Window_HWND(), UI_Misc_ByPassOBS);//绕过OBS
		static int UI_Panel = 0;//大区块选择
		static Variable::Vector2 GUI_WindowSize = { 0,0 };//窗体大小(用于开关动画)
		if (!Menu_Open)GUI_WindowSize = { 0,0 };//关闭窗体时
		GUI_VAR.Window_SetSize(Variable::Animation_Vec2<class CLASS_MenuState_Animation_>(GUI_WindowSize, UI_Setting_MenuAnimation));//菜单窗口大小动画 (弹出, 关闭)
		if (!GUI_VAR.Window_Move() && Menu_Open)//不在移动窗口时绘制GUI
		{
			if (UI_Setting_CustomColor)//自定义颜色(单色)
			{
				GUI_VAR.Global_Set_EasyGUI_Color(UI_Setting_MainColor);//设置主题颜色
				GUI_VAR.GUI_BackGround(4);//自定义颜色背景主题
			}
			else GUI_VAR.GUI_BackGround(3);//默认(彩虹)
			GUI_VAR.GUI_Block(20, 20, 40, "", 110); GUI_VAR.In_DrawString(37, 35, "Rensen", GUI_VAR.Global_Get_EasyGUI_Color().Min_Bri(200), "Verdana", 25);
			GUI_VAR.GUI_Block_Panel(20, 70, 110, GUI_VAR.Window_GetSize().y - 90, "", { "Legit","Visual","Misc","Infolist","Setting","Attach" }, UI_Panel, 25);
			if (UI_Panel == 0)//Legit
			{
				const auto Block_Aimbot = GUI_VAR.GUI_Block(150, 30, 340, "Aim bot");
				GUI_VAR.GUI_Checkbox(Block_Aimbot, 1, "Enabled", UI_Legit_Aimbot);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Aimbot_1>(Block_Aimbot, 1, UI_Legit_Aimbot_Key);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 2, "Judging wall", UI_Legit_Aimbot_JudgingWall);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 3, "Remove recoil", UI_Legit_Aimbot_RemoveRecoil);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 4, "Trigger on aiming", UI_Legit_Aimbot_TriggerOnAim);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 5, "Auto shoot", UI_Legit_Aimbot_AutoShoot, { 255,150,150 });
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 40,Block_Aimbot.y }, 6, "Auto stop", UI_Legit_Aimbot_AutoStop, { 255,150,150 });
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 40,Block_Aimbot.y }, 7, "Auto scope", UI_Legit_Aimbot_AutoScope, { 255,150,150 });
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Aimbot_2>({ Block_Aimbot.x + 20,Block_Aimbot.y }, 8, "Auto shoot delay", 0, 500, UI_Legit_Aimbot_AutoShootDelay, "ms", { 255,150,150 });
				GUI_VAR.GUI_Checkbox(Block_Aimbot, 9, "Adaptive aimbot", UI_Legit_AdaptiveAimbot, { 200,200,150 });
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Aimbot_3>(Block_Aimbot, 10, "Initial smooth", 0, 20, UI_Legit_AdaptiveAimbot_InitialSmooth, "", { 200,200,150 });
				const auto Block_Armory = GUI_VAR.GUI_Block(150, 390, 490, "Armory");
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 1, "Show range", UI_Legit_Armory_ShowAimbotRange);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 2, "Hit site parser", UI_Legit_Armory_HitSiteParser);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 3, "PISTOL Body aim (else head)", UI_Legit_Armory_BodyAim_PISTOL);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Armory_1>({ Block_Armory.x - 10,Block_Armory.y }, 4, "PISTOL range", 0, 100, UI_Legit_Armory_Range_PISTOL, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Armory_2>({ Block_Armory.x - 10,Block_Armory.y }, 5, "PISTOL smooth", 0, 40, UI_Legit_Armory_Smooth_PISTOL);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 6, "RIFLE Body aim (else head)", UI_Legit_Armory_BodyAim_RIFLE);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Armory_3>({ Block_Armory.x - 10,Block_Armory.y }, 7, "RIFLE range", 0, 100, UI_Legit_Armory_Range_RIFLE, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Armory_4>({ Block_Armory.x - 10,Block_Armory.y }, 8, "RIFLE smooth", 0, 40, UI_Legit_Armory_Smooth_RIFLE);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 9, "SNIPER Body aim (else head)", UI_Legit_Armory_BodyAim_SNIPER);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Armory_5>({ Block_Armory.x - 10,Block_Armory.y }, 10, "SNIPER range", 0, 100, UI_Legit_Armory_Range_SNIPER, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Armory_6>({ Block_Armory.x - 10,Block_Armory.y }, 11, "SNIPER smooth", 0, 40, UI_Legit_Armory_Smooth_SNIPER);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 12, "SHOTGUN Body aim (else head)", UI_Legit_Armory_BodyAim_SHOTGUN);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Armory_7>({ Block_Armory.x - 10,Block_Armory.y }, 13, "SHOTGUN range", 0, 100, UI_Legit_Armory_Range_SHOTGUN, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Armory_8>({ Block_Armory.x - 10,Block_Armory.y }, 14, "SHOTGUN smooth", 0, 40, UI_Legit_Armory_Smooth_SHOTGUN);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Armory_9>({ Block_Armory.x - 10,Block_Armory.y }, 15, "SHOTGUN trigger distance", 100, 2000, UI_Legit_Armory_TriggerDistance_SHOTGUN);
				const auto Block_Triggerbot = GUI_VAR.GUI_Block(580, 30, 190, "Trigger bot");
				GUI_VAR.GUI_Checkbox(Block_Triggerbot, 1, "Enabled", UI_Legit_Triggerbot);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Triggerbot_1>(Block_Triggerbot, 1, UI_Legit_Triggerbot_Key);
				GUI_VAR.GUI_Checkbox({ Block_Triggerbot.x + 20,Block_Triggerbot.y }, 2, "Any target", UI_Legit_Triggerbot_AnyTarget);
				GUI_VAR.GUI_Checkbox({ Block_Triggerbot.x + 20,Block_Triggerbot.y }, 3, "Shoot when accurate", UI_Legit_Triggerbot_ShootWhenAccurate);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Triggerbot_2>(Block_Triggerbot, 4, "Shoot delay", 1, 500, UI_Legit_Triggerbot_ShootDelay, "ms");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Triggerbot_3>(Block_Triggerbot, 5, "Shoot duration", 1, 1000, UI_Legit_Triggerbot_ShootDuration, "ms");
				const auto Block_PreciseAim = GUI_VAR.GUI_Block(580, 240, 130, "Precise aim");
				GUI_VAR.GUI_Checkbox(Block_PreciseAim, 1, "Enabled", UI_Legit_PreciseAim);
				GUI_VAR.GUI_Slider<float, class CLASS_Block_PreciseAim_1>(Block_PreciseAim, 2, "Default sensitivity", 0, 0.022, UI_Legit_PreciseAim_DefaultSensitivity);
				GUI_VAR.GUI_Slider<float, class CLASS_Block_PreciseAim_2>(Block_PreciseAim, 3, "Enable sensitivity", 0, 0.015, UI_Legit_PreciseAim_EnableSensitivity);
				const auto Block_RemoveRecoil = GUI_VAR.GUI_Block(580, 390, 160, "Remove recoil");
				GUI_VAR.GUI_Checkbox(Block_RemoveRecoil, 1, "Enabled", UI_Legit_RemoveRecoil);
				GUI_VAR.GUI_Checkbox({ Block_RemoveRecoil.x + 20,Block_RemoveRecoil.y }, 2, "Lateral repair", UI_Legit_RemoveRecoil_LateralRepair);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_RemoveRecoil_1>(Block_RemoveRecoil, 3, "Start bullet", 1, 10, UI_Legit_RemoveRecoil_StartBullet);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_RemoveRecoil_2>(Block_RemoveRecoil, 4, "Sensitive", 0, 100, UI_Legit_RemoveRecoil_Sensitive, "%");
				const auto Block_MagnetAim = GUI_VAR.GUI_Block(580, 570, 130, "Magnet aim");
				GUI_VAR.GUI_Checkbox(Block_MagnetAim, 1, "Enabled", UI_Legit_MagnetAim);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_MagnetAim_1>(Block_MagnetAim, 2, "Range", 0, 100, UI_Legit_MagnetAim_Range, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Block_MagnetAim_2>(Block_MagnetAim, 3, "Smooth", 0.5, 6.6666, UI_Legit_MagnetAim_Smooth);
				const auto Block_Backtracking = GUI_VAR.GUI_Block(580, 720, 130, "Back tracking");
				GUI_VAR.GUI_Checkbox(Block_Backtracking, 1, "Enabled", UI_Legit_Backtracking);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Backtracking_1>(Block_Backtracking, 2, "Minimum time", 0, 500, UI_Legit_Backtracking_MinimumTime, "ms");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Backtracking_2>(Block_Backtracking, 3, "Maximum time", UI_Legit_Backtracking_MinimumTime, 1000, UI_Legit_Backtracking_MaximumTime, "ms");
				GUI_VAR.GUI_Tips(Block_Aimbot, 1, "Help you quickly aim at the target.");
				GUI_VAR.GUI_Tips({ Block_Aimbot.x + 10,Block_Aimbot.y }, 5, "Prefer Ragebot.", 0, { 255,150,150 });
				GUI_VAR.GUI_Tips(Block_Aimbot, 9, "More biological than normal aimbot.", 0, { 200,200,150 });
				GUI_VAR.GUI_Tips(Block_Triggerbot, 1, "Shoot when aiming at the enemy.");
				GUI_VAR.GUI_Tips(Block_PreciseAim, 1, "Reduce the sensitivity of the reticle when aiming at the enemy.");
				GUI_VAR.GUI_Tips({ Block_RemoveRecoil.x + 10,Block_RemoveRecoil.y }, 2, "Operations that only return landscape.");
				GUI_VAR.GUI_Tips({ Block_RemoveRecoil.x + 10,Block_RemoveRecoil.y }, 4, "Corresponding game sensitivity value.");
				GUI_VAR.GUI_Tips(Block_MagnetAim, 1, "Slow aiming without triggering key conditions. (Hard to see)");
				GUI_VAR.GUI_Tips(Block_Backtracking, 1, "Take advantage of network latency to have a bigger hitbox.");
				GUI_WindowSize = { 1010,910 };
			}
			else if (UI_Panel == 1)//Visual
			{
				const auto Block_ESP = GUI_VAR.GUI_Block(150, 30, 550, "Extra sensory perception");
				GUI_VAR.GUI_Checkbox(Block_ESP, 1, "Enabled", UI_Visual_ESP);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_ESP_1>(Block_ESP, 1, UI_Visual_ESP_Key);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 2, "Box", UI_Visual_ESP_Box);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 3, "Health bar", UI_Visual_ESP_Health);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 4, "Weapon text", UI_Visual_ESP_ActiveWeapon);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 5, "Line", UI_Visual_ESP_Line);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 6, "Skeleton", UI_Visual_ESP_Skeleton);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_ESP_2>(Block_ESP, 7, "Thickness", 1, 5, UI_Visual_ESP_Skeleton_Thickness, "px");
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 8, "Head dot", UI_Visual_ESP_HeadDot);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 9, "State", UI_Visual_ESP_State);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 10, "Name", UI_Visual_ESP_Name);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 11, "Drops", UI_Visual_ESP_Drops);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 12, "Out of FOV arrow", UI_Visual_ESP_OutFOV);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_ESP_3>(Block_ESP, 13, "Size", 20, 70, UI_Visual_ESP_OutFOV_Size, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_ESP_4>(Block_ESP, 14, "Radius", 0, 100, UI_Visual_ESP_OutFOV_Radius, "%");
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 15, "Custom color", UI_Visual_ESP_CustomColor);
				GUI_VAR.GUI_ColorSelector(Block_ESP, 15, UI_Visual_ESP_CustomColor_Color);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_ESP_5>(Block_ESP, 16, "Draw alpha", 20, 255, UI_Visual_ESP_DrawAlpha);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_ESP_6>(Block_ESP, 17, "Draw delay", 1, 30, UI_Visual_ESP_DrawDelay, "ms");
				const auto Block_Hitmark = GUI_VAR.GUI_Block(580, 30, 280, "Hit mark");
				GUI_VAR.GUI_Checkbox(Block_Hitmark, 1, "Enabled", UI_Visual_HitMark);
				GUI_VAR.GUI_ColorSelector(Block_Hitmark, 1, UI_Visual_HitMark_Color);
				GUI_VAR.GUI_Checkbox({ Block_Hitmark.x + 20,Block_Hitmark.y }, 2, "Show damage", UI_Visual_HitMark_Damage);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Hitmark_1>(Block_Hitmark, 3, "Range", 3, 100, UI_Visual_HitMark_Range, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Hitmark_2>(Block_Hitmark, 4, "Length", 3, 100, UI_Visual_HitMark_Length, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Hitmark_3>(Block_Hitmark, 5, "Thickness", 1, 10, UI_Visual_HitMark_Thickness, "px");
				GUI_VAR.GUI_Checkbox({ Block_Hitmark.x + 20,Block_Hitmark.y }, 6, "Lightning effect", UI_Visual_HitMark_KillEffect);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Hitmark_4>(Block_Hitmark, 7, "Quantity", 10, 500, UI_Visual_HitMark_KillEffect_Quantity);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Hitmark_5>(Block_Hitmark, 8, "Range", 10, 500, UI_Visual_HitMark_KillEffect_Range);
				const auto Block_Radar = GUI_VAR.GUI_Block(580, 330, 190, "Radar");
				GUI_VAR.GUI_Checkbox(Block_Radar, 1, "Enabled", UI_Visual_Radar);
				GUI_VAR.GUI_Button_Small({ Block_Radar.x + 10,Block_Radar.y }, 2, UI_Visual_Radar_Show);
				GUI_VAR.GUI_Checkbox({ Block_Radar.x + 20,Block_Radar.y }, 2, "Follow angle", UI_Visual_Radar_FollowAngle);
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Radar_1>(Block_Radar, 3, "Range", 0.2, 40, UI_Visual_Radar_Range);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Radar_2>(Block_Radar, 4, "Size", 150, 500, UI_Visual_Radar_Size, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Radar_3>(Block_Radar, 5, "Alpha", 0, 255, UI_Visual_Radar_Alpha);
				GUI_VAR.GUI_Tips(Block_ESP, 1, "Learn enemy coordinates through walls. (Full screen cannot be used)");
				GUI_VAR.GUI_Tips(Block_Hitmark, 1, "Effect that triggers when hitting the player.");
				GUI_VAR.GUI_Tips(Block_Radar, 1, "Exterior window radar. (Full screen cannot be used)");
				GUI_WindowSize = { 1010,610 };
			}
			else if (UI_Panel == 2)//Misc
			{
				const auto Block_Misc = GUI_VAR.GUI_Block(150, 30, 720, "Miscellaneous");
				GUI_VAR.GUI_Checkbox(Block_Misc, 1, "Bunny hop", UI_Misc_BunnyHop);
				GUI_VAR.GUI_Checkbox(Block_Misc, 2, "Hit sound", UI_Misc_HitSound);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_1>(Block_Misc, 3, "Tone", 10, 5000, UI_Misc_HitSound_Tone);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_2>(Block_Misc, 4, "Length", 10, 80, UI_Misc_HitSound_Length);
				GUI_VAR.GUI_Checkbox(Block_Misc, 5, "Sonar", UI_Misc_Sonar);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Misc_3>(Block_Misc, 5, UI_Misc_Sonar_Key);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_4>(Block_Misc, 6, "Range far", 500, 1000, UI_Misc_Sonar_Range_Far);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_5>(Block_Misc, 7, "Range near", 0, 500, UI_Misc_Sonar_Range_Near);
				GUI_VAR.GUI_Checkbox(Block_Misc, 8, "Knife bot", UI_Misc_AutoKnife);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Misc_6>(Block_Misc, 8, UI_Misc_AutoKnife_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 9, "Taser bot", UI_Misc_AutoTaser);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Misc_7>(Block_Misc, 9, UI_Misc_AutoTaser_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 10, "Water mark", UI_Misc_Watermark);
				GUI_VAR.GUI_Checkbox(Block_Misc, 11, "Sniper crosshair", UI_Misc_SniperCrosshair);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_8>(Block_Misc, 12, "Size", 10, 60, UI_Misc_SniperCrosshair_Size, "px");
				GUI_VAR.GUI_Checkbox(Block_Misc, 13, "Anti AFK kick", UI_Misc_AntiAFKKick);
				GUI_VAR.GUI_Checkbox(Block_Misc, 14, "Lock game window", UI_Misc_LockGameWindow);
				GUI_VAR.GUI_Checkbox(Block_Misc, 15, "Hide from OBS", UI_Misc_ByPassOBS);
				GUI_VAR.GUI_Checkbox(Block_Misc, 16, "Save performance", UI_Misc_SavePerformance, { 255,150,150 });
				GUI_VAR.GUI_Checkbox(Block_Misc, 17, "Night mode", UI_Misc_NightMode);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_9>(Block_Misc, 18, "Alpha", 50, 180, UI_Misc_NightMode_Alpha);
				GUI_VAR.GUI_Checkbox(Block_Misc, 19, "Auto peek", UI_Misc_AutoPeek);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Misc_10>(Block_Misc, 19, UI_Misc_AutoPeek_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 20, "Quick stop", UI_Misc_QuickStop);
				GUI_VAR.GUI_Checkbox(Block_Misc, 21, "Auto kill ceasefire", UI_Misc_AutoKillCeasefire);
				GUI_VAR.GUI_Checkbox(Block_Misc, 22, "Cursor ESP", UI_Misc_CursorESP);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Misc_11>(Block_Misc, 22, UI_Misc_CursorESP_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 23, "Global team check", UI_Misc_TeamCheck, { 200,200,150 });
				const auto Block_Resolution = GUI_VAR.GUI_Block(580, 30, 160, "Screen resolution");
				GUI_VAR.GUI_Button(Block_Resolution, 1, "2560 * 1440", UI_Visual_Res_2560, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 2, "1920 * 1080", UI_Visual_Res_1920, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 3, "1280 * 1024", UI_Visual_Res_1280, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 4, "1280 * 960", UI_Visual_Res_960, 83);
				const auto Block_CloudConfig = GUI_VAR.GUI_Block(580, 210, 150, "Cloud config");
				GUI_VAR.GUI_Button(Block_CloudConfig, 1, "Load config", UI_Misc_LoadCloudConfig, 80);
				GUI_VAR.GUI_List(Block_CloudConfig, 2, { "Legit","Rage","Legit - no visual" }, UI_Misc_SelectedConfig);
				auto Block_Spoof = GUI_VAR.GUI_Block(580, 380, 370, "Spoof");
				GUI_VAR.GUI_Checkbox(Block_Spoof, 1, "Enabled", UI_Spoof_Spoof, { 200,200,150 });
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 2, "Aim at teammate", UI_Spoof_AimbotTeam);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Spoof_1>(Block_Spoof, 2, UI_Spoof_AimbotTeam_Key);
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Spoof_2>({ Block_Spoof.x + 20,Block_Spoof.y }, 3, "Smooth", 0, 20, UI_Spoof_AimbotTeam_Smooth);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 4, "Increase recoil", UI_Spoof_IncreaseRecoil);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Spoof_3>({ Block_Spoof.x + 20,Block_Spoof.y }, 5, "Strength", 50, 1000, UI_Spoof_IncreaseRecoil_Value, "px");
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 6, "Unable to pick up C4", UI_Spoof_DropC4);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 7, "Fake anti aim", UI_Spoof_FakeAntiAim);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Spoof_4>(Block_Spoof, 7, UI_Spoof_FakeAntiAim_Key);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 8, "Kill drop sniper", UI_Spoof_KillDropSniper);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 9, "Learn player", UI_Spoof_LearnPlayer);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Spoof_5>(Block_Spoof, 9, UI_Spoof_LearnPlayer_Key);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 10, "Fake ragebot", UI_Spoof_FakeRageBot);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Spoof_6>(Block_Spoof, 10, UI_Spoof_FakeRageBot_Key);
				auto FakeRageBot_SliderString = "Target: " + Advanced::Player_Name(UI_Spoof_FakeRageBot_Target);
				if (!UI_Spoof_FakeRageBot_Target)FakeRageBot_SliderString = "Target: Any target";
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Spoof_7>({ Block_Spoof.x + 20,Block_Spoof.y }, 11, FakeRageBot_SliderString, 0, 64, UI_Spoof_FakeRageBot_Target);
				GUI_VAR.GUI_Tips(Block_Misc, 2, "Play Beep when hitting player.");
				GUI_VAR.GUI_Tips(Block_Misc, 5, "Makes a subtle sound when approaching an enemy.");
				GUI_VAR.GUI_Tips(Block_Misc, 8, "Auto attack when conditions such as distance and blood volume are met.");
				GUI_VAR.GUI_Tips(Block_Misc, 14, "Lock the game window to the front.");
				GUI_VAR.GUI_Tips(Block_Misc, 16, "Reduce the load on the CPU.", 0, { 255,150,150 });
				GUI_VAR.GUI_Tips(Block_Misc, 17, "Reduce screen brightness.");
				GUI_VAR.GUI_Tips(Block_Misc, 19, "Return to coordinates when shooting.");
				GUI_VAR.GUI_Tips(Block_Misc, 22, "Implement ESP by modifying cursor coordinates.");
				GUI_VAR.GUI_Tips({ Block_Resolution.x + 10,Block_Resolution.y }, 1, "Flexible switching of window resolution. (Do not use screen zoom!!!)");
				GUI_VAR.GUI_Tips({ Block_CloudConfig.x + 10,Block_CloudConfig.y }, 1, "Load parameter files stored in Github.");
				GUI_VAR.GUI_Tips(Block_Spoof, 1, "Prank local player. (global switch)");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 2, "Aimbot for teammate.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 4, "Enhanced upward deflection of firearms.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 6, "Drop it when picking up C4.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 7, "Rotate view......");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 8, "Drop the weapon when killing an enemy with a sniper rifle.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 9, "Learn recent player actions.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 10, "Mimic Ragebot silent aim.");
				GUI_WindowSize = { 1010,780 };
			}
			else if (UI_Panel == 3)//List
			{
				const auto Block_PlayerList = GUI_VAR.GUI_Block(150, 30, GUI_VAR.Window_GetSize().y - 60, "Player list", 330);
				static BOOL UI_Debug_PlayerList_ReloadList = false; static vector<string> PlayerNameList = {}; static string PlayerName = "";
				GUI_VAR.GUI_Slider<int, class CLASS_Block_PlayerList_1>(Block_PlayerList, 1, "Player ID", 0, 64, Debug_Control_Var::SelectPlayer);
				GUI_VAR.GUI_Button_Small({ Block_PlayerList.x + 10,Block_PlayerList.y }, 1, UI_Debug_PlayerList_ReloadList);
				if (UI_Debug_PlayerList_ReloadList || System::Sleep_Tick<class CLASS_DEBUG_AUTO_RELOAD_PLAYERLIST_>(5000)) { ReLoad(true); PlayerNameList = {}; for (short i = 0; i <= 64; ++i)PlayerNameList.push_back(Advanced::Player_Name(i)); System::Log("Debug: Reload player list"); }//刷新玩家列表页面
				GUI_VAR.GUI_InputText<class CLASS_Block_PlayerList_2>(Block_PlayerList, 2, PlayerName, "Search player name");
				if (PlayerName != "" && PlayerName != "None") { for (short i = 0; i <= 64; ++i)if (PlayerName == Advanced::Player_Name(i))Debug_Control_Var::SelectPlayer = i; }//人物名称搜索
				GUI_VAR.GUI_List(Block_PlayerList, 3, PlayerNameList, Debug_Control_Var::SelectPlayer, 27);
				GUI_VAR.GUI_Tips({ Block_PlayerList.x + 12,Block_PlayerList.y }, 1, "Reload player list.");
				GUI_VAR.GUI_Tips({ Block_PlayerList.x + 12,Block_PlayerList.y }, 2, "Search player name.");
				const auto Block_Info = GUI_VAR.GUI_Block(510, 30, 490, "Info", 330);
				const auto Player_Pawn = Advanced::Traverse_Player(Debug_Control_Var::SelectPlayer);
				Variable::Vector4 Debug_PawnColor = { 0,0,0 };//人物数据地址绘制颜色
				if (Player_Pawn.Pawn() == Global_LocalPlayer.Pawn())Debug_PawnColor = { 100,100,255 };//自身
				else if (Player_Pawn.TeamNumber() == Global_LocalPlayer.TeamNumber())Debug_PawnColor = { 0,255,0 };//同队
				else if (Player_Pawn.TeamNumber() != Global_LocalPlayer.TeamNumber())Debug_PawnColor = { 255,0,0 };//不同队
				if (Player_Pawn.Health() == 0)Debug_PawnColor = { 150,150,150 };//无效或是死亡
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 1, "client.dll -> " + Variable::Hex_String(Module_client));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 2, "Pawn -> " + Variable::Hex_String(Player_Pawn.Pawn()), Debug_PawnColor);
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 3, "Name: " + Advanced::Player_Name(Debug_Control_Var::SelectPlayer));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 4, "Health: " + to_string(Player_Pawn.Health()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 5, "Armor: " + to_string(Player_Pawn.Armor()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 6, "TeamNum: " + to_string(Player_Pawn.TeamNumber()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 7, "IDEntIndex: " + to_string(Player_Pawn.IDEntIndex()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 8, "Flags: " + to_string(Player_Pawn.Flags()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 9, "ShotsFired: " + to_string(Player_Pawn.ShotsFired()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 10, "MoveSpeed: " + to_string(Player_Pawn.MoveSpeed()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 11, "Spotted: " + to_string(Player_Pawn.Spotted()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 12, "Scoped: " + to_string(Player_Pawn.Scoped()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 13, "ActiveWeapon: " + Player_Pawn.ActiveWeaponName() + " (" + to_string(Player_Pawn.ActiveWeapon()) + ")");
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 14, "Origin: ");
				auto PlayerOrigin = Player_Pawn.Origin(); GUI_VAR.GUI_PosSelector({ Block_Info.x - 100,Block_Info.y }, 14, PlayerOrigin);
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 15, "Angle: ");
				auto PlayerViewAngle = Player_Pawn.ViewAngles(); GUI_VAR.GUI_PosSelector({ Block_Info.x - 100,Block_Info.y }, 15, PlayerViewAngle);
				GUI_VAR.GUI_Tips({ Block_Info.x + 3,Block_Info.y }, 1, "Cloud offsets date: " + CS2_Offsets::Offsets_Date);
				const auto Block_Offsets = GUI_VAR.GUI_Block(870, 30, GUI_VAR.Window_GetSize().y - 60, "Offsets", 330);
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 1, "Update date: " + CS2_Offsets::Offsets_Date);
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 2, "dwLocalPlayerController = " + Variable::Hex_String(CS2_Offsets::dwLocalPlayerController));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 3, "dwLocalPlayerPawn = " + Variable::Hex_String(CS2_Offsets::dwLocalPlayerPawn));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 4, "dwEntityList = " + Variable::Hex_String(CS2_Offsets::dwEntityList));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 5, "dwViewAngles = " + Variable::Hex_String(CS2_Offsets::dwViewAngles));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 6, "dwViewMatrix = " + Variable::Hex_String(CS2_Offsets::dwViewMatrix));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 7, "m_hPlayerPawn = " + Variable::Hex_String(CS2_Offsets::m_hPlayerPawn));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 8, "m_iTeamNum = " + Variable::Hex_String(CS2_Offsets::m_iTeamNum));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 9, "m_ArmorValue = " + Variable::Hex_String(CS2_Offsets::m_ArmorValue));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 10, "m_iHealth = " + Variable::Hex_String(CS2_Offsets::m_iHealth));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 11, "m_iIDEntIndex = " + Variable::Hex_String(CS2_Offsets::m_iIDEntIndex));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 12, "m_fFlags = " + Variable::Hex_String(CS2_Offsets::m_fFlags));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 13, "m_iShotsFired = " + Variable::Hex_String(CS2_Offsets::m_iShotsFired));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 14, "m_vecVelocity = " + Variable::Hex_String(CS2_Offsets::m_vecVelocity));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 15, "m_bSpotted = " + Variable::Hex_String(CS2_Offsets::m_bSpotted));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 16, "m_bIsScoped = " + Variable::Hex_String(CS2_Offsets::m_bIsScoped));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 17, "m_pClippingWeapon = " + Variable::Hex_String(CS2_Offsets::m_pClippingWeapon));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 18, "m_pGameSceneNode = " + Variable::Hex_String(CS2_Offsets::m_pGameSceneNode));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 19, "m_vecOrigin = " + Variable::Hex_String(CS2_Offsets::m_vecOrigin));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 20, "m_aimPunchCache = " + Variable::Hex_String(CS2_Offsets::m_aimPunchCache));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 21, "m_vecViewOffset = " + Variable::Hex_String(CS2_Offsets::m_vecViewOffset));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 22, "m_dwBoneMatrix = " + Variable::Hex_String(CS2_Offsets::m_dwBoneMatrix));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 23, "m_iszPlayerName = " + Variable::Hex_String(CS2_Offsets::m_iszPlayerName));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 24, "m_pActionTrackingServices = " + Variable::Hex_String(CS2_Offsets::m_pActionTrackingServices));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 25, "m_iNumRoundKills = " + Variable::Hex_String(CS2_Offsets::m_iNumRoundKills));
				//-----------------------------------------------------------------------------------------------------------------------------测试控件-------
				const auto Block_DebugControl = GUI_VAR.GUI_Block(510, 540, 280, "Debug control", 330);
				GUI_VAR.GUI_Checkbox(Block_DebugControl, 1, "Show console window", UI_Debug_ShowDebugWindow);
				GUI_VAR.GUI_Button_Small({ Block_DebugControl.x - 2,Block_DebugControl.y }, 1, Debug_Control_Var::ClearCommand);
				GUI_VAR.GUI_InputText<class CLASS_Block_DebugControl_1>({ Block_DebugControl.x - 15,Block_DebugControl.y }, 2, Debug_Control_Var::SystemCommand, "Command");
				GUI_VAR.GUI_Button_Small({ Block_DebugControl.x - 2,Block_DebugControl.y }, 2, Debug_Control_Var::SendSystemCommand);
				GUI_VAR.GUI_Checkbox(Block_DebugControl, 3, "Checkbox 1", Debug_Control_Var::Checkbox_1);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_DebugControl_2>({ Block_DebugControl.x - 70,Block_DebugControl.y }, 3, Debug_Control_Var::KeySelector_1);
				GUI_VAR.GUI_Checkbox(Block_DebugControl, 4, "Checkbox 2", Debug_Control_Var::Checkbox_2);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_DebugControl_3>({ Block_DebugControl.x - 70,Block_DebugControl.y }, 4, Debug_Control_Var::KeySelector_2);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_DebugControl_4>({ Block_DebugControl.x - 15,Block_DebugControl.y }, 5, "Slider int", -100, 100, Debug_Control_Var::Slider_1);
				GUI_VAR.GUI_Slider<float, class CLASS_Block_DebugControl_5>({ Block_DebugControl.x - 15,Block_DebugControl.y }, 6, "Slider float", -50, 50, Debug_Control_Var::Slider_2);
				GUI_VAR.GUI_Button({ Block_DebugControl.x - 15,Block_DebugControl.y }, 7, "Button 1", Debug_Control_Var::Button_1);
				GUI_VAR.GUI_Button({ Block_DebugControl.x - 15,Block_DebugControl.y }, 8, "Button 2", Debug_Control_Var::Button_2);
				GUI_VAR.GUI_Tips(Block_DebugControl, 1, "Clear console.");
				GUI_VAR.GUI_Tips(Block_DebugControl, 2, "Send command to system.");
				GUI_VAR.GUI_Tips(Block_DebugControl, 3, "GUI Draw FPS: " + to_string(GUI_VAR.Window_FPS() + System::Rand_Number(0, 1)) + "." + to_string(System::Rand_Number(100, 999)) + "  (" + to_string(GUI_VAR.Window_FPS()) + ")");//绘制GUI绘制帧数
				if (Debug_Control_Var::ClearCommand)system("cls");//清除控制台
				if (Debug_Control_Var::SendSystemCommand)//向系统发送指令
				{
					if (Debug_Control_Var::SystemCommand != "")cout << Debug_Control_Var::SystemCommand << endl;//打印控制台
					if (Variable::String_Find(Debug_Control_Var::SystemCommand, "/"))//检测是否是命令
					{
						auto Last_Send_STR = Debug_Control_Var::SystemCommand; Last_Send_STR.erase(0, 1);//擦除/
						const auto Return_String = Variable::String_Lower(Last_Send_STR);//转换小写 (自定义命令只支持小写判断)
						if (Return_String == "add checkbox")++Debug_Control_Var::Checkbox_Quantity;
						else system(Last_Send_STR.c_str());
					}
					else System::Log("Misc: Invalid command. Please add / in front of.", true);
				}
				if (Debug_Control_Var::Button_1 || Debug_Control_Var::Button_2)System::Log("Debug: Click button");
				if (Debug_Control_Var::Button_1)
				{
					System::Log("Username: " + System::Get_UserName());//打印用户名
					System::Log("Computername: " + System::Get_ComputerName());//打印用户电脑名
					System::Log("IP V4: " + System::Get_IPv4Address());//打印用户IPV4
				}
				GUI_WindowSize = { 1230,850 };
			}
			else if (UI_Panel == 4)//Setting
			{
				const auto Block_About = GUI_VAR.GUI_Block(150, 30, 160, "About");
				GUI_VAR.GUI_Text(Block_About, 1, "Rensen", GUI_VAR.Global_Get_EasyGUI_Color());
				GUI_VAR.GUI_Text({ Block_About.x + 47,Block_About.y }, 1, "for Counter-Strike 2 (External Free)", { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 2, "Version: " + Variable::Float_Precision(Rensen_Version), { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 3, "Release date: " + Rensen_ReleaseDate, { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 4, "Author: https://github.com/Coslly", { 100,100,100 });
				GUI_VAR.GUI_Button_Small({ Block_About.x + 10,Block_About.y }, 4, UI_Setting_OPENLINKAuthor);
				GUI_VAR.GUI_Tips({ Block_About.x + 10,Block_About.y }, 1, "No ban record so far in 2020!!!", 0, GUI_VAR.Global_Get_EasyGUI_Color());
				const auto Block_Menu = GUI_VAR.GUI_Block(150, 210, 340, "Menu");
				GUI_VAR.GUI_Text(Block_Menu, 1, "Menu key");
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Menu_1>(Block_Menu, 1, UI_Setting_MenuKey);
				GUI_VAR.GUI_Checkbox(Block_Menu, 2, "Menu color", UI_Setting_CustomColor);
				GUI_VAR.GUI_ColorSelector_a(Block_Menu, 2, UI_Setting_MainColor);
				if (UI_Setting_MainColor.a < 100)UI_Setting_MainColor.a = 100;
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Menu_2>(Block_Menu, 3, "Menu animation speed", 1.2, 10, UI_Setting_MenuAnimation);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Menu_3>(Block_Menu, 4, "Menu font size", 0, 30, UI_Setting_MenuFontSize, "px");
				GUI_VAR.GUI_InputText<class CLASS_Block_Menu_4>(Block_Menu, 5, UI_Setting_MenuFont, "Custom menu font");
				GUI_VAR.GUI_Button(Block_Menu, 6, "Save local config", UI_Setting_SaveLocalConfig, 65);
				if (CS2_HWND)GUI_VAR.GUI_Button(Block_Menu, 7, "Quit CS", UI_Setting_QuitCS, 90);
				else GUI_VAR.GUI_Button(Block_Menu, 7, "Start CS", UI_Setting_StartCS, 85);
				GUI_VAR.GUI_Button(Block_Menu, 8, "Github repositories", UI_Setting_GithubRepositories, 60);
				GUI_VAR.GUI_Button(Block_Menu, 9, "Restart menu", UI_Setting_RestartMenu, 75);
				GUI_VAR.GUI_Button(Block_Menu, 10, "Unload", UI_Setting_Unload, 95);
				GUI_VAR.GUI_Tips({ Block_Menu.x + 10,Block_Menu.y }, 6, "If you want to reset the default config you can delete Rensen.cfg in the same folder.");
				GUI_WindowSize = { 580,580 };
			}
			else if (UI_Panel == 5)//Attach
			{
				const auto Block_Size = GUI_VAR.Window_GetSize().y - 60;
				const auto Block_A = GUI_VAR.GUI_Block(150, 30, Block_Size, "Block_A");
				//A区块控件代码区域
				for (int i = 1; i <= Debug_Control_Var::Checkbox_Quantity; ++i)
				{
					GUI_VAR.GUI_Checkbox(Block_A, i, "Checkbox " + to_string(i), Debug_Control_Var::Checkbox_Value[i]);
				}

				const auto Block_B = GUI_VAR.GUI_Block(580, 30, Block_Size, "Block_B");
				//B区块控件代码区域

				GUI_WindowSize = { 1010,900 };
			}
			GUI_VAR.Draw_GUI(Debug_Control_Var::Checkbox_2);//最终绘制GUI画板
			if (UI_Misc_SavePerformance)Sleep(5);//节省电脑占用性能
			if (true)//按钮事件接收
			{
				if (UI_Visual_Res_2560)Window::Set_Resolution(2560, 1440);//设置显示器像素
				else if (UI_Visual_Res_1920)Window::Set_Resolution(1920, 1080);
				else if (UI_Visual_Res_1280)Window::Set_Resolution(1280, 1024);
				else if (UI_Visual_Res_960)Window::Set_Resolution(1280, 960);
				if (UI_Misc_LoadCloudConfig)//加载Github上的云参数
				{
					const auto Config_ID = UI_Misc_SelectedConfig;//防止套用的参数套写变量
					if (UI_Misc_SelectedConfig == 0)LoadCloudConfig("Legit");
					else if (UI_Misc_SelectedConfig == 1)LoadCloudConfig("Rage");
					else if (UI_Misc_SelectedConfig == 2)LoadCloudConfig("Legit No Visual");
					System::Log("Misc: LoadCloudConfig [" + to_string(Config_ID) + "]");
				}
				if (UI_Setting_OPENLINKAuthor)//打开作者Github主题页面
				{
					System::Open_Website("https://github.com/Coslly");
					System::Log("Setting: OpenGithubURL");
				}
				if (UI_Setting_SaveLocalConfig || (System::Get_Key(VK_LCONTROL) && System::Get_Key_Onest(0x53)))//保存当前所设置的参数
				{
					SaveLocalConfig();
					System::Log("Setting: SaveConfig");
				}
				if (UI_Setting_StartCS)//启动CS
				{
					if (CS2_MEM.Get_ProcessHWND() == 0)System::Open_Website("steam://rungameid/730");
					System::Log("Setting: StartCS");
				}
				else if (UI_Setting_QuitCS)//关闭CS
				{
					if (CS2_MEM.Get_ProcessHWND() != 0)Window::Kill_Window(CS2_MEM.Get_ProcessHWND());
					System::Log("Setting: QuitCS");
				}
				if (UI_Setting_GithubRepositories)//打开Github项目地址
				{
					System::Open_Website("https://github.com/Coslly/Rensen");
					System::Log("Setting: GithubRepositories");
				}
				if (UI_Setting_RestartMenu)//重启菜单
				{
					System::Log("Setting: RestartMenu");
					System::Self_Restart();
				}
				if (UI_Setting_Unload)//关闭菜单
				{
					Window::NVIDIA_Overlay();
					System::Log("Setting: Unload");
					exit(0);
				}
			}
		}
	}
}
void Thread_Menu_CN() noexcept//菜单线程 (提供给使用者丰富的自定义选项) (汉化版)
{
	System::Log("Load Thread: Thread_Menu()");
	GUI_VAR.Window_Create(1200, 1000, "Rensen", true);//创建置顶GUI绘制窗口
	while (true)
	{
		GUI_VAR.Window_SetTitle(System::Rand_String(10));//随机菜单窗口标题
		Window::Set_LimitWindowShow(GUI_VAR.Window_HWND(), UI_Misc_ByPassOBS);//绕过OBS
		UI_Setting_MenuFont = "等线";//中文字体
		static int UI_Panel = 0;//大区块选择
		static Variable::Vector2 GUI_WindowSize = { 0,0 };//窗体大小(用于开关动画)
		if (!Menu_Open)GUI_WindowSize = { 0,0 };//关闭窗体时
		GUI_VAR.Window_SetSize(Variable::Animation_Vec2<class CLASS_MenuState_Animation_>(GUI_WindowSize, UI_Setting_MenuAnimation));//菜单窗口大小动画 (弹出, 关闭)
		if (!GUI_VAR.Window_Move() && Menu_Open)//不在移动窗口时绘制GUI
		{
			if (UI_Setting_CustomColor)//自定义颜色(单色)
			{
				GUI_VAR.Global_Set_EasyGUI_Color(UI_Setting_MainColor);//设置主题颜色
				GUI_VAR.GUI_BackGround(4);//自定义颜色背景主题
			}
			else GUI_VAR.GUI_BackGround(3);//默认(彩虹)
			GUI_VAR.GUI_Block(20, 20, 40, "", 110); GUI_VAR.In_DrawString(37, 35, "Rensen", GUI_VAR.Global_Get_EasyGUI_Color().Min_Bri(200), "Verdana", 25);
			GUI_VAR.GUI_Block_Panel(20, 70, 110, GUI_VAR.Window_GetSize().y - 90, "", { "合法UTT","视觉UTT","杂项UTT","信息列表UTT","设置UTT","附加UTT" }, UI_Panel, 20);
			if (UI_Panel == 0)//Legit
			{
				const auto Block_Aimbot = GUI_VAR.GUI_Block(150, 30, 340, "瞄准机器人UTT");
				GUI_VAR.GUI_Checkbox(Block_Aimbot, 1, "启用UTT", UI_Legit_Aimbot);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Aimbot_1>(Block_Aimbot, 1, UI_Legit_Aimbot_Key);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 2, "判断墙体UTT", UI_Legit_Aimbot_JudgingWall);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 3, "自动压枪UTT", UI_Legit_Aimbot_RemoveRecoil);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 4, "瞄准时触发UTT", UI_Legit_Aimbot_TriggerOnAim);
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 20,Block_Aimbot.y }, 5, "自动开火UTT", UI_Legit_Aimbot_AutoShoot, { 255,150,150 });
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 40,Block_Aimbot.y }, 6, "自动停止移动UTT", UI_Legit_Aimbot_AutoStop, { 255,150,150 });
				GUI_VAR.GUI_Checkbox({ Block_Aimbot.x + 40,Block_Aimbot.y }, 7, "狙击枪自动开镜UTT", UI_Legit_Aimbot_AutoScope, { 255,150,150 });
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Aimbot_2>({ Block_Aimbot.x + 20,Block_Aimbot.y }, 8, "自动开火延迟UTT", 0, 500, UI_Legit_Aimbot_AutoShootDelay, "ms", { 255,150,150 });
				GUI_VAR.GUI_Checkbox(Block_Aimbot, 9, "自适应自瞄UTT", UI_Legit_AdaptiveAimbot, { 200,200,150 });
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Aimbot_3>(Block_Aimbot, 10, "平滑度UTT", 0, 20, UI_Legit_AdaptiveAimbot_InitialSmooth, "", { 200,200,150 });
				const auto Block_Armory = GUI_VAR.GUI_Block(150, 390, 490, "武器库UTT");
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 1, "显示范围圆圈UTT", UI_Legit_Armory_ShowAimbotRange);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 2, "打击点解析器UTT", UI_Legit_Armory_HitSiteParser);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 3, "手枪 只打胸部 (反之头部)UTT", UI_Legit_Armory_BodyAim_PISTOL);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Armory_1>({ Block_Armory.x - 10,Block_Armory.y }, 4, "手枪 范围UTT", 0, 100, UI_Legit_Armory_Range_PISTOL, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Armory_2>({ Block_Armory.x - 10,Block_Armory.y }, 5, "手枪 平滑度UTT", 0, 40, UI_Legit_Armory_Smooth_PISTOL);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 6, "步枪 只打胸部 (反之头部)UTT", UI_Legit_Armory_BodyAim_RIFLE);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Armory_3>({ Block_Armory.x - 10,Block_Armory.y }, 7, "步枪 范围UTT", 0, 100, UI_Legit_Armory_Range_RIFLE, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Armory_4>({ Block_Armory.x - 10,Block_Armory.y }, 8, "步枪 平滑度UTT", 0, 40, UI_Legit_Armory_Smooth_RIFLE);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 9, "狙击枪 只打胸部 (反之头部)UTT", UI_Legit_Armory_BodyAim_SNIPER);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Armory_5>({ Block_Armory.x - 10,Block_Armory.y }, 10, "狙击枪 范围UTT", 0, 100, UI_Legit_Armory_Range_SNIPER, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Armory_6>({ Block_Armory.x - 10,Block_Armory.y }, 11, "狙击枪 平滑度UTT", 0, 40, UI_Legit_Armory_Smooth_SNIPER);
				GUI_VAR.GUI_Checkbox({ Block_Armory.x - 10,Block_Armory.y }, 12, "霰弹枪 只打胸部 (反之头部)UTT", UI_Legit_Armory_BodyAim_SHOTGUN);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Armory_7>({ Block_Armory.x - 10,Block_Armory.y }, 13, "霰弹枪 范围UTT", 0, 100, UI_Legit_Armory_Range_SHOTGUN, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Armory_8>({ Block_Armory.x - 10,Block_Armory.y }, 14, "霰弹枪 平滑度UTT", 0, 40, UI_Legit_Armory_Smooth_SHOTGUN);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Armory_9>({ Block_Armory.x - 10,Block_Armory.y }, 15, "霰弹枪 触发距离UTT", 100, 2000, UI_Legit_Armory_TriggerDistance_SHOTGUN);
				const auto Block_Triggerbot = GUI_VAR.GUI_Block(580, 30, 190, "自动扳机UTT");
				GUI_VAR.GUI_Checkbox(Block_Triggerbot, 1, "启用UTT", UI_Legit_Triggerbot);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Triggerbot_1>(Block_Triggerbot, 1, UI_Legit_Triggerbot_Key);
				GUI_VAR.GUI_Checkbox({ Block_Triggerbot.x + 20,Block_Triggerbot.y }, 2, "任何目标 (包括掉落的武器)UTT", UI_Legit_Triggerbot_AnyTarget);
				GUI_VAR.GUI_Checkbox({ Block_Triggerbot.x + 20,Block_Triggerbot.y }, 3, "精准时触发UTT", UI_Legit_Triggerbot_ShootWhenAccurate);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Triggerbot_2>(Block_Triggerbot, 4, "开火延迟UTT", 1, 500, UI_Legit_Triggerbot_ShootDelay, "ms");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Triggerbot_3>(Block_Triggerbot, 5, "开火时长UTT", 1, 1000, UI_Legit_Triggerbot_ShootDuration, "ms");
				const auto Block_PreciseAim = GUI_VAR.GUI_Block(580, 240, 130, "精确瞄准UTT");
				GUI_VAR.GUI_Checkbox(Block_PreciseAim, 1, "启用UTT", UI_Legit_PreciseAim);
				GUI_VAR.GUI_Slider<float, class CLASS_Block_PreciseAim_1>(Block_PreciseAim, 2, "默认灵敏度UTT", 0, 0.022, UI_Legit_PreciseAim_DefaultSensitivity);
				GUI_VAR.GUI_Slider<float, class CLASS_Block_PreciseAim_2>(Block_PreciseAim, 3, "触发时灵敏度UTT", 0, 0.015, UI_Legit_PreciseAim_EnableSensitivity);
				const auto Block_RemoveRecoil = GUI_VAR.GUI_Block(580, 390, 160, "自动压枪UTT");
				GUI_VAR.GUI_Checkbox(Block_RemoveRecoil, 1, "启用UTT", UI_Legit_RemoveRecoil);
				GUI_VAR.GUI_Checkbox({ Block_RemoveRecoil.x + 20,Block_RemoveRecoil.y }, 2, "水平修复UTT", UI_Legit_RemoveRecoil_LateralRepair);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_RemoveRecoil_1>(Block_RemoveRecoil, 3, "触发子弹量UTT", 1, 10, UI_Legit_RemoveRecoil_StartBullet);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_RemoveRecoil_2>(Block_RemoveRecoil, 4, "灵敏度UTT", 0, 100, UI_Legit_RemoveRecoil_Sensitive, "%");
				const auto Block_MagnetAim = GUI_VAR.GUI_Block(580, 570, 130, "磁吸瞄准UTT");
				GUI_VAR.GUI_Checkbox(Block_MagnetAim, 1, "启用UTT", UI_Legit_MagnetAim);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_MagnetAim_1>(Block_MagnetAim, 2, "范围UTT", 0, 100, UI_Legit_MagnetAim_Range, "%");
				GUI_VAR.GUI_Slider<float, class CLASS_Block_MagnetAim_2>(Block_MagnetAim, 3, "平滑度UTT", 0.5, 6.6666, UI_Legit_MagnetAim_Smooth);
				GUI_VAR.GUI_Tips(Block_Aimbot, 1, "Help you quickly aim at the target.");
				GUI_VAR.GUI_Tips({ Block_Aimbot.x + 10,Block_Aimbot.y }, 5, "Prefer Ragebot.", 0, { 255,150,150 });
				GUI_VAR.GUI_Tips(Block_Aimbot, 9, "More biological than normal aimbot.", 0, { 200,200,150 });
				GUI_VAR.GUI_Tips(Block_Triggerbot, 1, "Shoot when aiming at the enemy.");
				GUI_VAR.GUI_Tips(Block_PreciseAim, 1, "Reduce the sensitivity of the reticle when aiming at the enemy.");
				GUI_VAR.GUI_Tips({ Block_RemoveRecoil.x + 10,Block_RemoveRecoil.y }, 2, "Operations that only return landscape.");
				GUI_VAR.GUI_Tips({ Block_RemoveRecoil.x + 10,Block_RemoveRecoil.y }, 4, "Corresponding game sensitivity value.");
				GUI_VAR.GUI_Tips(Block_MagnetAim, 1, "Slow aiming without triggering key conditions. (Hard to see)");
				GUI_WindowSize = { 1010,910 };
			}
			else if (UI_Panel == 1)//Visual
			{
				const auto Block_ESP = GUI_VAR.GUI_Block(150, 30, 550, "透视UTT");
				GUI_VAR.GUI_Checkbox(Block_ESP, 1, "启用UTT", UI_Visual_ESP);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_ESP_1>(Block_ESP, 1, UI_Visual_ESP_Key);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 2, "方框UTT", UI_Visual_ESP_Box);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 3, "血条UTT", UI_Visual_ESP_Health);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 4, "武器UTT", UI_Visual_ESP_ActiveWeapon);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 5, "射线UTT", UI_Visual_ESP_Line);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 6, "骨骼UTT", UI_Visual_ESP_Skeleton);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_ESP_2>(Block_ESP, 7, "粗细UTT", 1, 5, UI_Visual_ESP_Skeleton_Thickness, "px");
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 8, "头点UTT", UI_Visual_ESP_HeadDot);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 9, "状态UTT", UI_Visual_ESP_State);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 10, "名称UTT", UI_Visual_ESP_Name);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 11, "掉落物UTT", UI_Visual_ESP_Drops);
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 12, "视角外指针UTT", UI_Visual_ESP_OutFOV);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_ESP_3>(Block_ESP, 13, "大小UTT", 20, 70, UI_Visual_ESP_OutFOV_Size, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_ESP_4>(Block_ESP, 14, "范围UTT", 0, 100, UI_Visual_ESP_OutFOV_Radius, "%");
				GUI_VAR.GUI_Checkbox({ Block_ESP.x + 20,Block_ESP.y }, 15, "自定义颜色UTT", UI_Visual_ESP_CustomColor);
				GUI_VAR.GUI_ColorSelector(Block_ESP, 15, UI_Visual_ESP_CustomColor_Color);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_ESP_5>(Block_ESP, 16, "透明度UTT", 20, 255, UI_Visual_ESP_DrawAlpha);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_ESP_6>(Block_ESP, 17, "绘制延迟UTT", 1, 30, UI_Visual_ESP_DrawDelay, "ms");
				const auto Block_Hitmark = GUI_VAR.GUI_Block(580, 30, 280, "打击指针UTT");
				GUI_VAR.GUI_Checkbox(Block_Hitmark, 1, "启用UTT", UI_Visual_HitMark);
				GUI_VAR.GUI_ColorSelector(Block_Hitmark, 1, UI_Visual_HitMark_Color);
				GUI_VAR.GUI_Checkbox({ Block_Hitmark.x + 20,Block_Hitmark.y }, 2, "显示伤害UTT", UI_Visual_HitMark_Damage);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Hitmark_1>(Block_Hitmark, 3, "范围UTT", 3, 100, UI_Visual_HitMark_Range, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Hitmark_2>(Block_Hitmark, 4, "长度UTT", 3, 100, UI_Visual_HitMark_Length, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Hitmark_3>(Block_Hitmark, 5, "粗细UTT", 1, 10, UI_Visual_HitMark_Thickness, "px");
				GUI_VAR.GUI_Checkbox({ Block_Hitmark.x + 20,Block_Hitmark.y }, 6, "3D闪电效果UTT", UI_Visual_HitMark_KillEffect);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Hitmark_4>(Block_Hitmark, 7, "数量UTT", 10, 500, UI_Visual_HitMark_KillEffect_Quantity);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Hitmark_5>(Block_Hitmark, 8, "范围UTT", 10, 500, UI_Visual_HitMark_KillEffect_Range);
				const auto Block_Radar = GUI_VAR.GUI_Block(580, 330, 190, "雷达UTT");
				GUI_VAR.GUI_Checkbox(Block_Radar, 1, "启用UTT", UI_Visual_Radar);
				GUI_VAR.GUI_Button_Small({ Block_Radar.x + 10,Block_Radar.y }, 2, UI_Visual_Radar_Show);
				GUI_VAR.GUI_Checkbox({ Block_Radar.x + 20,Block_Radar.y }, 2, "跟随朝向角度UTT", UI_Visual_Radar_FollowAngle);
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Radar_1>(Block_Radar, 3, "范围UTT", 0.2, 40, UI_Visual_Radar_Range);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Radar_2>(Block_Radar, 4, "大小UTT", 150, 500, UI_Visual_Radar_Size, "px");
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Radar_3>(Block_Radar, 5, "透明度UTT", 0, 255, UI_Visual_Radar_Alpha);
				GUI_VAR.GUI_Tips(Block_ESP, 1, "Learn enemy coordinates through walls. (Full screen cannot be used)");
				GUI_VAR.GUI_Tips(Block_Hitmark, 1, "Effect that triggers when hitting the player.");
				GUI_VAR.GUI_Tips(Block_Radar, 1, "Exterior window radar. (Full screen cannot be used)");
				GUI_WindowSize = { 1010,610 };
			}
			else if (UI_Panel == 2)//Misc
			{
				const auto Block_Misc = GUI_VAR.GUI_Block(150, 30, 720, "杂项UTT");
				GUI_VAR.GUI_Checkbox(Block_Misc, 1, "兔子跳UTT", UI_Misc_BunnyHop);
				GUI_VAR.GUI_Checkbox(Block_Misc, 2, "击打音效UTT", UI_Misc_HitSound);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_1>(Block_Misc, 3, "音调UTT", 10, 5000, UI_Misc_HitSound_Tone);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_2>(Block_Misc, 4, "长度UTT", 10, 80, UI_Misc_HitSound_Length);
				GUI_VAR.GUI_Checkbox(Block_Misc, 5, "声呐UTT", UI_Misc_Sonar);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Misc_3>(Block_Misc, 5, UI_Misc_Sonar_Key);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_4>(Block_Misc, 6, "远UTT", 500, 1000, UI_Misc_Sonar_Range_Far);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_5>(Block_Misc, 7, "近UTT", 0, 500, UI_Misc_Sonar_Range_Near);
				GUI_VAR.GUI_Checkbox(Block_Misc, 8, "自动刀UTT", UI_Misc_AutoKnife);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Misc_6>(Block_Misc, 8, UI_Misc_AutoKnife_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 9, "自动电击枪UTT", UI_Misc_AutoTaser);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Misc_7>(Block_Misc, 9, UI_Misc_AutoTaser_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 10, "水印UTT", UI_Misc_Watermark);
				GUI_VAR.GUI_Checkbox(Block_Misc, 11, "狙击枪准星UTT", UI_Misc_SniperCrosshair);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_8>(Block_Misc, 12, "大小UTT", 10, 60, UI_Misc_SniperCrosshair_Size, "px");
				GUI_VAR.GUI_Checkbox(Block_Misc, 13, "防止挂机踢出UTT", UI_Misc_AntiAFKKick);
				GUI_VAR.GUI_Checkbox(Block_Misc, 14, "锁定游戏窗口最前端UTT", UI_Misc_LockGameWindow);
				GUI_VAR.GUI_Checkbox(Block_Misc, 15, "绕过OBS捕捉UTT", UI_Misc_ByPassOBS);
				GUI_VAR.GUI_Checkbox(Block_Misc, 16, "节省性能UTT", UI_Misc_SavePerformance, { 255,150,150 });
				GUI_VAR.GUI_Checkbox(Block_Misc, 17, "夜晚模式UTT", UI_Misc_NightMode);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Misc_9>(Block_Misc, 18, "透明度UTT", 50, 180, UI_Misc_NightMode_Alpha);
				GUI_VAR.GUI_Checkbox(Block_Misc, 19, "自动PEEKUTT", UI_Misc_AutoPeek);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Misc_10>(Block_Misc, 19, UI_Misc_AutoPeek_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 20, "自动急停UTT", UI_Misc_QuickStop);
				GUI_VAR.GUI_Checkbox(Block_Misc, 21, "击杀自动停火UTT", UI_Misc_AutoKillCeasefire);
				GUI_VAR.GUI_Checkbox(Block_Misc, 22, "光标透视UTT", UI_Misc_CursorESP);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Misc_11>(Block_Misc, 22, UI_Misc_CursorESP_Key);
				GUI_VAR.GUI_Checkbox(Block_Misc, 23, "判断队友UTT", UI_Misc_TeamCheck, { 200,200,150 });
				const auto Block_Resolution = GUI_VAR.GUI_Block(580, 30, 160, "屏幕像素UTT");
				GUI_VAR.GUI_Button(Block_Resolution, 1, "2560 * 1440", UI_Visual_Res_2560, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 2, "1920 * 1080", UI_Visual_Res_1920, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 3, "1280 * 1024", UI_Visual_Res_1280, 78);
				GUI_VAR.GUI_Button(Block_Resolution, 4, "1280 * 960", UI_Visual_Res_960, 83);
				const auto Block_CloudConfig = GUI_VAR.GUI_Block(580, 210, 150, "云端配置UTT");
				GUI_VAR.GUI_Button(Block_CloudConfig, 1, "加载配置UTT", UI_Misc_LoadCloudConfig, 20);
				GUI_VAR.GUI_List(Block_CloudConfig, 2, { "Legit","Rage","Legit - no visual" }, UI_Misc_SelectedConfig);
				auto Block_Spoof = GUI_VAR.GUI_Block(580, 380, 370, "恶搞功能UTT");
				GUI_VAR.GUI_Checkbox(Block_Spoof, 1, "开启UTT", UI_Spoof_Spoof, { 200,200,150 });
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 2, "瞄准队友UTT", UI_Spoof_AimbotTeam);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Spoof_1>(Block_Spoof, 2, UI_Spoof_AimbotTeam_Key);
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Spoof_2>({ Block_Spoof.x + 20,Block_Spoof.y }, 3, "平滑度UTT", 0, 20, UI_Spoof_AimbotTeam_Smooth);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 4, "增大后坐力UTT", UI_Spoof_IncreaseRecoil);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Spoof_3>({ Block_Spoof.x + 20,Block_Spoof.y }, 5, "后座量UTT", 50, 1000, UI_Spoof_IncreaseRecoil_Value, "px");
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 6, "丢弃C4UTT", UI_Spoof_DropC4);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 7, "假反瞄准UTT", UI_Spoof_FakeAntiAim);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Spoof_4>(Block_Spoof, 7, UI_Spoof_FakeAntiAim_Key);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 8, "击杀丢弃狙击枪UTT", UI_Spoof_KillDropSniper);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 9, "学习最近的玩家UTT", UI_Spoof_LearnPlayer);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Spoof_5>(Block_Spoof, 9, UI_Spoof_LearnPlayer_Key);
				GUI_VAR.GUI_Checkbox({ Block_Spoof.x + 20,Block_Spoof.y }, 10, "假愤怒机器人UTT", UI_Spoof_FakeRageBot);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Spoof_6>(Block_Spoof, 10, UI_Spoof_FakeRageBot_Key);
				auto FakeRageBot_SliderString = "目标: UTT" + Advanced::Player_Name(UI_Spoof_FakeRageBot_Target);
				if (!UI_Spoof_FakeRageBot_Target)FakeRageBot_SliderString = "目标: 任何目标UTT";
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Spoof_7>({ Block_Spoof.x + 20,Block_Spoof.y }, 11, FakeRageBot_SliderString, 0, 64, UI_Spoof_FakeRageBot_Target);
				GUI_VAR.GUI_Tips(Block_Misc, 2, "Play Beep when hitting player.");
				GUI_VAR.GUI_Tips(Block_Misc, 5, "Makes a subtle sound when approaching an enemy.");
				GUI_VAR.GUI_Tips(Block_Misc, 8, "Auto attack when conditions such as distance and blood volume are met.");
				GUI_VAR.GUI_Tips(Block_Misc, 14, "Lock the game window to the front.");
				GUI_VAR.GUI_Tips(Block_Misc, 16, "Reduce the load on the CPU.", 0, { 255,150,150 });
				GUI_VAR.GUI_Tips(Block_Misc, 17, "Reduce screen brightness.");
				GUI_VAR.GUI_Tips(Block_Misc, 19, "Return to coordinates when shooting.");
				GUI_VAR.GUI_Tips(Block_Misc, 22, "Implement ESP by modifying cursor coordinates.");
				GUI_VAR.GUI_Tips({ Block_Resolution.x + 10,Block_Resolution.y }, 1, "Flexible switching of window resolution. (Do not use screen zoom!!!)");
				GUI_VAR.GUI_Tips({ Block_CloudConfig.x + 10,Block_CloudConfig.y }, 1, "Load parameter files stored in Github.");
				GUI_VAR.GUI_Tips(Block_Spoof, 1, "Prank local player. (global switch)");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 2, "Aimbot for teammate.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 4, "Enhanced upward deflection of firearms.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 6, "Drop it when picking up C4.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 7, "Rotate view......");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 8, "Drop the weapon when killing an enemy with a sniper rifle.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 9, "Learn recent player actions.");
				GUI_VAR.GUI_Tips({ Block_Spoof.x + 10,Block_Spoof.y }, 10, "Mimic Ragebot silent aim.");
				GUI_WindowSize = { 1010,780 };
			}
			else if (UI_Panel == 3)//List
			{
				const auto Block_PlayerList = GUI_VAR.GUI_Block(150, 30, GUI_VAR.Window_GetSize().y - 60, "玩家列表UTT", 330);
				static BOOL UI_Debug_PlayerList_ReloadList = false; static vector<string> PlayerNameList = {}; static string PlayerName = "";
				GUI_VAR.GUI_Slider<int, class CLASS_Block_PlayerList_1>(Block_PlayerList, 1, "玩家 IDUTT", 0, 64, Debug_Control_Var::SelectPlayer);
				GUI_VAR.GUI_Button_Small({ Block_PlayerList.x + 10,Block_PlayerList.y }, 1, UI_Debug_PlayerList_ReloadList);
				if (UI_Debug_PlayerList_ReloadList || System::Sleep_Tick<class CLASS_DEBUG_AUTO_RELOAD_PLAYERLIST_>(5000)) { ReLoad(true); PlayerNameList = {}; for (short i = 0; i <= 64; ++i)PlayerNameList.push_back(Advanced::Player_Name(i)); System::Log("Debug: Reload player list"); }//刷新玩家列表页面
				GUI_VAR.GUI_InputText<class CLASS_Block_PlayerList_2>(Block_PlayerList, 2, PlayerName, "搜索玩家名称UTT");
				if (PlayerName != "" && PlayerName != "None") { for (short i = 0; i <= 64; ++i)if (PlayerName == Advanced::Player_Name(i))Debug_Control_Var::SelectPlayer = i; }//人物名称搜索
				GUI_VAR.GUI_List(Block_PlayerList, 3, PlayerNameList, Debug_Control_Var::SelectPlayer, 27);
				GUI_VAR.GUI_Tips({ Block_PlayerList.x + 12,Block_PlayerList.y }, 1, "Reload player list.");
				GUI_VAR.GUI_Tips({ Block_PlayerList.x + 12,Block_PlayerList.y }, 2, "Search player name.");
				const auto Block_Info = GUI_VAR.GUI_Block(510, 30, 490, "Info", 330);
				const auto Player_Pawn = Advanced::Traverse_Player(Debug_Control_Var::SelectPlayer);
				Variable::Vector4 Debug_PawnColor = { 0,0,0 };//人物数据地址绘制颜色
				if (Player_Pawn.Pawn() == Global_LocalPlayer.Pawn())Debug_PawnColor = { 100,100,255 };//自身
				else if (Player_Pawn.TeamNumber() == Global_LocalPlayer.TeamNumber())Debug_PawnColor = { 0,255,0 };//同队
				else if (Player_Pawn.TeamNumber() != Global_LocalPlayer.TeamNumber())Debug_PawnColor = { 255,0,0 };//不同队
				if (Player_Pawn.Health() == 0)Debug_PawnColor = { 150,150,150 };//无效或是死亡
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 1, "client.dll -> " + Variable::Hex_String(Module_client));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 2, "Pawn -> " + Variable::Hex_String(Player_Pawn.Pawn()), Debug_PawnColor);
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 3, "Name: " + Advanced::Player_Name(Debug_Control_Var::SelectPlayer));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 4, "Health: " + to_string(Player_Pawn.Health()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 5, "Armor: " + to_string(Player_Pawn.Armor()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 6, "TeamNum: " + to_string(Player_Pawn.TeamNumber()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 7, "IDEntIndex: " + to_string(Player_Pawn.IDEntIndex()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 8, "Flags: " + to_string(Player_Pawn.Flags()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 9, "ShotsFired: " + to_string(Player_Pawn.ShotsFired()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 10, "MoveSpeed: " + to_string(Player_Pawn.MoveSpeed()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 11, "Spotted: " + to_string(Player_Pawn.Spotted()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 12, "Scoped: " + to_string(Player_Pawn.Scoped()));
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 13, "ActiveWeapon: " + Player_Pawn.ActiveWeaponName() + " (" + to_string(Player_Pawn.ActiveWeapon()) + ")");
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 14, "Origin: ");
				auto PlayerOrigin = Player_Pawn.Origin(); GUI_VAR.GUI_PosSelector({ Block_Info.x - 100,Block_Info.y }, 14, PlayerOrigin);
				GUI_VAR.GUI_Text({ Block_Info.x - 20,Block_Info.y }, 15, "Angle: ");
				auto PlayerViewAngle = Player_Pawn.ViewAngles(); GUI_VAR.GUI_PosSelector({ Block_Info.x - 100,Block_Info.y }, 15, PlayerViewAngle);
				GUI_VAR.GUI_Tips({ Block_Info.x + 3,Block_Info.y }, 1, "Cloud offsets date: " + CS2_Offsets::Offsets_Date);
				const auto Block_Offsets = GUI_VAR.GUI_Block(870, 30, GUI_VAR.Window_GetSize().y - 60, "Offsets", 330);
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 1, "Update date: " + CS2_Offsets::Offsets_Date);
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 2, "dwLocalPlayerController = " + Variable::Hex_String(CS2_Offsets::dwLocalPlayerController));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 3, "dwLocalPlayerPawn = " + Variable::Hex_String(CS2_Offsets::dwLocalPlayerPawn));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 4, "dwEntityList = " + Variable::Hex_String(CS2_Offsets::dwEntityList));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 5, "dwViewAngles = " + Variable::Hex_String(CS2_Offsets::dwViewAngles));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 6, "dwViewMatrix = " + Variable::Hex_String(CS2_Offsets::dwViewMatrix));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 7, "m_hPlayerPawn = " + Variable::Hex_String(CS2_Offsets::m_hPlayerPawn));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 8, "m_iTeamNum = " + Variable::Hex_String(CS2_Offsets::m_iTeamNum));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 9, "m_ArmorValue = " + Variable::Hex_String(CS2_Offsets::m_ArmorValue));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 10, "m_iHealth = " + Variable::Hex_String(CS2_Offsets::m_iHealth));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 11, "m_iIDEntIndex = " + Variable::Hex_String(CS2_Offsets::m_iIDEntIndex));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 12, "m_fFlags = " + Variable::Hex_String(CS2_Offsets::m_fFlags));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 13, "m_iShotsFired = " + Variable::Hex_String(CS2_Offsets::m_iShotsFired));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 14, "m_vecVelocity = " + Variable::Hex_String(CS2_Offsets::m_vecVelocity));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 15, "m_bSpotted = " + Variable::Hex_String(CS2_Offsets::m_bSpotted));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 16, "m_bIsScoped = " + Variable::Hex_String(CS2_Offsets::m_bIsScoped));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 17, "m_pClippingWeapon = " + Variable::Hex_String(CS2_Offsets::m_pClippingWeapon));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 18, "m_pGameSceneNode = " + Variable::Hex_String(CS2_Offsets::m_pGameSceneNode));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 19, "m_vecOrigin = " + Variable::Hex_String(CS2_Offsets::m_vecOrigin));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 20, "m_aimPunchCache = " + Variable::Hex_String(CS2_Offsets::m_aimPunchCache));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 21, "m_vecViewOffset = " + Variable::Hex_String(CS2_Offsets::m_vecViewOffset));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 22, "m_dwBoneMatrix = " + Variable::Hex_String(CS2_Offsets::m_dwBoneMatrix));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 23, "m_iszPlayerName = " + Variable::Hex_String(CS2_Offsets::m_iszPlayerName));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 24, "m_pActionTrackingServices = " + Variable::Hex_String(CS2_Offsets::m_pActionTrackingServices));
				GUI_VAR.GUI_Text({ Block_Offsets.x - 20,Block_Offsets.y }, 25, "m_iNumRoundKills = " + Variable::Hex_String(CS2_Offsets::m_iNumRoundKills));
				//-----------------------------------------------------------------------------------------------------------------------------测试控件-------
				const auto Block_DebugControl = GUI_VAR.GUI_Block(510, 540, 280, "调试控件UTT", 330);
				GUI_VAR.GUI_Checkbox(Block_DebugControl, 1, "显示控制台窗口UTT", UI_Debug_ShowDebugWindow);
				GUI_VAR.GUI_Button_Small({ Block_DebugControl.x - 2,Block_DebugControl.y }, 1, Debug_Control_Var::ClearCommand);
				GUI_VAR.GUI_InputText<class CLASS_Block_DebugControl_1>({ Block_DebugControl.x - 15,Block_DebugControl.y }, 2, Debug_Control_Var::SystemCommand, "命令UTT");
				GUI_VAR.GUI_Button_Small({ Block_DebugControl.x - 2,Block_DebugControl.y }, 2, Debug_Control_Var::SendSystemCommand);
				GUI_VAR.GUI_Checkbox(Block_DebugControl, 3, "Checkbox 1", Debug_Control_Var::Checkbox_1);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_DebugControl_2>({ Block_DebugControl.x - 70,Block_DebugControl.y }, 3, Debug_Control_Var::KeySelector_1);
				GUI_VAR.GUI_Checkbox(Block_DebugControl, 4, "Checkbox 2", Debug_Control_Var::Checkbox_2);
				GUI_VAR.GUI_KeySelector<class CLASS_Block_DebugControl_3>({ Block_DebugControl.x - 70,Block_DebugControl.y }, 4, Debug_Control_Var::KeySelector_2);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_DebugControl_4>({ Block_DebugControl.x - 15,Block_DebugControl.y }, 5, "Slider int", -100, 100, Debug_Control_Var::Slider_1);
				GUI_VAR.GUI_Slider<float, class CLASS_Block_DebugControl_5>({ Block_DebugControl.x - 15,Block_DebugControl.y }, 6, "Slider float", -50, 50, Debug_Control_Var::Slider_2);
				GUI_VAR.GUI_Button({ Block_DebugControl.x - 15,Block_DebugControl.y }, 7, "Button 1", Debug_Control_Var::Button_1);
				GUI_VAR.GUI_Button({ Block_DebugControl.x - 15,Block_DebugControl.y }, 8, "Button 2", Debug_Control_Var::Button_2);
				GUI_VAR.GUI_Tips(Block_DebugControl, 1, "Clear console.");
				GUI_VAR.GUI_Tips(Block_DebugControl, 2, "Send command to system.");
				GUI_VAR.GUI_Tips(Block_DebugControl, 3, "GUI Draw FPS: " + to_string(GUI_VAR.Window_FPS() + System::Rand_Number(0, 1)) + "." + to_string(System::Rand_Number(100, 999)) + "  (" + to_string(GUI_VAR.Window_FPS()) + ")");//绘制GUI绘制帧数
				if (Debug_Control_Var::ClearCommand)system("cls");//清除控制台
				if (Debug_Control_Var::SendSystemCommand)//向系统发送指令
				{
					if (Debug_Control_Var::SystemCommand != "")cout << Debug_Control_Var::SystemCommand << endl;//打印控制台
					if (Variable::String_Find(Debug_Control_Var::SystemCommand, "/"))//检测是否是命令
					{
						auto Last_Send_STR = Debug_Control_Var::SystemCommand; Last_Send_STR.erase(0, 1);//擦除/
						const auto Return_String = Variable::String_Lower(Last_Send_STR);//转换小写 (自定义命令只支持小写判断)
						if (Return_String == "add checkbox")++Debug_Control_Var::Checkbox_Quantity;
						else system(Last_Send_STR.c_str());
					}
					else System::Log("Misc: Invalid command. Please add / in front of.", true);
				}
				if (Debug_Control_Var::Button_1 || Debug_Control_Var::Button_2)System::Log("Debug: Click button");
				if (Debug_Control_Var::Button_1)
				{
					System::Log("Username: " + System::Get_UserName());//打印用户名
					System::Log("Computername: " + System::Get_ComputerName());//打印用户电脑名
					System::Log("IP V4: " + System::Get_IPv4Address());//打印用户IPV4
				}
				GUI_WindowSize = { 1230,850 };
			}
			else if (UI_Panel == 4)//Setting
			{
				const auto Block_About = GUI_VAR.GUI_Block(150, 30, 160, "关于UTT");
				GUI_VAR.GUI_Text(Block_About, 1, "Rensen", GUI_VAR.Global_Get_EasyGUI_Color());
				GUI_VAR.GUI_Text({ Block_About.x + 47,Block_About.y }, 1, "for Counter-Strike 2 (免费外部)UTT", { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 2, "版本: UTT" + Variable::Float_Precision(Rensen_Version) + " 汉化版", { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 3, "发布日期: UTT" + Rensen_ReleaseDate, { 100,100,100 });
				GUI_VAR.GUI_Text(Block_About, 4, "作者: https://github.com/CosllyUTT", { 100,100,100 });
				GUI_VAR.GUI_Button_Small({ Block_About.x + 10,Block_About.y }, 4, UI_Setting_OPENLINKAuthor);
				GUI_VAR.GUI_Tips({ Block_About.x + 10,Block_About.y }, 1, "No ban record so far in 2020!!!", 0, GUI_VAR.Global_Get_EasyGUI_Color());
				const auto Block_Menu = GUI_VAR.GUI_Block(150, 210, 340, "菜单UTT");
				GUI_VAR.GUI_Text(Block_Menu, 1, "菜单开关UTT");
				GUI_VAR.GUI_KeySelector<class CLASS_Block_Menu_1>(Block_Menu, 1, UI_Setting_MenuKey);
				GUI_VAR.GUI_Checkbox(Block_Menu, 2, "自定义菜单主题色UTT", UI_Setting_CustomColor);
				GUI_VAR.GUI_ColorSelector_a(Block_Menu, 2, UI_Setting_MainColor);
				if (UI_Setting_MainColor.a < 100)UI_Setting_MainColor.a = 100;
				GUI_VAR.GUI_Slider<float, class CLASS_Block_Menu_2>(Block_Menu, 3, "菜单动画速度UTT", 1.2, 10, UI_Setting_MenuAnimation);
				GUI_VAR.GUI_Slider<int, class CLASS_Block_Menu_3>(Block_Menu, 4, "菜单字体大小UTT", 0, 30, UI_Setting_MenuFontSize, "px");
				GUI_VAR.GUI_InputText<class CLASS_Block_Menu_4>(Block_Menu, 5, UI_Setting_MenuFont, "自定义菜单字体UTT");
				GUI_VAR.GUI_Button(Block_Menu, 6, "保存配置UTT", UI_Setting_SaveLocalConfig, 20);
				if (CS2_HWND)GUI_VAR.GUI_Button(Block_Menu, 7, "关闭 CSUTT", UI_Setting_QuitCS, 20);
				else GUI_VAR.GUI_Button(Block_Menu, 7, "打开 CSUTT", UI_Setting_StartCS, 20);
				GUI_VAR.GUI_Button(Block_Menu, 8, "Github 项目链接UTT", UI_Setting_GithubRepositories, 20);
				GUI_VAR.GUI_Button(Block_Menu, 9, "重启菜单UTT", UI_Setting_RestartMenu, 20);
				GUI_VAR.GUI_Button(Block_Menu, 10, "关闭菜单UTT", UI_Setting_Unload, 20);
				GUI_VAR.GUI_Tips({ Block_Menu.x + 10,Block_Menu.y }, 6, "If you want to reset the default config you can delete Rensen.cfg in the same folder.");
				GUI_WindowSize = { 580,580 };
			}
			else if (UI_Panel == 5)//Attach
			{
				const auto Block_Size = GUI_VAR.Window_GetSize().y - 60;
				const auto Block_A = GUI_VAR.GUI_Block(150, 30, Block_Size, "Block_A");
				//A区块控件代码区域
				for (int i = 1; i <= Debug_Control_Var::Checkbox_Quantity; ++i)
				{
					GUI_VAR.GUI_Checkbox(Block_A, i, "Checkbox " + to_string(i), Debug_Control_Var::Checkbox_Value[i]);
				}

				const auto Block_B = GUI_VAR.GUI_Block(580, 30, Block_Size, "Block_B");
				//B区块控件代码区域

				GUI_WindowSize = { 1010,900 };
			}
			GUI_VAR.Draw_GUI(Debug_Control_Var::Checkbox_2);//最终绘制GUI画板
			if (UI_Misc_SavePerformance)Sleep(5);//节省电脑占用性能
			if (true)//按钮事件接收
			{
				if (UI_Visual_Res_2560)Window::Set_Resolution(2560, 1440);//设置显示器像素
				else if (UI_Visual_Res_1920)Window::Set_Resolution(1920, 1080);
				else if (UI_Visual_Res_1280)Window::Set_Resolution(1280, 1024);
				else if (UI_Visual_Res_960)Window::Set_Resolution(1280, 960);
				if (UI_Misc_LoadCloudConfig)//加载Github上的云参数
				{
					const auto Config_ID = UI_Misc_SelectedConfig;//防止套用的参数套写变量
					if (UI_Misc_SelectedConfig == 0)LoadCloudConfig("Legit");
					else if (UI_Misc_SelectedConfig == 1)LoadCloudConfig("Rage");
					else if (UI_Misc_SelectedConfig == 2)LoadCloudConfig("Legit No Visual");
					System::Log("Misc: LoadCloudConfig [" + to_string(Config_ID) + "]");
				}
				if (UI_Setting_OPENLINKAuthor)//打开作者Github主题页面
				{
					System::Open_Website("https://github.com/Coslly");
					System::Log("Setting: OpenGithubURL");
				}
				if (UI_Setting_SaveLocalConfig || (System::Get_Key(VK_LCONTROL) && System::Get_Key_Onest(0x53)))//保存当前所设置的参数
				{
					SaveLocalConfig();
					System::Log("Setting: SaveConfig");
				}
				if (UI_Setting_StartCS)//启动CS
				{
					if (CS2_MEM.Get_ProcessHWND() == 0)System::Open_Website("steam://rungameid/730");
					System::Log("Setting: StartCS");
				}
				else if (UI_Setting_QuitCS)//关闭CS
				{
					if (CS2_MEM.Get_ProcessHWND() != 0)Window::Kill_Window(CS2_MEM.Get_ProcessHWND());
					System::Log("Setting: QuitCS");
				}
				if (UI_Setting_GithubRepositories)//打开Github项目地址
				{
					System::Open_Website("https://github.com/Coslly/Rensen");
					System::Log("Setting: GithubRepositories");
				}
				if (UI_Setting_RestartMenu)//重启菜单
				{
					System::Log("Setting: RestartMenu");
					System::Self_Restart();
				}
				if (UI_Setting_Unload)//关闭菜单
				{
					Window::NVIDIA_Overlay();
					System::Log("Setting: Unload");
					exit(0);
				}
			}
		}
	}
}
void Thread_Misc() noexcept//杂项线程 (一些菜单事件处理和杂项功能)
{
	System::Log("Load Thread: Thread_Misc()");
	Window::Windows Window_Watermark; const auto Window_Watermark_HWND = Window_Watermark.Create_RenderBlock_Alpha(Window::Get_Resolution().x, 50, "Rensen - Watermark");//创建水印透明窗口
	Window::Render Window_Watermark_Render; Window_Watermark_Render.CreatePaint(Window_Watermark_HWND, 0, 0, Window::Get_Resolution().x, 50);
	Window::Windows Window_NightMode; Window_NightMode.Create_RenderBlock(Window::Get_Resolution().x, Window::Get_Resolution().y, "Rensen - NightMode");//夜晚模式窗口
	Window_Watermark.Show_Window();//将水印修改为最前端绘制覆盖窗口
	ReLoad(true);//刷新CS2_SDK内存数据 (快速初始化)
	while (true)
	{
		ReLoad();//刷新CS2_SDK内存数据
		Global_TeamCheck = UI_Misc_TeamCheck;//队伍判断(文件跨越修改变量)
		if (UI_Misc_LockGameWindow && !Menu_Open)SetForegroundWindow(CS2_HWND);//锁定CS窗口到最前端
		if (UI_Debug_ShowDebugWindow)
		{
			Window::Show_ConsoleWindow();//显示控制台
			Window::Set_Topmost_Status(GetConsoleWindow(), true);//将控制台窗口改为最前端
		}
		else Window::Hide_ConsoleWindow();//隐藏控制台
		//----------------------------------------------------------------------------------------------------------------------------------------
		if (UI_Misc_Watermark)//水印
		{
			Window::Set_LimitWindowShow(Window_Watermark.Get_HWND(), UI_Misc_ByPassOBS);//绕过OBS
			Window_Watermark.Set_WindowPos(0, 0);//水印窗口默认坐标
			if (System::Sleep_Tick<class CLASS_WaterMark_WindowReload_Delay_>(200))//降低CPU占用
			{
				Window_Watermark.Set_WindowTitle(System::Rand_String(10));//随机水印窗口标题
				static string WaterMark_String = "";
				short WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 4.85;
				if (!CS2_HWND)WaterMark_String = "Rensen | CS not found | " + System::Get_UserName() + " | " + System::Time_String();
				else { WaterMark_String = "Rensen | " + System::Get_UserName() + " | " + System::Time_String(); WaterMark_String_Size = strlen(WaterMark_String.c_str()) * 5.2; }
				const Variable::Vector2 Watermark_Pos = { Window::Get_Resolution().x - WaterMark_String_Size - 10,10 };
				Window_Watermark_Render.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });
				Window_Watermark_Render.RenderA_SolidRect(Watermark_Pos.x, Watermark_Pos.y, WaterMark_String_Size, 15, { 1,1,1,130 });
				if (UI_Setting_CustomColor)
				{
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x, Watermark_Pos.y, WaterMark_String_Size / 2, 1, GUI_IO.GUIColor.D_Alpha(255) / 2, GUI_IO.GUIColor.D_Alpha(255));
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x + WaterMark_String_Size / 2, Watermark_Pos.y, WaterMark_String_Size / 2, 1, GUI_IO.GUIColor.D_Alpha(255), GUI_IO.GUIColor.D_Alpha(255) / 2);
				}
				else {
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x, Watermark_Pos.y, WaterMark_String_Size / 2, 1, { GUI_IO.GUIColor_Rainbow[0], GUI_IO.GUIColor_Rainbow[1], GUI_IO.GUIColor_Rainbow[2],255 }, { GUI_IO.GUIColor_Rainbow[3], GUI_IO.GUIColor_Rainbow[4], GUI_IO.GUIColor_Rainbow[5],255 });
					Window_Watermark_Render.RenderA_GradientRect(Watermark_Pos.x + WaterMark_String_Size / 2, Watermark_Pos.y, WaterMark_String_Size / 2, 1, { GUI_IO.GUIColor_Rainbow[3], GUI_IO.GUIColor_Rainbow[4], GUI_IO.GUIColor_Rainbow[5],255 }, { GUI_IO.GUIColor_Rainbow[6], GUI_IO.GUIColor_Rainbow[7], GUI_IO.GUIColor_Rainbow[8],255 });
				}
				Window_Watermark_Render.Render_String(Watermark_Pos.x + 4, Watermark_Pos.y + 2, WaterMark_String, "Small Fonts", 12, { 255,255,255 }, false);
				if (Menu_Open)//菜单开启时
				{
					Window_Watermark_Render.RenderA_SmpStr(2, 2, "Release " + Rensen_ReleaseDate, GUI_IO.GUIColor.D_Alpha(200), { 1,0,0,130 });//编译日期绘制
					Window_Watermark_Render.RenderA_SmpStr(2, 2 + 14, "Offsets " + CS2_Offsets::Offsets_Date, GUI_IO.GUIColor.D_Alpha(200), { 1,0,0,130 });//云偏移更新日期绘制
				}
				Window_Watermark_Render.DrawPaint(true);
			}
		}
		else Window_Watermark.Set_WindowPos(99999, 99999);//将窗口移至边界外来代替隐藏窗口
		//----------------------------------------------------------------------------------------------------------------------------------------
		static auto NightMode_Alpha = 0; const auto NightMode_Alpha_Ani = Variable::Animation<class CLASS_NightMode_Window_AlphaAnimation_>(NightMode_Alpha, 5);//夜晚模式透明度动画
		if (UI_Misc_NightMode && (Global_IsShowWindow || Menu_Open))
		{
			Window::Set_LimitWindowShow(Window_NightMode.Get_HWND(), UI_Misc_ByPassOBS);//绕过OBS
			Variable::Vector4 BackGround_Color = { 0,0,10 }; if (Menu_Open)BackGround_Color = GUI_IO.GUIColor / 10;//菜单外部背景色
			Window_NightMode.BackGround_Color(Variable::Animation_Vec4<class CLASS_NIGHTMODE_BACKGROUNDCOLOR_ANI_>(BackGround_Color));//绘制颜色背景板
			if (System::Sleep_Tick<class CLASS_NightMode_Window_Sleep_>(500))//降低CPU占用 (窗口标题,消息循环)
			{
				Window_NightMode.Set_WindowTitle(System::Rand_String(10));//随机夜晚模式窗口标题
				Window_NightMode.Fix_inWhile();//夜晚模式消息循环
			}
			NightMode_Alpha = UI_Misc_NightMode_Alpha;
		}
		else NightMode_Alpha = 0;
		if (NightMode_Alpha_Ani <= 0)MoveWindow(Window_NightMode.Get_HWND(), 0, 0, 0, 0, true);//透明度等于0的时候隐藏窗口
		else MoveWindow(Window_NightMode.Get_HWND(), 0, 0, Window::Get_Resolution().x, Window::Get_Resolution().y, true);//放大窗口
		Window_NightMode.Set_WindowAlpha(NightMode_Alpha_Ani);//夜晚模式修改透明度
		//----------------------------------------------------------------------------------------------------------------------------------------
		if (CS2_HWND && Global_IsShowWindow && Global_LocalPlayer.Health())//一些杂项功能
		{
			const auto Local_Pos = Global_LocalPlayer.Origin();//本地人物坐标
			const auto Local_ActiveWeaponID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器ID
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_HitSound)//击打音效
			{
				static auto OldDamage = 0; static auto OldKill = 0;
				const auto Damage = Advanced::Local_RoundDamage();//伤害
				const auto Kill = Advanced::Local_RoundDamage(true);//击杀
				if (Damage != OldDamage)//当伤害或是击杀值变化则返回
				{
					if (Kill > OldKill)Beep(UI_Misc_HitSound_Tone * 2, UI_Misc_HitSound_Length);//Kill
					else if (Damage > OldDamage)Beep(UI_Misc_HitSound_Tone, UI_Misc_HitSound_Length);//Hit
					OldDamage = Damage; OldKill = Kill;
				}
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_AutoKnife && (UI_Misc_AutoKnife_Key == 0 || System::Get_Key(UI_Misc_AutoKnife_Key)) && (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500))//自动刀
			{
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
					const auto Player_Pos = PlayerPawn.Origin();//敌人坐标
					const auto Angle = Variable::CalculateAngle(Local_Pos + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(3), Base::ViewAngles());
					if (Variable::Coor_Dis_3D(Local_Pos, Player_Pos) <= 70 && hypot(Angle.x, Angle.y) <= 40)//判断距离(世界坐标, 本地人物视角)
					{
						if ((PlayerPawn.Health() <= 55 && PlayerPawn.Health() > 30) || Variable::Dif_Value_Ran<float>(Base::ViewAngles().y, PlayerPawn.ViewAngles().y, 50))//血量判断重刀还是轻刀
						{
							ExecuteCommand("+attack2");
							Sleep(1);
							ExecuteCommand("-attack2");
						}
						else {
							ExecuteCommand("+attack");
							Sleep(1);
							ExecuteCommand("-attack");
						}
						Sleep(1);
						ExecuteCommand("+lookatweapon");
						Sleep(1);
						ExecuteCommand("-lookatweapon");
					}
				}
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_AutoTaser && (UI_Misc_AutoTaser_Key == 0 || System::Get_Key(UI_Misc_AutoTaser_Key)) && Local_ActiveWeaponID == 31)//自动电击枪
			{
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
					const auto Player_Pos = PlayerPawn.Origin();//敌人坐标
					if (Variable::Coor_Dis_3D(Local_Pos, Player_Pos) <= 130 && PlayerPawn.Pawn() == Global_LocalPlayer.IDEntIndex_Pawn().Pawn())//判断距离 && 瞄准
					{
						ExecuteCommand("+attack");
						Sleep(1);
						ExecuteCommand("-attack");
					}
				}
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_AntiAFKKick && System::Sleep_Tick<class CLASS_MISC_ANTIAFKKICK_>(5000)) { System::Mouse_Move(1, 0); Sleep(1); System::Mouse_Move(-1, 0); }//防止挂机踢出游戏脚本
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_QuickStop)//自动快速急停
			{
				const auto Trigger_Value = 20;//急停终止速度
				if (!(System::Get_Key(0x57) || System::Get_Key(0x41) || System::Get_Key(0x44) || System::Get_Key(0x53) || System::Get_Key(VK_SPACE)) && Global_LocalPlayer.MoveSpeed() > Trigger_Value && Global_LocalPlayer.Flags() & (1 << 0))
				{
					for (int i = 0; i <= 3; ++i)//遍历 (为了精准急停)
					{
						if (Global_LocalPlayer.MoveSpeed() <= Trigger_Value)continue;//每次遍历都检查速度
						const auto LocalVel = Global_LocalPlayer.Velocity();
						const auto LocalYaw = Base::ViewAngles().y;
						const auto X = (LocalVel.x * cos(LocalYaw / 180 * 3.1415926) + LocalVel.y * sin(LocalYaw / 180 * 3.1415926));
						const auto Y = (LocalVel.y * cos(LocalYaw / 180 * 3.1415926) - LocalVel.x * sin(LocalYaw / 180 * 3.1415926));
						if (X > Trigger_Value) { ExecuteCommand("+back"); Sleep(1); ExecuteCommand("-back"); }
						else if (X < -Trigger_Value) { ExecuteCommand("+forward"); Sleep(1); ExecuteCommand("-forward"); }
						if (Y > Trigger_Value) { ExecuteCommand("+right"); Sleep(1); ExecuteCommand("-right"); }
						else if (Y < -Trigger_Value) { ExecuteCommand("+left"); Sleep(1); ExecuteCommand("-left"); }
					}
				}
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_AutoKillCeasefire)//击杀时自动停止开火
			{
				static auto OldKill = 0; const auto Kill = Advanced::Local_RoundDamage(true);//击杀
				if (OldKill != Kill) { if (Kill > OldKill)ExecuteCommand("-attack"); OldKill = Kill; }//当击杀值变化则返回停止开火
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Misc_CursorESP && System::Get_Key(UI_Misc_CursorESP_Key))//鼠标光标透视 (为了支持全屏模式透视)
			{
				const auto Local_ViewMatrix = Base::ViewMatrix();//本地人物视角矩阵
				const auto CS_Scr_Res = Window::Get_WindowResolution(CS2_HWND);//游戏窗口大小
				for (short i = 0; i < Global_ValidClassID.size(); ++i)//人物ID遍历
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
					if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
					const auto PlayerPos_Scr = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(4), Local_ViewMatrix);//躯干屏幕坐标
					if (PlayerPos_Scr.x < 0 || PlayerPos_Scr.x > CS_Scr_Res.r)continue;//检测指定坐标是否在屏幕内
					System::Set_MousePos({ (int)PlayerPos_Scr.x + CS_Scr_Res.b,(int)PlayerPos_Scr.y + CS_Scr_Res.a });//最终修改光标坐标鼠标坐标
					Sleep(5);//光标停留更久
				}
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			if (UI_Spoof_Spoof)//恶搞功能
			{
				//--------------------------------------
				if (UI_Spoof_AimbotTeam && System::Get_Key(UI_Spoof_AimbotTeam_Key))//瞄准队友
				{
					float Aim_Range = 10;//瞄准范围
					for (short i = 0; i < Global_ValidClassID.size(); ++i)//人物ID遍历
					{
						const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
						if (PlayerPawn.Pawn() == Global_LocalPlayer.Pawn() || !PlayerPawn.Health() || PlayerPawn.TeamNumber() != Global_LocalPlayer.TeamNumber())continue;//检查是否队友
						const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(6), Base::ViewAngles() + Global_LocalPlayer.AimPunchAngle() * 2);
						const auto Fov = hypot(Angle.x, Angle.y);
						if (!Angle.IsZero() && Fov <= Aim_Range) { Aim_Range = Fov; System::Mouse_Move(-Angle.y * (30 - UI_Spoof_AimbotTeam_Smooth), Angle.x * (30 - UI_Spoof_AimbotTeam_Smooth)); }
					}
					const auto TargetPawn = Global_LocalPlayer.IDEntIndex_Pawn();//瞄准到的人物Pawn //防止瞄准到敌人
					if (Advanced::Check_Enemy(TargetPawn))//基础人物判断
					{
						const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), TargetPawn.BonePos(0), Base::ViewAngles() + Global_LocalPlayer.AimPunchAngle() * 2);
						if (hypot(Angle.x, Angle.y) <= Aim_Range)System::Mouse_Move(Angle.y * 10, 0);
					}
				}
				//--------------------------------------
				if (UI_Spoof_IncreaseRecoil && System::Get_ValueBigger<int, class CLASS_MISC_Spoof_IncreaseRecoil_>(Global_LocalPlayer.ShotsFired()))System::Mouse_Move(0, -1 * UI_Spoof_IncreaseRecoil_Value);//加强后坐力
				//--------------------------------------
				if (UI_Spoof_DropC4 && Global_LocalPlayer.ActiveWeapon() == 49)ExecuteCommand("drop");//无法拾取C4
				//--------------------------------------
				if (UI_Spoof_FakeAntiAim && System::Get_Key(UI_Spoof_FakeAntiAim_Key))Advanced::Move_to_Angle(9999, 9999);//陀螺
				//--------------------------------------
				if (UI_Spoof_KillDropSniper)//丢枪狙
				{
					static auto OldKill = 0; const auto Kill = Advanced::Local_RoundDamage(true);//击杀
					if (Kill > OldKill && Global_LocalPlayer.ActiveWeapon(true) == 3 && Global_LocalPlayer.ShotsFired() == 1)ExecuteCommand("drop");//丢弃武器
					if (Kill != OldKill)OldKill = Kill;
				}
				//--------------------------------------
				static BOOL IS_LearnPlayer = false;//释放按键判断变量
				if (UI_Spoof_LearnPlayer && System::Get_Key(UI_Spoof_LearnPlayer_Key))//模仿最近玩家
				{
					IS_LearnPlayer = true; struct RecPla { Base::PlayerPawn Pawn = { 0 }; int Dis = 99999; }; RecPla RecentPlayer;//最近的玩家结构体变量
					for (short i = 0; i < Global_ValidClassID.size(); ++i)//遍历计算最近玩家
					{
						const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
						if (PlayerPawn.Pawn() == Global_LocalPlayer.Pawn())continue;//过滤本地人物
						const auto For_Dis = Variable::Coor_Dis_3D(Global_LocalPlayer.Origin(), PlayerPawn.Origin());
						if (RecentPlayer.Dis > For_Dis) { RecentPlayer.Dis = For_Dis; RecentPlayer.Pawn = PlayerPawn; }
					}
					if (RecentPlayer.Dis <= 1000)//超出范围则不执行 (因为跟不上)
					{
						Advanced::Move_to_Angle(RecentPlayer.Pawn.ViewAngles(), 2, 1, 1);//学习玩家朝向角度
						Advanced::Move_to_Pos(RecentPlayer.Pawn.Origin());//移动到玩家
					}
				}
				else if (IS_LearnPlayer == true)//释放按键
				{
					ExecuteCommand("-forward");
					ExecuteCommand("-right");
					ExecuteCommand("-back");
					ExecuteCommand("-left");//释放所有按键
					IS_LearnPlayer = false;
				}
				//--------------------------------------
				static auto Old_Angle = Base::ViewAngles();//原始视角坐标 (要返回的坐标)
				if (UI_Spoof_FakeRageBot && System::Get_Key(UI_Spoof_FakeRageBot_Key))//对某玩家实施暴力瞄准
				{
					for (int i = 0; i <= 64; ++i)//遍历人物ID
					{
						if (!System::Get_Key(UI_Spoof_FakeRageBot_Key))continue;//修复延时开枪
						if (UI_Spoof_FakeRageBot_Target && i != UI_Spoof_FakeRageBot_Target)continue;//任何目标判定
						const auto Target = Advanced::Traverse_Player(i);
						if (Target.Health() && Target.Pawn() != Global_LocalPlayer.Pawn() && Target.TeamNumber() != 1)//目标活着 && 不是本地人物
						{
							const auto Aim_Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), Target.BonePos(6), Global_LocalPlayer.AimPunchAngle() * 2);//计算要瞄准的目标视角坐标
							Advanced::Move_to_Angle(Aim_Angle, 40, 0.1);//将视角移动到目标位置
							if (Global_LocalPlayer.IDEntIndex_Pawn().Pawn() == Target.Pawn())//检查是否瞄准到
							{
								ExecuteCommand("+attack");
								Sleep(1);
								ExecuteCommand("-attack");
								Sleep(100);//防止重复冲突
							}
							Advanced::Move_to_Angle(Old_Angle);//将视角移动到出发点位置 实现fake静默XD
						}
					}
				}
				else Old_Angle = Base::ViewAngles();//刷新原坐标
				//--------------------------------------
			}
			//----------------------------------------------------------------------------------------------------------------------------------------
			Sleep(1);//降低CPU占用
		}
		else Sleep(20);//降低CPU占用
	}
}
void Thread_Funtion_BunnyHop() noexcept//功能线程: 连跳
{
	System::Log("Load Thread: Thread_Funtion_BunnyHop()");
	while (true)
	{
		if (CS2_HWND && Global_IsShowWindow && Global_LocalPlayer.Health() && UI_Misc_BunnyHop && System::Get_Key(VK_SPACE))
		{
			if (Global_LocalPlayer.Flags() & (1 << 0))//当本地人物触及到地面跳跃
			{
				ExecuteCommand("+jump");//跳跃!!!
				Sleep(1);
				ExecuteCommand("-jump");
			}
			Sleep(1);
		}
		else Sleep(20);
	}
}
void Thread_Funtion_Aimbot() noexcept//功能线程: 瞄准机器人
{
	System::Log("Load Thread: Thread_Funtion_Aimbot()");
	while (true)
	{
		if (CS2_HWND && Global_IsShowWindow && Global_LocalPlayer.Health() && UI_Legit_Aimbot && System::Get_Key(UI_Legit_Aimbot_Key))
		{
			System::Sleep_ns(1000);//比Sleep更快的函数为了更加自然平滑
			static short Aim_Range, Aim_Parts; static float Aim_Smooth;//瞄准范围,瞄准部位,瞄准平滑度
			BOOL SpottedPlayer_Quantity = false;//是否有实体暴露 (用于优先瞄准暴露的实体)
			const auto LocalPlayer_ActiveWeapon_ID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器ID
			const auto LocalPlayer_ActiveWeapon_Type = Global_LocalPlayer.ActiveWeapon(true);//本地人物手持武器类型
			if (LocalPlayer_ActiveWeapon_Type == 1)//手枪
			{
				if (UI_Legit_Armory_BodyAim_PISTOL)Aim_Parts = 3; else Aim_Parts = 6;
				Aim_Range = UI_Legit_Armory_Range_PISTOL / 5;
				Aim_Smooth = 40 - UI_Legit_Armory_Smooth_PISTOL - 2;
			}
			else if (LocalPlayer_ActiveWeapon_Type == 2)//步枪
			{
				if (UI_Legit_Armory_BodyAim_RIFLE)Aim_Parts = 3; else Aim_Parts = 6;
				Aim_Range = UI_Legit_Armory_Range_RIFLE / 5;
				Aim_Smooth = 40 - UI_Legit_Armory_Smooth_RIFLE - 2;
			}
			else if (LocalPlayer_ActiveWeapon_Type == 3)//狙击枪
			{
				if (UI_Legit_Armory_BodyAim_SNIPER)Aim_Parts = 3; else Aim_Parts = 6;
				Aim_Range = UI_Legit_Armory_Range_SNIPER / 5;
				Aim_Smooth = 40 - UI_Legit_Armory_Smooth_SNIPER - 2;
			}
			else if (LocalPlayer_ActiveWeapon_Type == 4)//霰弹枪
			{
				if (UI_Legit_Armory_BodyAim_SHOTGUN)Aim_Parts = 3; else Aim_Parts = 6;
				Aim_Range = UI_Legit_Armory_Range_SHOTGUN / 5;
				Aim_Smooth = 40 - UI_Legit_Armory_Smooth_SHOTGUN - 2;
			}
			else continue;//如果是无效的武器则重新来过(刀,道具,电击枪等)
			if (Aim_Range == 0)continue;//范围为0时则重新来过
			if (Aim_Smooth == 0)Aim_Smooth = 1;//最小平滑度
			const auto Local_AimPunchAngle = Global_LocalPlayer.AimPunchAngle();
			Aim_Range = Aim_Range + -Local_AimPunchAngle.x;
			static Variable::Vector3 Recoil_Angle;//后坐力角度
			if (UI_Legit_Aimbot_RemoveRecoil)Recoil_Angle = Base::ViewAngles() + Local_AimPunchAngle * 2;//移除后坐力
			else Recoil_Angle = Base::ViewAngles();
			const auto CrosshairId = Advanced::Check_Enemy(Global_LocalPlayer.IDEntIndex_Pawn());//瞄准的实体Pawn
			float minFovG = 255;
			Variable::Vector3 targetAngle = { 0,0,0 };
			// 遍历优先瞄准暴露的实体
			for (short i = 0; i < Global_ValidClassID.size(); ++i) {
				if (SpottedPlayer_Quantity) continue; // 如果有了暴露的实体则直接返回
				const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]); // 遍历的人物Pawn
				if (!Advanced::Check_Enemy(PlayerPawn)) continue; // 队伍判断
				const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(Aim_Parts), Recoil_Angle); // 最终瞄准角度
				if (hypot(Angle.x, Angle.y) <= Aim_Range && PlayerPawn.Spotted()) {

					SpottedPlayer_Quantity = true;
				}
			}

			// 遍历所有目标，找到FovG最小的目标
			for (short i = 0; i < Global_ValidClassID.size(); ++i) {
				const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]); // 遍历的人物Pawn
				if (!Advanced::Check_Enemy(PlayerPawn) || (UI_Legit_Aimbot_TriggerOnAim && !CrosshairId) || ((UI_Legit_Aimbot_JudgingWall || SpottedPlayer_Quantity) && !PlayerPawn.Spotted())) continue;
				if (LocalPlayer_ActiveWeapon_Type == 4 && Variable::Coor_Dis_3D(PlayerPawn.Origin(), Global_LocalPlayer.Origin()) > UI_Legit_Armory_TriggerDistance_SHOTGUN) continue; // 霰弹枪最大触发范围
				if (UI_Legit_Armory_HitSiteParser && PlayerPawn.Health() <= 20) Aim_Parts = 4; // 部位解析器 (粗制滥造)
				Variable::Vector3 Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(Aim_Parts), Recoil_Angle); // 最终瞄准角度
				float FovG = hypot(Angle.x, Angle.y); // 圆圈范围计算

				if (!Angle.IsZero() && FovG <= Aim_Range) { // 范围判断

					{
						if (FovG < minFovG) {
							minFovG = FovG;
							targetAngle = Angle;
						}
					}
				}
			}
			// 瞄准FovG最小的目标
			if (!targetAngle.IsZero()) {
				float TarFovG = hypot(targetAngle.x, targetAngle.y); // 圆圈范围计算
				if (TarFovG >= 0.0015) //死区，防止低平滑设置瞄准时屏幕大幅晃动
				{
					if (Global_LocalPlayer.Scoped() && LocalPlayer_ActiveWeapon_Type == 3) System::Mouse_Move(-targetAngle.y * Aim_Smooth * 3.5, targetAngle.x * Aim_Smooth * 3.5); // 加快开镜时灵敏度
					else System::Mouse_Move(-targetAngle.y * Aim_Smooth, targetAngle.x * Aim_Smooth);
					if (UI_Legit_Aimbot_AutoShoot && CrosshairId && (!UI_Legit_Aimbot_AutoStop || LocalPlayer_ActiveWeapon_Type == 4 || Advanced::Stop_Move()) && minFovG <= 1.8) { // AutoShoot & AutoStop
						if (LocalPlayer_ActiveWeapon_Type == 3 && LocalPlayer_ActiveWeapon_ID != 11 && LocalPlayer_ActiveWeapon_ID != 38) System::Key_Con(UI_Legit_Aimbot_Key, false); // 单发狙击枪射击后释放触发按键
						if (UI_Legit_Aimbot_AutoScope && LocalPlayer_ActiveWeapon_Type == 3 && !Global_LocalPlayer.Scoped()) { // 自动开镜
							ExecuteCommand("+attack2");
							Sleep(1);
							ExecuteCommand("-attack2");
							Sleep(100); // 待扩散稳定
						}
						ExecuteCommand("+attack");
						if (LocalPlayer_ActiveWeapon_ID == 64) Sleep(250); // R8左轮无法开枪修复
						else Sleep(1);
						ExecuteCommand("-attack");
						if (UI_Legit_Aimbot_Key == 2 && LocalPlayer_ActiveWeapon_Type == 1) System::Mouse_Con(2, false); // 自瞄按键在右键且是手枪则脚本持续开火状态 (可有可无)						
						if (Global_LocalPlayer.ShotsFired() != 0) Sleep(UI_Legit_Aimbot_AutoShootDelay); // 自动开枪延迟 (缓解后座力)
					}
				}
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_AdaptiveAimbot() noexcept//功能线程: 生物瞄准机器人(更加自然的效果)
{
	System::Log("Load Thread: Thread_Funtion_AdaptiveAimbot()");
	while (true)
	{
		if (CS2_HWND && Global_IsShowWindow && Global_LocalPlayer.Health() && UI_Legit_AdaptiveAimbot && System::Get_Key(VK_LBUTTON) && Global_LocalPlayer.ActiveWeapon(true) == 2)//当CS窗口在最前端 && 本地人物活着 && 按键按下 && 步枪
		{
			System::Sleep_ns(2000);//比Sleep更快的函数为了更加自然平滑
			float Aim_Range = 3; int Aim_Bone = 6; const auto PunchAngle = Global_LocalPlayer.AimPunchAngle();
			if (abs(PunchAngle.x) * 2 >= Aim_Range)Aim_Range = abs(PunchAngle.x) * 1.5;//计算开枪之后附加后坐力的范围
			for (short i = 0; i < Global_ValidClassID.size(); ++i)//人物ID遍历
			{
				const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
				if (!Advanced::Check_Enemy(PlayerPawn) || !PlayerPawn.Spotted())continue;//当没有被发现则重新来过
				if (PlayerPawn.Health() <= 60)Aim_Bone = 4;//低血时瞄准躯干 (降低爆头率)
				const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(Aim_Bone), Base::ViewAngles() + PunchAngle * 2);//最终瞄准角度 (6: 头部)
				const auto FovG = hypot(Angle.x, Angle.y);//圆圈范围计算
				if (!Angle.IsZero() && FovG <= Aim_Range)//范围判断
				{
					Aim_Range = FovG;//防止锁住两个或多个人
					if (Global_LocalPlayer.ShotsFired() > 1 && FovG <= Aim_Range / 2 && PlayerPawn.MoveSpeed() <= 150)System::Mouse_Move(-Angle.y * 30, Angle.x * 30);
					else System::Mouse_Move(-Angle.y * (20 - UI_Legit_AdaptiveAimbot_InitialSmooth), Angle.x * (20 - UI_Legit_AdaptiveAimbot_InitialSmooth));
				}
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_Triggerbot() noexcept//功能线程: 自动扳机
{
	System::Log("Load Thread: Thread_Funtion_Triggerbot()");
	while (true)
	{
		if (CS2_HWND && Global_IsShowWindow && Global_LocalPlayer.Health() && UI_Legit_Triggerbot && System::Get_Key(UI_Legit_Triggerbot_Key))//当CS窗口在最前端 && 本地人物活着 && 按键按下
		{
			System::Sleep_ns(500);//纳秒级延时
			const auto Local_ActiveWeaponID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器序号
			if (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500 || Local_ActiveWeaponID == 31)continue;//过滤特殊武器 (刀子, 电击枪)
			else if (((UI_Legit_Triggerbot_AnyTarget && Global_LocalPlayer.IDEntIndex() != -1) || Advanced::Check_Enemy(Global_LocalPlayer.IDEntIndex_Pawn())) && (!UI_Legit_Triggerbot_ShootWhenAccurate || Global_LocalPlayer.ActiveWeapon(true) == 1 || Global_LocalPlayer.ActiveWeapon(true) == 4 || Advanced::Stop_Move(50, false)))
			{
				ExecuteCommand("+attack");//Shoot!! 开枪!!
				Sleep(UI_Legit_Triggerbot_ShootDuration);
				ExecuteCommand("-attack");
				Sleep(UI_Legit_Triggerbot_ShootDelay);
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_AssisteAim() noexcept//功能线程: 精确瞄准
{
	System::Log("Load Thread: Thread_Funtion_AssisteAim()");
	while (true)
	{
		if (CS2_HWND && Global_IsShowWindow && Global_LocalPlayer.Health())//当CS窗口在最前端 && 本地人物活着
		{
			System::Sleep_ns(5000);//纳秒级延时 (加快循环速度)
			if (UI_Legit_PreciseAim)//精确瞄准
			{
				const auto Local_ActiveWeaponID = Global_LocalPlayer.ActiveWeapon();//本地人物手持武器ID
				if (Local_ActiveWeaponID == 42 || Local_ActiveWeaponID == 59 || Local_ActiveWeaponID >= 500) { ExecuteCommand("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity)); Sleep(10); continue; }//过滤特殊武器 (刀类)
				if (Advanced::Check_Enemy(Global_LocalPlayer.IDEntIndex_Pawn()))ExecuteCommand("m_yaw " + to_string(UI_Legit_PreciseAim_EnableSensitivity));
				else ExecuteCommand("m_yaw " + to_string(UI_Legit_PreciseAim_DefaultSensitivity));
			}
			if (UI_Legit_MagnetAim && System::Is_MousePos_InMid(CS2_HWND) && !System::Get_Key(VK_LBUTTON) && Global_LocalPlayer.ActiveWeapon() != 0)//磁吸瞄准
			{
				Sleep(1);//降低CPU占用
				float Aim_Range = UI_Legit_MagnetAim_Range / 5;//瞄准范围
				for (short i = 0; i < Global_ValidClassID.size(); ++i)//人物ID遍历
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);//遍历的人物Pawn
					if (!Advanced::Check_Enemy(PlayerPawn) || !PlayerPawn.Spotted())continue;//简单的实体判断
					const auto Angle = Variable::CalculateAngle(Global_LocalPlayer.Origin() + Global_LocalPlayer.ViewOffset(), PlayerPawn.BonePos(6), Base::ViewAngles());
					const auto Fov = hypot(Angle.x, Angle.y);
					if (!Angle.IsZero() && Fov <= Aim_Range && Fov >= 1.5) { Aim_Range = Fov; System::Mouse_Move(-Angle.y * (7.f - UI_Legit_MagnetAim_Smooth), Angle.x * (7.f - UI_Legit_MagnetAim_Smooth)); }
				}
			}
		}
		else Sleep(20);
	}
}
void Thread_Funtion_RemoveRecoil() noexcept//功能线程: 移除后坐力
{
	System::Log("Load Thread: Thread_Funtion_RemoveRecoil()");
	while (true)
	{
		if (CS2_HWND && Global_IsShowWindow && UI_Legit_RemoveRecoil && Global_LocalPlayer.Health() && System::Get_Key(VK_LBUTTON))//移除后坐力
		{
			static auto OldPunch = Variable::Vector3{};
			if (Global_LocalPlayer.ShotsFired() >= UI_Legit_RemoveRecoil_StartBullet)//判断开出的子弹数
			{
				const auto AimPunch = Global_LocalPlayer.AimPunchAngle();//原始后坐力角度
				auto NewPunch = Variable::Vector3{ OldPunch.x - AimPunch.x * 2,OldPunch.y - AimPunch.y * 2,0 };//计算后坐力之后的角度
				if (UI_Legit_RemoveRecoil_LateralRepair)NewPunch.x = 0;//只处理X坐标
				System::Mouse_Move(-NewPunch.y * UI_Legit_RemoveRecoil_Sensitive, NewPunch.x * (UI_Legit_RemoveRecoil_Sensitive / 2 + 5));//修改计算后坐力之后的角度
				OldPunch = AimPunch * 2;
			}
			else OldPunch = { 0,0,0 };
			Sleep(1);
		}
		else Sleep(20);
	}
}
void Thread_Funtion_PlayerESP() noexcept//功能线程: 透视和一些视觉杂项
{
	System::Log("Load Thread: Thread_Funtion_PlayerESP()");
	auto Rensen_ESP_RenderWindow = Window::NVIDIA_Overlay({ 0,0 }, false);//初始化英伟达覆盖
	Window::Windows SpareRenderWindow;
	if (!Rensen_ESP_RenderWindow)//当没有找到英伟达覆盖时 (不是英伟达显卡)
	{
		System::Log("Error: NVIDIA overlay window not found (Used Generate Alternative Window instead)", true);//未找到英伟达覆盖时报错
		Rensen_ESP_RenderWindow = SpareRenderWindow.Create_RenderBlock_Alpha(0, 0, "NVIDIA Overlay");//创建代替覆盖窗口
	}
	Window::Render ESP_Paint; ESP_Paint.CreatePaint(Rensen_ESP_RenderWindow, 0, 0, Window::Get_Resolution().x, Window::Get_Resolution().y);//创建内存画板
	while (true)
	{
		Sleep(UI_Visual_ESP_DrawDelay);//降低CPU占用
		if (SpareRenderWindow.Get_HWND())SpareRenderWindow.Fix_inWhile();//当已创建窗口时进入消息循环
		const auto CS_Scr_Res = Window::Get_WindowResolution(CS2_HWND);
		MoveWindow(Rensen_ESP_RenderWindow, CS_Scr_Res.b, CS_Scr_Res.a, CS_Scr_Res.r, CS_Scr_Res.g, true);//修改 Pos & Size
		SetLayeredWindowAttributes(Rensen_ESP_RenderWindow, RGB(0, 0, 0), Variable::Animation<class CLASS_PlayerESP_Alpha_Animation_>(UI_Visual_ESP_DrawAlpha, 2), LWA_ALPHA);//窗口透明度设置
		Window::Set_LimitWindowShow(Rensen_ESP_RenderWindow, UI_Misc_ByPassOBS);//绕过OBS
		ESP_Paint.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//清除画板
		if (CS2_HWND && (Menu_Open || Global_IsShowWindow))//当CS窗口在最前端 && 菜单在最前端
		{
			Window::Set_Topmost_Status(Rensen_ESP_RenderWindow, Global_IsShowWindow);//修改窗口为最前端窗口 (覆盖一切的!!!)
			if (UI_Visual_ESP && (UI_Visual_ESP_Key == 0 || System::Get_Key(UI_Visual_ESP_Key)))//ESP 透视
			{
				auto Draw_Color = GUI_IO.GUIColor;
				if (UI_Visual_ESP_CustomColor)Draw_Color = UI_Visual_ESP_CustomColor_Color;//自定义透视ESP颜色
				const auto Local_Matrix = Base::ViewMatrix(); const auto Local_Angles = Base::ViewAngles(); const auto Local_Position = Global_LocalPlayer.Origin();
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					static uintptr_t C4_CachePlayerPawn = 0; if (PlayerPawn.ActiveWeaponName() == "C4")C4_CachePlayerPawn = PlayerPawn.Pawn();//更新C4缓存人物ID (可能会有刷新偏差Bug)
					if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
					const auto Top_Pos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(6) + Variable::Vector3{ 0, 0, 8 }, Local_Matrix);
					const auto Entity_Position = PlayerPawn.Origin();
					const auto Player_Distance = Variable::Coor_Dis_3D(Local_Position, Entity_Position);
					if (Player_Distance >= 10000)continue;//距离太远则不绘制ESP
					if (Top_Pos.x < -100 || Top_Pos.x > CS_Scr_Res.r + 100)//检测是否在屏幕内
					{
						if (UI_Visual_ESP_OutFOV && Global_LocalPlayer.Health())//方向指示器
						{
							auto Screen_Pos = Variable::Ang_Pos(CS_Scr_Res.g / ((120 - (float)UI_Visual_ESP_OutFOV_Radius) / 10), Local_Angles.y - 90 + atan2((Local_Position.x - Entity_Position.x), (Local_Position.y - Entity_Position.y)) * (180 / acos(-1)));
							Screen_Pos = { CS_Scr_Res.r / 2 - Screen_Pos[0] * ((float)CS_Scr_Res.r / (float)CS_Scr_Res.g),CS_Scr_Res.g / 2 + Screen_Pos[1] };
							ESP_Paint.RenderA_GradientCircle(Screen_Pos[0], Screen_Pos[1], UI_Visual_ESP_OutFOV_Size, { 0,0,0,100 }, { 0,0,0,0 });
							ESP_Paint.RenderA_GradientCircle(Screen_Pos[0], Screen_Pos[1], UI_Visual_ESP_OutFOV_Size, Draw_Color.D_Alpha(System::RainbowColor(3).r), { 0,0,0,0 });
							if (UI_Visual_ESP_ActiveWeapon)ESP_Paint.Render_String(Screen_Pos[0] - 8, Screen_Pos[1] - 4, PlayerPawn.ActiveWeaponName(), "Small Fonts", 9, { 100,100,100 });//绘制手持武器
						}
						continue;//不绘制ESP 重来
					}
					const auto Bottom_Pos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.Origin() - Variable::Vector3{ 0, 0, 6 }, Local_Matrix);
					const auto Hight = Bottom_Pos.y - Top_Pos.y;
					const auto Width = Hight * 0.25;
					const auto Left = Top_Pos.x - Width;
					const auto Right = Top_Pos.x + Width;
					if (Player_Distance <= 4000)//距离检测 降低CPU占用
					{
						if (UI_Visual_ESP_Line)ESP_Paint.RenderA_GradientLine(CS_Scr_Res.r / 2, CS_Scr_Res.g, Left + (Right - Left) / 2, Bottom_Pos.y, { 0,0,0,0 }, Draw_Color.D_Alpha(200));//射线
						if (UI_Visual_ESP_Skeleton)//骨骼
						{
							static const vector<short> Bone_Flags = { 6,5,4,13,14,15,14,13,4,8,9,10,9,8,4,3,2,1,25,26,27,26,25,1,22,23,24,24 };
							for (short i = 0; i <= Bone_Flags.size() - 2; ++i)
							{
								const auto Bone_ScreenPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(Bone_Flags[i]), Local_Matrix);
								const auto Bone_ScreenPos_ = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(Bone_Flags[i + 1]), Local_Matrix);
								ESP_Paint.Render_Line(Bone_ScreenPos.x, Bone_ScreenPos.y, Bone_ScreenPos_.x, Bone_ScreenPos_.y, Draw_Color / 2, UI_Visual_ESP_Skeleton_Thickness);
							}
							if (Debug_Control_Var::Checkbox_1 && Debug_Control_Var::Checkbox_2)
							{
								for (int i = 0; i <= 30; ++i)//显示所有骨骼ID
								{
									const auto Bone_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(i), Local_Matrix);
									ESP_Paint.RenderA_SmpStr(Bone_ScrPos.x, Bone_ScrPos.y, to_string(i), Draw_Color.D_Alpha(255));
								}
							}
						}
						if (UI_Visual_ESP_HeadDot)//头点
						{
							const auto Head_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, PlayerPawn.BonePos(6), Local_Matrix);
							ESP_Paint.RenderA_GradientCircle(Head_ScrPos.x, Head_ScrPos.y, 15, Draw_Color.D_Alpha(150), { 0,0,0,0 }, 0.2);
						}
					}
					if (UI_Visual_ESP_Box)//方框
					{
						ESP_Paint.RenderA_HollowRect(Left, Top_Pos.y, Right - Left, Bottom_Pos.y - Top_Pos.y, { 0,0,0,130 }, 3);
						ESP_Paint.RenderA_HollowRect(Left, Top_Pos.y, Right - Left, Bottom_Pos.y - Top_Pos.y, Draw_Color.D_Alpha(200));
					}
					if (UI_Visual_ESP_Health)//血条
					{
						const auto PlayerHealth = PlayerPawn.Health();//人物血量
						float Health_Ma = PlayerHealth * 0.01;
						if (PlayerHealth >= 100)Health_Ma = 1;
						else if (PlayerHealth <= 0)Health_Ma = 0;
						const auto PlayerArmor = PlayerPawn.Armor();//人物护甲
						float Armor_Ma = PlayerArmor * 0.01;
						if (PlayerArmor >= 100)Armor_Ma = 1;
						else if (PlayerArmor <= 0)Armor_Ma = 0;
						ESP_Paint.RenderA_SolidRect(Left - 6, Top_Pos.y - 1, 4, Bottom_Pos.y - Top_Pos.y + 3, { 0,0,0,130 });
						ESP_Paint.RenderA_SolidRect(Left - 5, Bottom_Pos.y - Hight * Armor_Ma, 2, Bottom_Pos.y - (Bottom_Pos.y - Hight * Armor_Ma) + 1, { 50,50,50,200 });//护甲条绘制
						if (UI_Visual_ESP_CustomColor)ESP_Paint.RenderA_GradientRect(Left - 5, Bottom_Pos.y - Hight * Health_Ma, 2, Bottom_Pos.y - (Bottom_Pos.y - Hight * Health_Ma) + 1, Draw_Color.D_Alpha(200), (Draw_Color / 5).D_Alpha(200), true);//血量条绘制
						else ESP_Paint.RenderA_GradientRect(Left - 5, Bottom_Pos.y - Hight * Health_Ma, 2, Bottom_Pos.y - (Bottom_Pos.y - Hight * Health_Ma) + 1, { (int)(1 - Health_Ma * 255),(int)(255 * Health_Ma),0,200 }, { 255,0,0,200 }, true);
						if (PlayerHealth < 100 && PlayerHealth > 0)ESP_Paint.Render_SmpStr(Left - 8, Bottom_Pos.y - Hight * Health_Ma - 6, to_string(PlayerHealth), { 150,150,150 }, { 0 }, false);//血量值绘制
					}
					if (UI_Visual_ESP_State)//人物状态
					{
						auto i = 0;//Line pos
						if (PlayerPawn.Armor()) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "HK", { 200,200,200 }, { 0 }, false); ++i; }
						if (C4_CachePlayerPawn == PlayerPawn.Pawn()) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "C4", { 255,0,0 }, { 0 }, false); ++i; }
						if (PlayerPawn.Scoped() && PlayerPawn.ActiveWeapon(true) == 3) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "ZOOM", { 0,120,255 }, { 0 }, false); ++i; }
						if (PlayerPawn.Spotted()) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "HIT", { 200,200,200 }, { 0 }, false); ++i; }
						if (PlayerPawn.ShotsFired() > 0) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "SHOT", { 200,200,200 }, { 0 }, false); ++i; }
						if (!(PlayerPawn.Flags() & (1 << 0))) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "AIR", { 200,200,200 }, { 0 }, false); ++i; }
						if (Global_LocalPlayer.IDEntIndex_Pawn().Pawn() == PlayerPawn.Pawn()) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "X", { 200,200,200 }, { 0 }, false); ++i; }
						if (Player_Distance >= 2500) { ESP_Paint.Render_SmpStr(Right + 2, Top_Pos.y - 2 + i * 8, "INV", { 100,0,255 }, { 0 }, false); ++i; }
					}
					if (UI_Visual_ESP_ActiveWeapon)ESP_Paint.Render_SmpStr(Left, Bottom_Pos.y, PlayerPawn.ActiveWeaponName(), { 200,200,200 }, { 0 }, false);//手持武器名称
					if (UI_Visual_ESP_Name)ESP_Paint.RenderA_String(Left - 2, Top_Pos.y - 15, Advanced::Player_Name(Global_ValidClassID[i]), "Segoe UI", 11, (Draw_Color * 3).Re_Col().D_Alpha(255));//人物名称
				}
			}
			if (Global_LocalPlayer.Health())//当本地人物活着时执行的功能
			{
				if (UI_Visual_HitMark)//命中标记
				{
					static short Mark_DMG = 0;//造成的伤害
					static Variable::Vector4 Mark_Color, EffectColor;//绘制颜色
					Mark_Color = Mark_Color - Variable::Vector4{ 10, 10, 10 }; Mark_Color = Mark_Color.Re_Col();//准星透明化动画
					EffectColor = EffectColor - Variable::Vector4{ 8, 8, 8 }; EffectColor = EffectColor.Re_Col();//特效透明化动画
					static auto OldDamage = 0; static auto OldKill = 0;
					const auto Damage = Advanced::Local_RoundDamage();//伤害
					const auto Kill = Advanced::Local_RoundDamage(true);//击杀
					const auto IDEnt_Pos = Global_LocalPlayer.IDEntIndex_Pawn().BonePos(5); static auto Target_Pos = IDEnt_Pos;//特效目标坐标
					if (Damage > OldDamage || Damage < OldDamage)//当伤害变化
					{
						if (Kill > OldKill && Global_LocalPlayer.ShotsFired()) { EffectColor = UI_Visual_HitMark_Color; }//Kill
						if (Damage > OldDamage) { Mark_Color = UI_Visual_HitMark_Color; Mark_DMG = Damage - OldDamage; }//Hit
						OldDamage = Damage; OldKill = Kill;//刷新
					}
					if (UI_Visual_HitMark_KillEffect)//闪电击杀效果
					{
						if (EffectColor.r != 0 || EffectColor.g != 0 || EffectColor.b != 0)//3D特效
						{
							const auto Range = UI_Visual_HitMark_KillEffect_Range;//爆炸半径 范围
							const auto Player_Matrix = Base::ViewMatrix();//本地人物视角矩阵
							for (short i = 0; i <= UI_Visual_HitMark_KillEffect_Quantity; ++i)//绘制粒子线条
							{
								srand(i * Kill);//随机种子
								const auto Effect_Pos = Variable::WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Target_Pos, Player_Matrix);//起点坐标
								const auto Effect_Pos_To = Variable::WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Target_Pos.x + rand() % Range - Range / 2,Target_Pos.y + rand() % Range - Range / 2,Target_Pos.z + rand() % Range - Range / 2 }, Player_Matrix);
								ESP_Paint.Render_Line(Effect_Pos.x, Effect_Pos.y, Effect_Pos_To.x, Effect_Pos_To.y, EffectColor);
							}
						}
						else if (IDEnt_Pos.x != 0)Target_Pos = IDEnt_Pos;
					}
					if (Mark_Color.r != 0 || Mark_Color.g != 0 || Mark_Color.b != 0)//2D准星
					{
						const short Range = UI_Visual_HitMark_Range, Length = UI_Visual_HitMark_Length, Width = UI_Visual_HitMark_Thickness;//绘制设置(距离,长度,粗细)
						ESP_Paint.Render_Line(CS_Scr_Res.r / 2 - Range, CS_Scr_Res.g / 2 - Range, CS_Scr_Res.r / 2 - Range - Length, CS_Scr_Res.g / 2 - Range - Length, Mark_Color, Width);
						ESP_Paint.Render_Line(CS_Scr_Res.r / 2 + Range, CS_Scr_Res.g / 2 + Range, CS_Scr_Res.r / 2 + Range + Length, CS_Scr_Res.g / 2 + Range + Length, Mark_Color, Width);
						ESP_Paint.Render_Line(CS_Scr_Res.r / 2 + Range, CS_Scr_Res.g / 2 - Range, CS_Scr_Res.r / 2 + Range + Length, CS_Scr_Res.g / 2 - Range - Length, Mark_Color, Width);
						ESP_Paint.Render_Line(CS_Scr_Res.r / 2 - Range, CS_Scr_Res.g / 2 + Range, CS_Scr_Res.r / 2 - Range - Length, CS_Scr_Res.g / 2 + Range + Length, Mark_Color, Width);
						if (UI_Visual_HitMark_Damage)ESP_Paint.Render_String(CS_Scr_Res.r / 2 - 5, CS_Scr_Res.g / 2 + Range + 10, to_string(Mark_DMG), "Small Fonts", 11, Mark_Color, false);
					}
				}
				if (UI_Misc_AutoPeek)//AutoPeek
				{
					auto Range = 30;//范围变量
					const auto LocalPlayer_Pos = Global_LocalPlayer.Origin(); static BOOL IS_SAVED_POS = false; static auto Peek_Pos = LocalPlayer_Pos;//缓存要移动的坐标
					static BOOL DO_MOVE = false;//判断是否要移动到目标坐标
					if (System::Get_Key(UI_Misc_AutoPeek_Key))
					{
						if (!IS_SAVED_POS) { Peek_Pos = LocalPlayer_Pos; IS_SAVED_POS = true; }//刷新缓存坐标
						if (Variable::Coor_Dis_3D(LocalPlayer_Pos, Peek_Pos) >= 250)Peek_Pos = LocalPlayer_Pos;//如果距离太远那么再次刷新
						if (Global_LocalPlayer.ShotsFired() != 0)DO_MOVE = true;//开枪后移动
						if (DO_MOVE && Advanced::Move_to_Pos(Peek_Pos, Range))DO_MOVE = false;//判断结束移动
						const auto Player_Matrix = Base::ViewMatrix();//本地人物视角矩阵
						const auto Target_Origin = Peek_Pos;//目标绘制点3D世界坐标
						const auto Draw_SCR_Pos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Target_Origin, Player_Matrix);//中心点屏幕坐标
						if (Draw_SCR_Pos.x > 0 && Draw_SCR_Pos.x < CS_Scr_Res.r && Draw_SCR_Pos.y > 0 && Draw_SCR_Pos.y < CS_Scr_Res.g)
						{
							const auto Origin_Offset = Variable::Pos_Angle(LocalPlayer_Pos, Target_Origin);//双点坐标连接偏差角度
							const auto Size_X = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Variable::Ang_Pos_Vec(Target_Origin, Range, Origin_Offset * -1), Player_Matrix);
							const auto Size_Y = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Variable::Ang_Pos_Vec(Target_Origin, Range, Origin_Offset * -1 + 90), Player_Matrix);
							if (Draw_SCR_Pos.x != 9999 && Size_X.x != 9999 && Size_Y.x != 9999 && Variable::Coor_Dis_2D(Size_X, Draw_SCR_Pos) <= 500)ESP_Paint.RenderA_GradientEllipse(Draw_SCR_Pos.x, Draw_SCR_Pos.y, Variable::Coor_Dis_2D(Size_X, Draw_SCR_Pos) * 2, Variable::Coor_Dis_2D(Size_Y, Draw_SCR_Pos) * 2, GUI_IO.GUIColor.D_Alpha(255), { 0,0,0,0 }, 0);
						}
						Range += 5;//范围修正
						for (short i = 0; i <= 10; ++i)//绘制Peek圆圈
						{
							srand(i + System::Tick());//随机种子
							const auto Effect_Pos = Variable::WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Peek_Pos, Player_Matrix);//起点坐标 (屏幕2D坐标)
							const auto Effect_Pos_To = Variable::WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Peek_Pos.x + rand() % Range - Range / 2,Peek_Pos.y + rand() % Range - Range / 2,Peek_Pos.z }, Player_Matrix);
							if (DO_MOVE)ESP_Paint.Render_Line(Effect_Pos.x, Effect_Pos.y, Effect_Pos_To.x, Effect_Pos_To.y, GUI_IO.GUIColor, 2);
							else ESP_Paint.Render_Line(Effect_Pos.x, Effect_Pos.y, Effect_Pos_To.x, Effect_Pos_To.y, GUI_IO.GUIColor / 2);
						}
					}
					else {
						IS_SAVED_POS = false;
						if (DO_MOVE)//防止串按键
						{
							ExecuteCommand("-forward");
							ExecuteCommand("-right");
							ExecuteCommand("-back");
							ExecuteCommand("-left");//释放所有按键
							DO_MOVE = false;
						}
					}
				}
				if (UI_Legit_Aimbot && UI_Legit_Armory_ShowAimbotRange)//Aimbot Range 自瞄范围绘制
				{
					auto Circle_Range = 0;
					const auto Local_ActiveWeaponType = Global_LocalPlayer.ActiveWeapon(true);//本地人物手持武器类型
					if (Local_ActiveWeaponType == 1)Circle_Range = UI_Legit_Armory_Range_PISTOL * 5;
					else if (Local_ActiveWeaponType == 2)Circle_Range = UI_Legit_Armory_Range_RIFLE * 5;
					else if (Local_ActiveWeaponType == 3) { if (Global_LocalPlayer.Scoped())Circle_Range = UI_Legit_Armory_Range_SNIPER * 14; else Circle_Range = UI_Legit_Armory_Range_SNIPER * 5; }
					else if (Local_ActiveWeaponType == 4)Circle_Range = UI_Legit_Armory_Range_SHOTGUN * 5;
					Circle_Range += abs(Global_LocalPlayer.AimPunchAngle().x * 25);//后坐力反馈
					if (Circle_Range > 300)ESP_Paint.Render_HollowCircle(CS_Scr_Res.r / 2, CS_Scr_Res.g / 2, Variable::Animation<class Render_Aimbot_Range_Animation>(Circle_Range, 1.5), GUI_IO.GUIColor / 3);
					else ESP_Paint.RenderA_GradientCircle(CS_Scr_Res.r / 2, CS_Scr_Res.g / 2, Variable::Animation<class Render_Aimbot_Range_Animation>(Circle_Range, 1.5), { 0,0,0,0 }, GUI_IO.GUIColor.D_Alpha(80), 0.95);
				}
				if (UI_Misc_SniperCrosshair && Global_LocalPlayer.ActiveWeapon(true) == 3 && !Global_LocalPlayer.Scoped())ESP_Paint.RenderA_GradientCircle(CS_Scr_Res.r / 2, CS_Scr_Res.g / 2, UI_Misc_SniperCrosshair_Size, GUI_IO.GUIColor.D_Alpha(150), { 0,0,0,0 }, 0.3);//狙击枪准星
			}
		}
		else Sleep(20);
		ESP_Paint.DrawPaint();//最终绘制画板
		if (CS2_HWND && Menu_Open)Sleep(20);//菜单打开时降低绘制速度以降低CPU使用率
	}
}
void Thread_Funtion_EntityESP() noexcept//功能线程: 实体透视
{
	System::Log("Load Thread: Thread_Funtion_EntityESP()");
	Window::Windows RenderWindow; Window::Render WEP_Render;
	const auto Render_Window_HWND = RenderWindow.Create_RenderBlock(Window::Get_Resolution().x, Window::Get_Resolution().y, "Rensen - EntityESP");
	RenderWindow.Set_WindowAttributes({ 0,0,0 }, 180);//窗口过滤颜色和透明度
	WEP_Render.CreatePaint(Render_Window_HWND, 0, 0, Window::Get_Resolution().x, Window::Get_Resolution().y);
	while (true)
	{
		Sleep(UI_Visual_ESP_DrawDelay);//降低CPU占用
		RenderWindow.Set_WindowTitle(System::Rand_String(10));//随机实体透视窗口标题
		const auto CS_Scr_Res = Window::Get_WindowResolution(CS2_HWND);
		WEP_Render.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//刷新绘制画板
		if (CS2_HWND && UI_Visual_ESP && (UI_Visual_ESP_Key == 0 || System::Get_Key(UI_Visual_ESP_Key)) && UI_Visual_ESP_Drops && (Menu_Open || Global_IsShowWindow))//当CS窗口在最前端 && 本地人物活着
		{
			if (Menu_Open)Sleep(50);//节省CPU性能 (可有可无)
			auto Draw_Color = GUI_IO.GUIColor; if (UI_Visual_ESP_CustomColor)Draw_Color = UI_Visual_ESP_CustomColor_Color;
			MoveWindow(Render_Window_HWND, CS_Scr_Res.b, CS_Scr_Res.a, CS_Scr_Res.r, CS_Scr_Res.g, true);//Pos & Size
			RenderWindow.Set_WindowAttributes({ 0,0,0 }, Variable::Animation<class CLASS_EntityESP_Alpha_Animation_>(UI_Visual_ESP_DrawAlpha, 2));//窗口透明度设置
			Window::Set_LimitWindowShow(RenderWindow.Get_HWND(), UI_Misc_ByPassOBS);//绕过OBS
			const auto Entitylist = Base::EntityList(); const auto Local_Origin = Global_LocalPlayer.Origin(); const auto Local_ViewMatrix = Base::ViewMatrix();
			static vector<short> Class_ID = {};//有效实体ID
			if (System::Sleep_Tick<class CLASS_Drops_ESP_Reload_ClassID_>(600))//特殊算法为了提高绘制效率
			{
				short Show_Quantity = 0;//计算绘制的实体数量
				Class_ID = {};//刷新有效实体ID
				for (short i = 65; i <= 2048; ++i)//class id 65-2048
				{
					if (Show_Quantity > 40)continue;//限制数量
					const Base::PlayerPawn Entity = Base::Convert(Entitylist, i);
					if (!Entity.Pawn())continue;
					const auto Entity_Pos = Entity.Origin();
					if (Entity_Pos.x == 0 || Entity_Pos.y == 0 || Variable::Coor_Dis_3D(Local_Origin, Entity_Pos) >= 2500)continue;//实体之间距离检测
					const auto Entity_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Entity.Origin(), Local_ViewMatrix);
					if (Entity_ScrPos.x < -800 || Entity_ScrPos.x > CS_Scr_Res.r + 800)continue;//检测实体是否在屏幕内
					if (Entity.ActiveWeaponName(true, Entity.Pawn()) == "NONE" && !Variable::String_Find(Entity.EntityName(), "_projectile"))continue;//检测实体名称是否有效
					if (Entity.EntityName() == "hegrenade_projectile" && !System::Get_ValueChangeState<float, class CLASS_Drops_ESP_Delete_StopedEntity_>(Entity_Pos.x))continue;//排除手雷缓存 (受累爆炸后不在移动时就是留下的缓存)
					Class_ID.push_back(i); ++Show_Quantity;//计算有效实体数量
					System::Sleep_ns(10);//降低CPU占用
				}
			}
			if (Class_ID.size() > 0)
			{
				for (short i = 0; i < Class_ID.size(); ++i)//只遍历有效实体
				{
					const Base::PlayerPawn Entity = Base::Convert(Entitylist, Class_ID[i]);
					const auto Entity_Pos = Entity.Origin();
					if (Entity_Pos.x == 0 || Entity_Pos.y == 0)continue;//过滤掉无效坐标
					auto Entity_ScrPos = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, Entity_Pos, Local_ViewMatrix);
					auto Entity_Name = Entity.EntityName();
					if (Variable::String_Find(Entity_Name, "_projectile"))//飞行的道具绘制
					{
						Entity_Name.erase(Entity_Name.length() - 11, 11);//删除_projectile
						Entity_Name = Variable::String_Upper(Entity_Name);//转换大写
						if (Entity_Name == "SMOKEGRENADE")//烟雾弹范围绘制
						{
							const float SmokeRange = 200;//烟雾弹绘制范围 (坐标范围)
							const auto Pos_1 = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Entity_Pos.x - (float)floor(sin(System::Tick() / 1000.f) * SmokeRange),Entity_Pos.y - (float)floor(cos(System::Tick() / 1000.f) * SmokeRange), Entity_Pos.z }, Local_ViewMatrix);
							const auto Pos_2 = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Entity_Pos.x + (float)floor(sin(System::Tick() / 1000.f) * SmokeRange),Entity_Pos.y + (float)floor(cos(System::Tick() / 1000.f) * SmokeRange), Entity_Pos.z }, Local_ViewMatrix);
							const auto Pos_3 = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Entity_Pos.x + (float)floor(cos(System::Tick() / 1000.f) * SmokeRange),Entity_Pos.y - (float)floor(sin(System::Tick() / 1000.f) * SmokeRange), Entity_Pos.z }, Local_ViewMatrix);
							const auto Pos_4 = WorldToScreen(CS_Scr_Res.r, CS_Scr_Res.g, { Entity_Pos.x - (float)floor(cos(System::Tick() / 1000.f) * SmokeRange),Entity_Pos.y + (float)floor(sin(System::Tick() / 1000.f) * SmokeRange), Entity_Pos.z }, Local_ViewMatrix);
							WEP_Render.Render_Line(Pos_1.x, Pos_1.y, Pos_2.x, Pos_2.y, Draw_Color);
							WEP_Render.Render_Line(Pos_3.x, Pos_3.y, Pos_4.x, Pos_4.y, Draw_Color);
							Entity_Name = "SMOKE";
						}
						else if (Entity_Name == "FLASHBANG")Entity_Name = "FLASH";
						else if (Entity_Name == "HEGRENADE")Entity_Name = "GRENADE";
						if (Entity_ScrPos.x <= 100)Entity_ScrPos.x = 100;
						else if (Entity_ScrPos.x >= CS_Scr_Res.r - 100)Entity_ScrPos.x = CS_Scr_Res.r - 100;
						if (Entity_ScrPos.y <= 100)Entity_ScrPos.y = 100;
						else if (Entity_ScrPos.y >= CS_Scr_Res.g - 100)Entity_ScrPos.y = CS_Scr_Res.g - 100;//防止移除屏幕边缘
						WEP_Render.RenderA_GradientCircle(Entity_ScrPos.x, Entity_ScrPos.y, 20, { 1,1,1 }, Draw_Color.D_Alpha(255), floor(sin((float)System::Tick() / 150) * 40 + 40) / 100 - 0.2);
						WEP_Render.Render_SmpStr(Entity_ScrPos.x - 13, Entity_ScrPos.y, Entity_Name, { 200,200,200 }, { 1,1,1 });
					}
					else WEP_Render.Render_SmpStr(Entity_ScrPos.x - 15, Entity_ScrPos.y, Entity.ActiveWeaponName(true, Entity.Pawn()), { 200,200,200 }, { 1,1,1 });//武器绘制
				}
			}
			else Sleep(100);
		}
		else { MoveWindow(Render_Window_HWND, 0, 0, 0, 0, true); Sleep(20); }
		WEP_Render.DrawPaint(true);
	}
}
void Thread_Funtion_Radar() noexcept//功能线程: 雷达
{
	System::Log("Load Thread: Thread_Funtion_Radar()");
	Sleep(500);//相比菜单后一步创建窗口
	Window::Windows Radar_Window; const auto RadarRenderWindow = Radar_Window.Create_Window(UI_Visual_Radar_Size, UI_Visual_Radar_Size + 15, "Rensen - Radar", true);//创建雷达绘制窗口
	Window::Render Radar_Paint; Radar_Paint.CreatePaint(RadarRenderWindow, 0, 0, 500, 500 + 15);//创建绘制画板
	Radar_Window.Set_WindowPos(UI_Visual_Radar_Pos.x, UI_Visual_Radar_Pos.y);//套用参数的雷达位置
	while (true)
	{
		Sleep(5);//降低CPU占用
		Radar_Window.Set_WindowTitle(System::Rand_String(10));//随机雷达窗口标题
		Window::Set_LimitWindowShow(Radar_Window.Get_HWND(), UI_Misc_ByPassOBS);//绕过OBS
		static short Radar_Size_; const short RadarSizeAnimation = Variable::Animation<class Class_Radar_Window_Size>(Radar_Size_, 2);
		if (CS2_HWND && (Global_IsShowWindow || Menu_Open || Window::Get_WindowEnable(Radar_Window.Get_HWND())) && UI_Visual_Radar)//当CS窗口在最前端
		{
			Radar_Size_ = UI_Visual_Radar_Size; UI_Visual_Radar_Pos = Radar_Window.Get_WindowPos();
			if (!Radar_Window.Window_Move(15))//移动雷达窗口
			{
				const float RadarRangeAnimation = Variable::Animation<class Class_Radar_Window_Range>(UI_Visual_Radar_Range, 2);//窗口动画
				const auto LocalPlayerPos = Global_LocalPlayer.Origin(); const auto ViewAngle = Base::ViewAngles();
				Radar_Paint.Render_SolidRect(0, 0, 9999, 9999, { 0,0,0 });//背景
				if (UI_Visual_Radar_Alpha)//透明状态不绘制人物视角朝向
				{
					if (UI_Visual_Radar_FollowAngle)Radar_Paint.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 135, 0)[1] ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, 225, 0)[1] }, GUI_IO.GUIColor / 4, { 0,0,0 }, { 0,0,0 });
					else Radar_Paint.Render_GradientTriangle({ RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15 ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 45)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 45)[1] ,(int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 135)[0], (int)Variable::Ang_Pos_(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 2, ViewAngle.y, 135)[1] }, GUI_IO.GUIColor / 4, { 0,0,0 }, { 0,0,0 });//本地人物视野
				}
				Radar_Paint.Render_HollowCircle(RadarSizeAnimation / 2, RadarSizeAnimation / 2 + 15, RadarSizeAnimation / 100 * 3.5, { 255,255,255 }, 2);//自身圆圈
				for (short i = 0; i < Global_ValidClassID.size(); ++i)
				{
					const auto PlayerPawn = Advanced::Traverse_Player(Global_ValidClassID[i]);
					if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
					const auto EntityPos = PlayerPawn.Origin(); static vector<float> EnemyScreenPos;
					if (UI_Visual_Radar_FollowAngle)EnemyScreenPos = { RadarSizeAnimation / 2 - Variable::Ang_Pos(Variable::Coor_Dis_2D(LocalPlayerPos, EntityPos), ViewAngle.y - 90 + atan2((LocalPlayerPos.x - EntityPos.x), (LocalPlayerPos.y - EntityPos.y)) * (180 / acos(-1)))[0] / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + Variable::Ang_Pos(Variable::Coor_Dis_2D(LocalPlayerPos, EntityPos), ViewAngle.y - 90 + atan2((LocalPlayerPos.x - EntityPos.x), (LocalPlayerPos.y - EntityPos.y)) * (180 / acos(-1)))[1] / RadarRangeAnimation };
					else EnemyScreenPos = { RadarSizeAnimation / 2 - (LocalPlayerPos.x - EntityPos.x) / RadarRangeAnimation,RadarSizeAnimation / 2 + 15 + (LocalPlayerPos.y - EntityPos.y) / RadarRangeAnimation };
					if (EnemyScreenPos[0] > RadarSizeAnimation)EnemyScreenPos[0] = RadarSizeAnimation;//边缘限制 (无法离开绘制区域)
					else if (EnemyScreenPos[0] < 0) EnemyScreenPos[0] = 0;
					if (EnemyScreenPos[1] > RadarSizeAnimation + 15)EnemyScreenPos[1] = RadarSizeAnimation + 15;
					else if (EnemyScreenPos[1] < 15)EnemyScreenPos[1] = 15;
					if (PlayerPawn.Spotted())Radar_Paint.Render_SolidCircle(EnemyScreenPos[0], EnemyScreenPos[1], RadarSizeAnimation / 100 * 3.5, GUI_IO.GUIColor, GUI_IO.GUIColor);//敌人圆圈
					else Radar_Paint.Render_HollowCircle(EnemyScreenPos[0], EnemyScreenPos[1], RadarSizeAnimation / 100 * 3.5, GUI_IO.GUIColor);
				}
				Radar_Paint.Render_GradientRect(0, 0, Radar_Window.Get_WindowSize().x, 14, GUI_IO.GUIColor / 2, GUI_IO.GUIColor / 4, false);
				Radar_Paint.Render_GradientRect(0, 14, Radar_Window.Get_WindowSize().x, 1, GUI_IO.GUIColor / 4, GUI_IO.GUIColor / 2, false);//标题背景
				Radar_Paint.Render_String(3 + 1, 1 + 1, "Rensen - Radar", "Small Fonts", 12, { 0,0,1 }, false);//标题阴影
				Radar_Paint.Render_String(3, 1, "Rensen - Radar", "Small Fonts", 12, GUI_IO.GUIColor, false);//标题
				Radar_Paint.DrawPaint();//最终绘制雷达画板
			}
		}
		else Radar_Size_ = 0;
		if (UI_Visual_Radar_Show)//修复窗口不显示BUG
		{
			Radar_Window.Show_Window();
			Window::Set_Topmost_Status(Radar_Window.Get_HWND(), true);
		}
		Radar_Window.Set_WindowSize(RadarSizeAnimation, RadarSizeAnimation + 15);//雷达大小
		if (!UI_Visual_Radar_Alpha)Radar_Window.Set_WindowAttributes({ 0,0,0 }, 0, LWA_COLORKEY);//将黑色像素改为全透明
		else Radar_Window.Set_WindowAlpha(Variable::Animation<class Class_Radar_Window_Alpha>(UI_Visual_Radar_Alpha, 2));//雷达透明度
		Radar_Window.Fix_inWhile();//窗口消息循环
	}
}
void Thread_Funtion_Sonar() noexcept//功能线程: 声呐(距离检测)
{
	System::Log("Load Thread: Thread_Funtion_Sonar()");
	while (true)
	{
		Sleep(5);
		if (CS2_HWND && Global_IsShowWindow && UI_Misc_Sonar && (UI_Misc_Sonar_Key == 0 || System::Get_Key(UI_Misc_Sonar_Key)) && Global_LocalPlayer.Health())//当CS窗口在最前端 && 本地人物活着
		{
			const auto Local_Pos = Global_LocalPlayer.Origin();//本地人物坐标
			for (short i = 0; i <= 64; ++i)
			{
				System::Sleep_ns(150);
				if (UI_Misc_Sonar_Key != 0 && !System::Get_Key(UI_Misc_Sonar_Key))continue;//提高效率
				const auto PlayerPawn = Advanced::Traverse_Player(i);
				if (!Advanced::Check_Enemy(PlayerPawn))continue;//多点检测
				const auto Pos_Dis = Variable::Coor_Dis_2D(Local_Pos, PlayerPawn.Origin());//敌人坐标距离
				if (Pos_Dis <= UI_Misc_Sonar_Range_Near)Beep(300, 20);//Near range 近距离
				else if (Pos_Dis <= UI_Misc_Sonar_Range_Far)Beep(150, 20);//Far range 远距离
				if (Pos_Dis <= UI_Misc_Sonar_Range_Far)Sleep(20);//断开间隔
			}
		}
		else Sleep(20);
	}
}
int main() noexcept//主线程 (加载多线程, 一些杂项功能)
{
	System::Anti_Debugger("Debugging is disabled after compilation is completed.");//防止逆向破解
	//----------------------------------------------------------------------------------------------------------------------------------
	System::URL_READ UserID_READ = { "Cache_UserID" }; BOOL Attest = false;//认证变量
	if (UserID_READ.StoreMem("https://github.com/Coslly/Rensen/blob/main/Cloud%20Files/UserID.uid?raw=true"))//Github读取有效用户ID
	{
		if (!Attest)for (short i = 0; i <= 10000; i++) { if (System::Get_UserName() == UserID_READ.Read(i) || Variable::String_Upper(UserID_READ.Read(i)) == "BYPASS") { Attest = true; break; } }//遍历检测并修改认证
		UserID_READ.Release();//释放缓存
	}
	if (!Attest) { Window::Message_Box("Rensen Attest - " + System::Get_UserName(), "Your identity cannot be passed.\n\nUnable to access from Chinese IP.\n\nAuthor: https://github.com/Coslly\n", MB_ICONSTOP); exit(0); }//未被认证则直接退出
	//----------------------------------------------------------------------------------------------------------------------------------
	System::URL_READ AutoUpdate = { "Cache_Update" };//自动更新系统
	if (AutoUpdate.StoreMem("https://github.com/Coslly/Rensen/blob/main/Rensen/Rensen/Main.cpp?raw=true"))//版本号更新检查
	{
		auto Version = AutoUpdate.Read(3); if (Version != "") { Version.erase(0, 29); Version.erase(Version.size() - 15, 100); }//擦除无用字符只获取版本号
		AutoUpdate.Release();//释放缓存
		if (Variable::string_float_(Version) > Rensen_Version && Window::Message_Box("Rensen Update", "A new version has been released.\nDo you want to update now?\nIt may take tens of seconds.\n\nYou will be updated to Ver[" + Version + "]", MB_YESNO | MB_ICONASTERISK) == 6)
		{
			System::Open_Website("https://github.com/Coslly/Rensen/releases/download/Release/Rensen.exe"); exit(0);//打开下载链接并且关闭程序
		}
	}
	//----------------------------------------------------------------------------------------------------------------------------------
	System::Anti_click();//控制台不被暂停
	Window::Hide_ConsoleWindow();//隐藏控制台
	Window::Initialization_ConsoleWindow();//初始化控制台窗口 (初始化窗口大小, 清除字符)
	printf("Welcome to Rensen for Counter-Strike 2 cheat.\nThe Rensen project is a version converted from FreeCS.\nNo team author By: https://github.com/Coslly\nThe following information returned is debugging information.\n");//作者留言
	System::Log("Load Thread: main()");
	Sleep(100);//修复重启进程冲突
	if (!System::Judge_File(UI_LocalConfigPath)) { System::Create_File(UI_LocalConfigPath, UI_DefaultConfig); System::Self_Restart(); }//创建默认参数文件 (当未找到参数文件时, 第一次启动时)
	thread Thread_Menu_ = thread(Thread_Menu);
	thread Thread_Misc_ = thread(Thread_Misc);
	Sleep(50);//防止重启卡线程 (以下为功能函数线程)
	thread Thread_Funtion_BunnyHop_ = thread(Thread_Funtion_BunnyHop);
	thread Thread_Funtion_Aimbot_ = thread(Thread_Funtion_Aimbot);
	thread Thread_Funtion_AdaptiveAimbot_ = thread(Thread_Funtion_AdaptiveAimbot);
	thread Thread_Funtion_Triggerbot_ = thread(Thread_Funtion_Triggerbot);
	thread Thread_Funtion_AssisteAim_ = thread(Thread_Funtion_AssisteAim);
	thread Thread_Funtion_RemoveRecoil_ = thread(Thread_Funtion_RemoveRecoil);
	thread Thread_Funtion_PlayerESP_ = thread(Thread_Funtion_PlayerESP);
	thread Thread_Funtion_EntityESP_ = thread(Thread_Funtion_EntityESP);
	thread Thread_Funtion_Radar_ = thread(Thread_Funtion_Radar);
	thread Thread_Funtion_Sonar_ = thread(Thread_Funtion_Sonar);
	while (true)//菜单动画和关闭快捷键
	{
		if (!Attest) { exit(0); return 0; }//过滤未认证用户 (防止被HOOK初始化函数)
		if (System::Get_Key(VK_INSERT) && System::Get_Key(VK_DELETE)) { Beep(50, 50); Window::NVIDIA_Overlay(); exit(0); }//快速关闭键 (防止卡线程)
		static short MenuWindowAlpha = 0;
		if (Menu_Open)MenuWindowAlpha = MenuWindowAlpha + UI_Setting_MainColor.a / UI_Setting_MenuAnimation / 2.5;//窗体透明度动画
		else MenuWindowAlpha = MenuWindowAlpha - UI_Setting_MainColor.a / UI_Setting_MenuAnimation / 1.25;
		if (MenuWindowAlpha >= UI_Setting_MainColor.a)MenuWindowAlpha = UI_Setting_MainColor.a;
		else if (MenuWindowAlpha <= 0)MenuWindowAlpha = 0;
		GUI_VAR.Window_SetAlpha(MenuWindowAlpha);//修改菜单透明度
		if (!System::Key_Toggle<class CLASS_Main_Rensen_MenuKey>(UI_Setting_MenuKey)) { GUI_VAR.Window_Show(); Menu_Open = true; }//保证菜单窗口在最前端
		else { if (MenuWindowAlpha == 0)GUI_VAR.Window_Hide(); Menu_Open = false; }
		GUI_IO = GUI_VAR.Get_IO();//刷新GUI状态数据
		if (!UI_Setting_CustomColor)GUI_IO.GUIColor = { GUI_IO.GUIColor_Rainbow[3],GUI_IO.GUIColor_Rainbow[4],GUI_IO.GUIColor_Rainbow[5] };//GUI主题颜色到功能函数
		if (UI_Setting_MenuFont == "")GUI_VAR.Global_Set_EasyGUI_Font("Verdana");//自定义GUI字体
		else GUI_VAR.Global_Set_EasyGUI_Font(UI_Setting_MenuFont);
		GUI_VAR.Global_Set_EasyGUI_FontSize(UI_Setting_MenuFontSize);//自定义GUI字体大小
		Sleep(1);
	}
}
