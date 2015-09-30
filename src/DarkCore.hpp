#ifndef DARKCORE_HPP
#define DARKCORE_HPP

//
//	MSVC compiler-specific definitions
//
#ifdef _MSC_VER
#	pragma once

//	Disable warnings about not using "safe" C functions.
#	pragma warning (disable : 4996)

//	Include Windows-specific headers
#	define _CRT_SECURE_NO_WARNINGS
#	define WIN32_LEAN_AND_MEAN
#	include <Windows.h>
#	include <resource.h>

//	Library Imports/Exports
#	ifdef DarkCore_EXPORTS
#		define DarkCoreAPI __declspec(dllexport)
#	else
#		define DarkCoreAPI __declspec(dllimport)
#	endif /* DarkCore_EXPORTS */

//	Hook Definitions
#	define Hook(func1, func2) o##func1 = (t##func1)GetProcAddress(hMod, #func2)
#	define DetourHook(func) o##func = (t##func)DetourAttach(&(PVOID&)GetProcAddress(hMod, #func), hk##func)
#	define DetourUnhook(func) DetourDetach(&(PVOID&)o##func, hk##func);

#endif /* _MSC_VER */

//
// Common Headers
//
#include <Psapi.h>

// Standard Library Headers
#include <fstream>
#include <string>
#include <sstream>

// Detours Headers
#include <detours.h>

// libwebsockets Headers
#include <libwebsockets.h>
#include <websock-w32.h>
#include <gettimeofday.h>

// RapidJSON Headers
#include <ThirdParty\rapidjson\document.h>
#include <ThirdParty\rapidjson\writer.h>
#include <ThirdParty\rapidjson\stringbuffer.h>

// Python Headers
#include <Python.h>

// DarkCore Headers
#include <Logging/Debug.hpp>
#include <Python/Python.hpp>
#include <WebSockets/WebSockets.hpp>
#include <Memory/D3D9.hpp>
#include <Memory/Memory.hpp>

namespace DarkCore
{
	extern DarkCoreAPI HMODULE Module;

	DarkCoreAPI bool Initialize(HMODULE module);
	DarkCoreAPI bool Finalize();
}

#endif /* DARKCORE_HPP */
