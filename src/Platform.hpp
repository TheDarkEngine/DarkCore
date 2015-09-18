
//
//	MSVC compiler-specific definitions
//

#ifdef _MSC_VER
#	pragma once

//	Disable warnings about not using "safe" C functions.
#	pragma warning (disable : 4996)

//	Include Windows-specific headers
#	define WIN32_LEAN_AND_MEAN
#	include <Windows.h>

#endif /* _MSC_VER */

//
// Standard Library Headers
//

#include <string>
