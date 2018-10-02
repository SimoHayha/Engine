#pragma once

#ifdef ENGINE_EXPORTS
	#define ENGINE_EXPORT __declspec(dllexport)
#else
	#define ENGINE_EXPORT __declspec(dllimport)
#endif