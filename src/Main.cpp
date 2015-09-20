#include <windows.h>
#include <stdio.h>
#include <detours.h>
#include "Logging\Debug.hpp"
#include "Python\Python.hpp"
#include "WebSockets\WebSockets.hpp"
#include "Main.hpp"

BOOL DarkInit(HINSTANCE hModule)
{
	DisableThreadLibraryCalls(hModule);

	//
	// Find the path of the module
	//

	char currentPath[MAX_PATH];
	GetModuleFileName(hModule, currentPath, MAX_PATH);

	//
	// Initialize subsystems
	//

	Logging::Debug::InitDebugLogging(hModule);
	Python::Initialize(currentPath);
	CreateThread(0, 0, WebSockets::Server::Start, 0, 0, 0);

	return TRUE;
}

BOOL DarkExit()
{
	Python::Finalize();
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