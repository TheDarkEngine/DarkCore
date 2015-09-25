#ifndef DARKCORE_PYTHON_PYTHON_COMPONENT_HPP
#define DARKCORE_PYTHON_PYTHON_COMPONENT_HPP

#ifdef _MSC_VER
#	pragma once
#endif /* _MSC_VER */

namespace DarkCore
{
	class PythonComponent : public Component
	{
	public:
		DarkCoreAPI PythonComponent(const std::string &applicationPath, Container *parent = NULL);

		DarkCoreAPI bool Initialize();
		DarkCoreAPI void Finalize();

		DarkCoreAPI void AddToSearchPath(const std::string &directoryPath);
		DarkCoreAPI PyObject *LoadModule(const std::string &moduleName);

		DarkCoreAPI friend PyObject *DebugLog(PyObject *self, PyObject *args);
		DarkCoreAPI friend PyObject *HookEvent(PyObject *self, PyObject *args);

	protected:
		bool Initialized;
		DarkCoreAPI static PythonComponent *Instance;

		wchar_t *WideApplicationPath;
		std::string ApplicationPath;

	};
}

#endif /* DARKCORE_PYTHON_PYTHON_COMPONENT_HPP */
