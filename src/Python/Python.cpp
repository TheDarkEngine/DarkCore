#include <Python.h>
#include "../Logging/Debug.hpp"
#include "Python.hpp"

wchar_t *Python::Program;

PyMethodDef Python::Methods[] = {
	{ "debug_log", Python::DebugLog, METH_VARARGS, "Passes a message to the debug log." },
	{ NULL, NULL, 0, NULL }
};

PyModuleDef Python::Module = {
	PyModuleDef_HEAD_INIT, "darkcore", NULL, -1, Python::Methods, NULL, NULL, NULL, NULL
};

bool Python::Initialize(std::string programName)
{
	const char *programNameStr;
	
	if (!(Python::Program = Py_DecodeLocale((programNameStr = programName.c_str()), 0)))
	{
		Logging::Debug::WriteToLog("FATAL: Cannot decode program: %s", programNameStr);
		return false;
	}

	Py_SetProgramName(Python::Program);
	PyImport_AppendInittab("darkcore", &Python::CreateModule);
	Py_Initialize();

	Logging::Debug::WriteToLog("DarkCore Python API Initialized");

	return true;
}

PyObject *Python::CreateModule()
{
	return PyModule_Create(&Python::Module);
}

void Python::Finalize()
{
	Py_Finalize();
	PyMem_RawFree(Python::Program);

	Logging::Debug::WriteToLog("DarkCore Python API Finalized");
}

PyObject *Python::DebugLog(PyObject *self, PyObject *args)
{
	const char *msg = 0;

	if (!PyArg_ParseTuple(args, "s", &msg))
		return NULL;

	Logging::Debug::WriteToLog("%s", msg);

	return Py_None;
}
