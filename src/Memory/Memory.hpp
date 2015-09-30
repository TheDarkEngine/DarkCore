#ifndef DARKCORE_MEMORY_MEMORY_HPP
#define DARKCORE_MEMORY_MEMORY_HPP

#ifdef _MSC_VER
#	pragma once
#endif	/* _MSC_VER */

namespace Memory
{
	bool Initialize();
	void Dispose();

	int CompareByteArray(PBYTE ByteArray1, PCHAR ByteArray2, PCHAR Mask, DWORD Length);
	DarkCoreAPI PBYTE FindSignature(LPVOID BaseAddress, DWORD ImageSize, PCHAR Signature, PCHAR Mask);
	bool GetModuleInfo(DWORD& ImageSize, PBYTE& BaseAddress);

	static int Filter(unsigned int code, struct _EXCEPTION_POINTERS *ep)
	{
		// Handle only AV
		return code == EXCEPTION_ACCESS_VIOLATION ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH;
	}

	template <typename T>
	T Read(uintptr_t Address, const T& def_val = T())
	{
		__try	
		{
			return *(T*)(Address);
		}
		__except (Filter(GetExceptionCode(), GetExceptionInformation()))
		{
			return def_val;
		}
	}

	template <class T>
	bool Write(uintptr_t Address, T Value)
	{
		__try
		{
			*(T*)Address = Value;
		}
		__except (Filter(GetExceptionCode(), GetExceptionInformation()))
		{
			return false;
		}
		return true;
	}

}

#endif /* DARKCORE_MEMORY_MEMORY_HPP */