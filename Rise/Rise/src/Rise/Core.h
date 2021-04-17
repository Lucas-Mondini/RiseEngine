#pragma once

#include "RisePCH.h"

#ifdef RISE_PLATAFORM_WINDOWS
	#ifdef RISE_BUILD_DLL
		#define RISE_API __declspec(dllexport)
	#else
		#define RISE_API __declspec(dllimport)
	#endif
#else
#define RISE_PLATAFORM_UNKNOWN
#error non suported plataform
#endif 

#ifdef RISE_ENABLE_ASSERTS
	#define RISE_ASSERT(x, ...) { if(!x){RISE_CLIENT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RISE_CORE_ASSERT(x, ...) { if(!x){RISE_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define RISE_ASSERT(x, ...)
	#define RISE_CORE_ASSERT(x, ...) 
#endif



#define LShiftbit(x) (1 << x)