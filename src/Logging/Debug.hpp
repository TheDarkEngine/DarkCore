#ifndef DARKCORE_LOGGING_DEBUG_HPP
#define DARKCORE_LOGGING_DEBUG_HPP

#ifdef _MSC_VER
#	pragma once
#endif	/* _MSC_VER */

namespace Logging
{
	class Debug
	{
	public:
		static void __cdecl WriteToLog(const char* fmt, ...);
		static void InitDebugLogging(HMODULE hModule);
		static void ExitDebugLogging();

	private:
		static char *GetDirectoryFile(char* filename);
	};
}

#endif /* DARKCORE_LOGGING_DEBUG_HPP */
