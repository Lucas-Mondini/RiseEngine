project "GLEW"
    kind "StaticLib"
    language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
        "include/GL/eglew.h",
        "include/GL/glew.h",
        "include/GL/glxew.h",
        "include/GL/wglew.h",
        "src/glew.c",
        "src/glewinfo.c",
        "src/visualinfo.c"
    }
    includedirs{
        "include"
    }

	filter "system:windows"
        buildoptions { "-std=c11" }
        systemversion "10.0.18362.0"
        staticruntime "On"

        files
        {
            "src/glew.c",
            "src/glewinfo.c",
            "src/visualinfo.c"
        }

		defines 
		{ 
            "_GLEW_WIN32"
		}
    filter { "system:windows", "configurations:Release" }
        buildoptions "/MT"