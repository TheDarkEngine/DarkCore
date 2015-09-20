#include <DarkCore.hpp>

HMODULE DarkCore::Module;

bool DarkCore::Initialize(HINSTANCE module)
{
	DarkCore::Module = module;

	DisableThreadLibraryCalls(module);

	//
	// Find the path of the module
	//

	char currentPath[MAX_PATH];
	GetModuleFileName(module, currentPath, MAX_PATH);

	//
	// Initialize subsystems
	//

	Logging::Debug::InitDebugLogging(module);
	Python::Initialize(currentPath);
	CreateThread(0, 0, WebSockets::Server::Start, 0, 0, 0);

	return true;
}

//
// DarkExit should contain any cleanup necessary to safely unload DarkCore 
//
bool DarkCore::Finalize()
{
	// Cleanup Plugins
	Python::Finalize();

	// Cleanup Web API
	WebSockets::Server::Stop();

	// Stop Logging
	Logging::Debug::ExitDebugLogging();

	return true;
}

//
// This temporary hooking that requires an injector.
// This should be replaced with a better hijack method
//
BOOL WINAPI DllMain(HMODULE hMod, long ulReason, void* pvReserved)
{
	switch (ulReason)
	{
	case DLL_PROCESS_ATTACH:
		return DarkCore::Initialize(hMod) ? TRUE : FALSE;
	
	case DLL_PROCESS_DETACH:
		return DarkCore::Finalize() ? TRUE : FALSE;
	
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		return TRUE;
	}

	return FALSE;
}