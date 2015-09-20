#ifndef DARKCORE_PYTHON_PYTHON_HPP
#define DARKCORE_PYTHON_PYTHON_HPP

#include <Python.h>
#include "../Main.hpp"

namespace Python
{
	DarkCoreAPI wchar_t *Program;
	DarkCoreAPI PyMethodDef Methods[];
	DarkCoreAPI PyModuleDef Module;

	class Object
	{
	public:
		Object();

	private:
		PyObject *Value;
	};

	//
	// Toplevel functions:
	//

	DarkCoreAPI bool Initialize(std::string programName);
	DarkCoreAPI PyObject *CreateModule();
	DarkCoreAPI void Finalize();

	//
	// Functions in the 'darkcore' module:
	//

	DarkCoreAPI PyObject *DebugLog(PyObject *self, PyObject *args);
}

#endif /* DARKCORE_PYTHON_PYTHON_HPP */
