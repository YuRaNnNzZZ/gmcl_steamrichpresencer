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

GMOD_MODULE_OPEN()
{
	LUA->PushSpecial(GarrysMod::Lua::SPECIAL_GLOB);
		LUA->GetField(-1, "steamworks");
		LUA->PushCFunction(SetRichPresence);
		LUA->SetField(-2, "SetRichPresence");
	LUA->Pop(2);

	return 0;
}

GMOD_MODULE_CLOSE()
{
	return 0;
}