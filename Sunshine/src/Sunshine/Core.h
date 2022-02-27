#pragma once

#ifdef SU_PLATFORM_WINDOWS
	#ifdef SU_BUILD_DLL
		#define SUNSHINE_API __declspec(dllexport)
	#else
		#define SUNSHINE_API __declspec(dllimport)
	#endif
#else
	#error Sunshine only supports Windows
#endif
