#include <DarkCore.hpp>

wchar_t *Python::Program;

PyModuleDef Python::Module = {
	PyModuleDef_HEAD_INIT, "darkcore", NULL, -1, Python::Methods, NULL, NULL, NULL, NULL
};

PyMethodDef Python::Methods[] = {
	{ "debug_log", Python::DebugLog, METH_VARARGS, "Passes a message to the debug log." },
	{ "hook_event", Python::HookEvent, METH_VARARGS, "Hooks an event to a python function." },
	{ NULL, NULL, 0, NULL }
};

//
// Toplevel functions:
//

bool Python::Initialize(std::string programName)
{
	//
	// Setup the internal program name
	//

	const char *programNameStr;
	
	if (!(Python::Program = Py_DecodeLocale((programNameStr = programName.c_str()), 0)))
	{
		Logging::Debug::WriteToLog("FATAL: Cannot decode program: %s", programNameStr);
		return false;
	}

	Py_SetProgramName(Python::Program);

	//
	// Initialize the 'darkcore' internal module
	//

	PyImport_AppendInittab("darkcore", &Python::InitializeModule);
	Py_Initialize();

	//
	// Add the 'plugins' directory to the python module path
	//

	auto lastSlashIndex = programName.rfind('\\');
	auto programDirectory = lastSlashIndex != std::string::npos ? programName.substr(0, lastSlashIndex) : "";

	auto path = PySys_GetObject("path");
	PyList_Append(path, PyUnicode_FromString(programDirectory.append("\\plugins\\").c_str()));
	PySys_SetObject("path", path);


	Logging::Debug::WriteToLog("DarkCore Python API Initialized");


	//
	// Import halo_online module as a test
	//

	auto module = PyImport_ImportModule("halo_online");

	if (!module)
		MessageBox(0, "Failed to import 'halo_online' module.", "", MB_OK);
	
	Logging::Debug::WriteToLog("Imported '%s' module", PyModule_GetName(module));

	return true;
}

PyObject *Python::InitializeModule()
{
	return PyModule_Create(&Python::Module);
}

void Python::Finalize()
{
	Py_Finalize();
	PyMem_RawFree(Python::Program);

	Logging::Debug::WriteToLog("DarkCore Python API Finalized");
}

//
// Functions in the 'darkcore' module:
//

PyObject *Python::DebugLog(PyObject *self, PyObject *args)
{
	const char *msg = 0;

	if (!PyArg_ParseTuple(args, "s", &msg))
		return NULL;

	Logging::Debug::WriteToLog("%s", msg);

	return Py_None;
}

PyObject *Python::HookEvent(PyObject *self, PyObject *args)
{
	//
	// TODO: Load the plugin
	//

	return Py_None;
}
