#ifndef DARKCORE_PYTHON_PYTHON_HPP
#define DARKCORE_PYTHON_PYTHON_HPP

#include "../Platform.hpp"

class Python
{
public:
	static bool Initialize(std::string programName);
	static void Finalize();

private:
	static wchar_t *Program;
};

#endif /* DARKCORE_PYTHON_PYTHON_HPP */
