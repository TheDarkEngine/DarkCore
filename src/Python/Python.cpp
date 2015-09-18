#include <Python.h>
#include "../Logging/Debug.hpp"
#include "Python.hpp"

bool Python::Initialize(std::string programName)
{
	const char *programNameStr;
	
	if (!(Python::Program = Py_DecodeLocale((programNameStr = programName.c_str()), 0)))
	{
		Logging::Debug::WriteToLog("FATAL: Cannot decode program: %s", programNameStr);
		return false;
	}

	Py_SetProgramName(Python::Program);
	Py_Initialize();

	return true;
}

void Python::Finalize()
{
	Py_Finalize();
	PyMem_RawFree(Python::Program);
}
