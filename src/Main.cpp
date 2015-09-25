#include <DarkCore.hpp>

static DarkCore::Container *Core = NULL;

BOOL WINAPI DllMain(HMODULE hMod, long ulReason, void* pvReserved)
{
	switch (ulReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			char applicationPathStr[MAX_PATH];
			GetModuleFileName(hMod, applicationPathStr, MAX_PATH);

			auto applicationPath = std::string(applicationPathStr);
			auto lastSlashIndex = applicationPath.rfind('\\');
			auto programDirectory = lastSlashIndex != std::string::npos ? applicationPath.substr(0, lastSlashIndex) : "";

			Core = new DarkCore::Container({
				new DarkCore::LogComponent(programDirectory.append("\\DarkCore-Debug.log")),
				new DarkCore::PythonComponent(applicationPath)
			});

			//
			// TODO: Add other components to the core here.
			//

			return Core->Initialize() ? TRUE : FALSE;
		}

		case DLL_PROCESS_DETACH:
			if (Core != NULL)
				Core->Finalize();
			return TRUE;

		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			return TRUE;
	}

	return FALSE;
}
