#ifndef DARKCORE_MAIN_HPP
#define DARKCORE_MAIN_HPP

#include "Platform.hpp"

#ifdef DarkCore_EXPORTS
#	define DarkCoreAPI extern "C" __declspec(dllexport)
#else
#	define DarkCoreAPI extern "C" __declspec(dllimport)
#endif /* DarkCore_EXPORTS */

#define Hook(func1, func2) o##func1 = (t##func1)GetProcAddress(hMod, #func2)
#define DetourHook(func) o##func = (t##func)DetourAttach(&(PVOID&)GetProcAddress(hMod, #func), hk##func)
#define DetourUnhook(func) DetourDetach(&(PVOID&)o##func, hk##func);

#endif /* DARKCORE_MAIN_HPP */
