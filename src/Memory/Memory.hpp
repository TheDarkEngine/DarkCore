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
	PBYTE FindSignature(LPVOID BaseAddress, DWORD ImageSize, PCHAR Signature, PCHAR Mask);
	bool GetModuleInfo(DWORD& ImageSize, PBYTE& BaseAddress);

}

#endif /* DARKCORE_MEMORY_MEMORY_HPP */