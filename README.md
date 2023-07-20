# Steam Rich Presencer
A simple Garry's Mod module that adds ability to change your Rich Presence from Lua.

It wraps [this function](https://partner.steamgames.com/doc/api/ISteamFriends#SetRichPresence) as `steamworks.SetRichPresence(String presenceKey, String presenceValue)`

## Installation
- Switch Garry's Mod to `x86-64` branch
- Download the build for your OS from releases
- Unpack the dll file to `steamapps/common/GarrysMod/garrysmod/lua/bin`

## Example Usage
```Lua
if not util.IsBinaryModuleInstalled("steamrichpresencer") then return end -- check if module is correctly installed

require("steamrichpresencer") -- module adds steamworks.SetRichPresence function on load

steamworks.SetRichPresence("generic", "Destiny 2") -- GMod only makes use of "generic" presence key
```
### Your status would like like this:
![](https://i.imgur.com/2ZTXZck.png)
