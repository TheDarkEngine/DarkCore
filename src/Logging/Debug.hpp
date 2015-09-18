#ifndef DEBUG_HPP
#define DEBUG_HPP
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
#endif /* DEBUG_HPP */