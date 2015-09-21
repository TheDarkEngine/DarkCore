#include <DarkCore.hpp>

namespace Python
{
	//
	// DarkCore Python Module Container
	//

	wchar_t *Program;
	
	PyObject *DebugLog(PyObject *self, PyObject *args);
	PyObject *HookEvent(PyObject *self, PyObject *args);

	PyMethodDef Methods[] = {
		{ "debug_log", DebugLog, METH_VARARGS, "Passes a message to the debug log." },
		{ "hook_event", HookEvent, METH_VARARGS, "Hooks an event to a python function." },
		{ NULL, NULL, 0, NULL }
	};

	PyModuleDef Module = {
		PyModuleDef_HEAD_INIT, "darkcore", NULL, -1, Methods, NULL, NULL, NULL, NULL
	};

	PyObject *InitializeModule()
	{
		return PyModule_Create(&Module);
	}

	//
	// DarkCore Python API
	//

	bool Loaded = false;

	bool Initialize(std::string programName)
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

		AddToSearchPath(programDirectory.append("\\plugins\\"));

		Logging::Debug::WriteToLog("DarkCore Python API Initialized");

		return (Loaded = true);
	}

	bool AddToSearchPath(std::string directory)
	{
		auto path = PySys_GetObject("path");
		PyList_Append(path, PyUnicode_FromString(directory.c_str()));
		PySys_SetObject("path", path);

		return true;
	}

	PyObject *LoadModule(std::string moduleName)
	{
		return PyImport_ImportModule(moduleName.c_str());
	}

	void Finalize()
	{
		Py_Finalize();
		PyMem_RawFree(Python::Program);

		Logging::Debug::WriteToLog("DarkCore Python API Finalized");
	}

	//
	// Functions in the 'darkcore' module:
	//

	PyObject *DebugLog(PyObject *self, PyObject *args)
	{
		const char *msg = 0;

		if (!PyArg_ParseTuple(args, "s", &msg))
			return NULL;

		Logging::Debug::WriteToLog("%s", msg);

		return Py_None;
	}

	PyObject *HookEvent(PyObject *self, PyObject *args)
	{
		//
		// TODO: Load the plugin
		//

		return Py_None;
	}
}
