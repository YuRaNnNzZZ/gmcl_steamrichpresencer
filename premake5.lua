PROJECT_GENERATOR_VERSION = 3

newoption({
	trigger = "gmcommon",
	description = "Sets the path to the garrysmod_common (https://github.com/danielga/garrysmod_common) directory",
	value = "../garrysmod_common"
})

local gmcommon = assert(_OPTIONS.gmcommon or os.getenv("GARRYSMOD_COMMON"),
	"you didn't provide a path to your garrysmod_common (https://github.com/danielga/garrysmod_common) directory")
include(gmcommon)

CreateWorkspace({name = "steamrichpresencer", abi_compatible = false, path = "projects/" .. os.target() .. "/" .. _ACTION})
	CreateProject({serverside = false, source_path = "source", manual_files = true})
		IncludeLuaShared()
		-- IncludeHelpersExtended()
		-- IncludeScanning()
		-- IncludeDetouring()
		IncludeSDKCommon()
		IncludeSDKTier0()
		IncludeSDKTier1()
		IncludeSteamAPI()

	files({"source/*.cpp", "source/*.hpp"})