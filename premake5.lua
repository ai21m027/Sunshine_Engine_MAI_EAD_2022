
workspace "Sunshine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Sunshine/vendor/GLFW/include"
IncludeDir["Glad"] = "Sunshine/vendor/Glad/include"
IncludeDir["ImGui"] = "Sunshine/vendor/imgui"

include "Sunshine/vendor/GLFW"
include "Sunshine/vendor/Glad"
include "Sunshine/vendor/imgui"

project "Sunshine"
	location "Sunshine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	--Pre compiled header configurations, pchsource needed for VS2019
	pchheader "supch.h"
	pchsource "Sunshine/src/supch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		--"%{IncludeDir.ImGui}/imgui_tables.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines{
			"SU_PLATFORM_WINDOWS",
			"SU_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			" IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "SU_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	filter "configurations:Release"
		defines "SU_RELEASE"
		buildoptions "/MD"
		optimize "On"
	filter "configurations:Dist"
		defines "SU_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	
	includedirs
	{
		"Sunshine/vendor/spdlog/include",
		"Sunshine/src"
	}
	
	links
	{
		"Sunshine"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines{
			"SU_PLATFORM_WINDOWS"
		}
		
	
	filter "configurations:Debug"
		defines "SU_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	filter "configurations:Release"
		defines "SU_RELEASE"
		buildoptions "/MD"
		optimize "On"
	filter "configurations:Dist"
		defines "SU_DIST"
		buildoptions "/MD"
		optimize "On"




