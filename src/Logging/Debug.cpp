#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include "Debug.hpp"

#define LOGNAME "DarkCore-Debug.log"

namespace Logging
{
	std::ofstream ofile;
	char dlldir[320];

	//TODO: move into a helper class somewhere so we can use this elsewhere
	const std::string currentDateTime() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
		// for more information about date/time format
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

		return buf;
	}
	char *Debug::GetDirectoryFile(char* filename)
	{
		static char path[320];
		strcpy_s(path, dlldir);
		strcat_s(path, filename);
		return path;
	}
	void __cdecl Debug::WriteToLog(const char* fmt, ...)
	{
		if (ofile)
		{
			if (!fmt)
				return;

			va_list va_alist;
			char logbuf[256] = { 0 };

			va_start(va_alist, fmt);
			_vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), fmt, va_alist);
			va_end(va_alist);

			ofile << currentDateTime() + ": " +logbuf << std::endl;
		}
	}

	void Debug::InitDebugLogging(HMODULE hModule)
	{
		GetModuleFileNameA(hModule, dlldir, 512);

		for (int i = (int)strlen(dlldir); i > 0; i--)
		{
			if (dlldir[i] == '\\')
			{
				dlldir[i + 1] = 0;
				break;
			}
		}

		ofile.open(GetDirectoryFile(LOGNAME), std::ios::app);

		WriteToLog("----------------------------------------");
		WriteToLog("DarkCore Debug Logging Initialized");
		WriteToLog("----------------------------------------");
	}

	void Debug::ExitDebugLogging()
	{
		WriteToLog("----------------------------------------");
		WriteToLog("DarkCore Exited");
		WriteToLog("----------------------------------------");
		ofile.close();
	}
}