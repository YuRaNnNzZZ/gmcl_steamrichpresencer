#include "GarrysMod/Lua/Interface.h"
#include <steam_api.h>

using namespace GarrysMod::Lua;

LUA_FUNCTION(SetRichPresence)
{
	const char *pchKey = LUA->CheckString(1);
	const char *pchValue = LUA->CheckString(2);

	bool success = SteamFriends()->SetRichPresence(pchKey, pchValue);

	LUA->PushBool(success);
	return 1;
}

LUA_FUNCTION(SetRichPresenceGameMode)
{
	const char *gamemode = LUA->CheckString(1);
	bool success = SteamFriends()->SetRichPresence("gamemode", gamemode);

	LUA->PushBool(success);
	return 1;
}

LUA_FUNCTION(SetRichPresenceMap)
{
	const char *map = LUA->CheckString(1);
	bool success = SteamFriends()->SetRichPresence("map", map);

	LUA->PushBool(success);
	return 1;
}

LUA_FUNCTION(SetRichPresenceStatus)
{
	const char* status = LUA->CheckString(1);
	bool success1 = SteamFriends()->SetRichPresence("generic", status);
	bool success2 = SteamFriends()->SetRichPresence("steam_display", "#status_generic");

	LUA->PushBool(success1);
	LUA->PushBool(success2);
	return 2;
}

void PushLuaFunction(GarrysMod::Lua::ILuaBase* LUA, const char* funcName, GarrysMod::Lua::CFunc func)
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
	LUA->PushString(funcName);
	LUA->PushCFunction(func);
	LUA->SetTable(-3);
}

GMOD_MODULE_OPEN()
{
	PushLuaFunction(LUA, "SetRichPresence", SetRichPresence);
	PushLuaFunction(LUA, "SetRichPresenceGameMode", SetRichPresenceGameMode);
	PushLuaFunction(LUA, "SetRichPresenceMap", SetRichPresenceMap);
	PushLuaFunction(LUA, "SetRichPresenceStatus", SetRichPresenceStatus);

	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}