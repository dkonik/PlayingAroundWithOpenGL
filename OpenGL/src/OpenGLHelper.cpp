#include <GL/glew.h>
#include <iostream>

#include "OpenGLHelper.h"

void ClearErrors()
{
	while (glGetError())
		;
}

bool CheckErrors(const char *function, const char *file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error (" << file << "::" << function << ":" << line << ")]: " << error << std::endl;
		return false;
	}
	return true;
}