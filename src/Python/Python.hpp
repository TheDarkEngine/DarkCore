#ifndef DARKCORE_PYTHON_PYTHON_HPP
#define DARKCORE_PYTHON_PYTHON_HPP

#ifdef _MSC_VER
#	pragma once
#endif	/* _MSC_VER */

namespace Python
{
	extern DarkCoreAPI wchar_t *Program;
	extern DarkCoreAPI PyModuleDef Module;
	extern DarkCoreAPI PyMethodDef Methods[];

	//
	// Toplevel functions:
	//

	DarkCoreAPI bool Initialize(std::string programName);
	DarkCoreAPI PyObject *InitializeModule();
	DarkCoreAPI void Finalize();

	//
	// Functions in the 'darkcore' module:
	//

	DarkCoreAPI PyObject *DebugLog(PyObject *self, PyObject *args);
	DarkCoreAPI PyObject *HookEvent(PyObject *self, PyObject *args);
}

#endif /* DARKCORE_PYTHON_PYTHON_HPP */
