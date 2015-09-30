#include <DarkCore.hpp>

namespace DarkCore
{
	//
	// 'darkcore' Python Module Definitions
	//

	PythonComponent *PythonComponent::Instance = NULL;

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

	PythonComponent::PythonComponent(const std::string &applicationPath, const std::string &name, Container *parent)
		: Component(name, parent), ApplicationPath(applicationPath) {}

	bool PythonComponent::Initialize()
	{
		if (PythonComponent::Instance && PythonComponent::Instance->Initialized)
			return true;

		LogComponent *log = this->GetSibling<LogComponent>();

		//
		// Setup the internal program name
		//

		const char *programNameStr;

		if (!(this->WideApplicationPath = Py_DecodeLocale((programNameStr = this->ApplicationPath.c_str()), 0)))
		{
			*log << "FATAL: Cannot decode program: " << programNameStr;

			return false;
		}

		Py_SetProgramName(this->WideApplicationPath);

		//
		// Initialize the 'darkcore' internal module
		//

		PyImport_AppendInittab("darkcore", &InitializeModule);
		Py_Initialize();

		//
		// Add the 'plugins' directory to the python module path
		//

		auto lastSlashIndex = this->ApplicationPath.rfind('\\');
		auto programDirectory = lastSlashIndex != std::string::npos ? this->ApplicationPath.substr(0, lastSlashIndex) : "";

		AddToSearchPath(programDirectory.append("\\plugins\\"));

		*log << "DarkCore Python Component Initialized";

		PythonComponent::Instance = this;

		return (this->Initialized = true);
	}

	void PythonComponent::Finalize()
	{
		Py_Finalize();
		PyMem_RawFree(this->WideApplicationPath);

		this->Initialized = false;

		auto log = this->GetSibling<LogComponent>();

		*log << "DarkCore Python Component Finalized";
	}

	void PythonComponent::AddToSearchPath(const std::string &directoryPath)
	{
		auto path = PySys_GetObject("path");
		PyList_Append(path, PyUnicode_FromString(directoryPath.c_str()));
		PySys_SetObject("path", path);
	}

	PyObject *PythonComponent::LoadModule(const std::string &moduleName)
	{
		return PyImport_ImportModule(moduleName.c_str());
	}

	PyObject *DebugLog(PyObject *self, PyObject *args)
	{
		const char *msg = 0;

		if (!PyArg_ParseTuple(args, "s", &msg))
			return NULL;

		LogComponent *log = NULL;

		if (PythonComponent::Instance != NULL)
			log = PythonComponent::Instance->GetSibling<LogComponent>();

		*log << msg;

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
