#include <windows.h>
#include <stdio.h>
#include <detours.h>
#include "Logging\Debug.hpp"
#include "WebSockets\WebSockets.hpp"
#include "Main.hpp"

BOOL DarkInit(HINSTANCE hModule)
{
	DisableThreadLibraryCalls(hModule);
	Logging::Debug::InitDebugLogging(hModule);

	CreateThread(0, 0, StartWebSocketServer, 0, 0, 0);

	return TRUE;
}

BOOL DarkExit()
{
	Logging::Debug::ExitDebugLogging();
	return TRUE;
}

//This temporary hooking that requires an injector.
//This should be replaced with a better hijack method
BOOL WINAPI DllMain(HMODULE hMod, long ulReason, void* pvReserved)
{
	switch (ulReason)
	{
	case DLL_PROCESS_ATTACH:
		return DarkInit(hMod);
	
	case DLL_PROCESS_DETACH:
		return DarkExit();
	
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		return TRUE;
	}

	return FALSE;
}