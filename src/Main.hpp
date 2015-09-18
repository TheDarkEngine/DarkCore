#ifndef MAIN_HPP
#define MAIN_HPP

#define Hook(func1, func2) o##func1 = (t##func1)GetProcAddress(hMod, #func2)
#define DetourHook(func) o##func = (t##func)DetourAttach(&(PVOID&)GetProcAddress(hMod, #func), hk##func)
#define DetourUnhook(func) DetourDetach(&(PVOID&)o##func, hk##func);
#define DllExport extern "C" __declspec(dllexport)
#endif