workspace "Sunshine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sunshine"
	location "Sunshine"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines{
			"SU_PLATFORM_WINDOWS",
			"SU_BUILD_DLL",
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "SU_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "SU_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "SU_DIST"
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
		symbols "On"
	filter "configurations:Release"
		defines "SU_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "SU_DIST"
		optimize "On"




