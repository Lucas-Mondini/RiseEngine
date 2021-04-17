workspace "Rise"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Includes to root (SolutionDir)
IncludeDir = {}
IncludeDir["GLFW"] = "Rise/vendor/GLFW/include"

include "Rise/vendor/GLFW"

project "Rise" 
	location "Rise"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	pchheader "RisePCH.h"
	pchsource "%{prj.name}/src/RisePCH.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/SPDLog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect"C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines {
		"RISE_PLATAFORM_WINDOWS",
		"RISE_BUILD_DLL"
		}
		
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir.. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "RISE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "RISE_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "RISE_DIST"
			optimize "On"


project "Sandbox" 
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Rise/vendor/SPDLog/include",
		"Rise/src"
	}
	
	links{
		"Rise"
	}

	filter "system:windows"
		cppdialect"C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines {
		"RISE_PLATAFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "RISE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "RISE_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "RISE_DIST"
			optimize "On"
