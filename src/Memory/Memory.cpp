#include <DarkCore.hpp>

namespace Memory
{
	int CompareByteArray(PBYTE ByteArray1, PCHAR ByteArray2, PCHAR Mask, DWORD Length)
	{
		DWORD nextStart = 0;
		char start = ByteArray2[0];
		for (DWORD i = 0; i < Length; i++)
		{
			if (Mask[i] == '?')
			{
				continue;
			}	
			if (ByteArray1[i] == start)
			{
				nextStart = i;
			}
			if (ByteArray1[i] != (BYTE)ByteArray2[i])
			{
				return nextStart;
			}
		}
		return -1;
	}

	PBYTE FindSignature(LPVOID BaseAddress, DWORD ImageSize, PCHAR Signature, PCHAR Mask)
	{
		PBYTE Address = NULL;
		PBYTE Buffer = (PBYTE)BaseAddress;

		if (GetModuleInfo(ImageSize, Buffer))
		{

			DWORD Length = strlen(Mask);

			for (DWORD i = 0; i < (ImageSize - Length); i++)
			{
				int result = CompareByteArray((Buffer + i), Signature, Mask, Length);
				if (result < 0)
				{
					Address = (PBYTE)BaseAddress + i;
					break;
				}
				else
				{
					i += result;
				}
			}
		}

		return Address;
	}

	bool GetModuleInfo(DWORD& ImageSize, PBYTE& BaseAddress)
	{
		MODULEINFO ModuleInfo; 
		memset(&ModuleInfo, 0, sizeof(ModuleInfo));

		if (GetModuleInformation(GetCurrentProcess(), NULL, &ModuleInfo, sizeof(ModuleInfo)))
		{
			ImageSize = ModuleInfo.SizeOfImage;
			BaseAddress = (PBYTE)ModuleInfo.lpBaseOfDll;
			return true;
		}
		return false;
	}
};