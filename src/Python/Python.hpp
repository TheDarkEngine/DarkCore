#ifndef DARKCORE_PYTHON_PYTHON_HPP
#define DARKCORE_PYTHON_PYTHON_HPP

#ifdef _MSC_VER
#	pragma once
#endif	/* _MSC_VER */

namespace Python
{
	DarkCoreAPI bool Initialize(std::string programName);
	DarkCoreAPI bool AddToSearchPath(std::string directory);
	DarkCoreAPI PyObject *LoadModule(std::string moduleName);
	DarkCoreAPI void Finalize();
}

#endif /* DARKCORE_PYTHON_PYTHON_HPP */
