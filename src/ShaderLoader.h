#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <string>

namespace Core
{
	class ShaderLoader
	{
	public:
		GLuint createProgram(const char * vertexShaderFileName,
							 const char * fragmentShaderFileName);

	private:
		std::string readShader(const char * fileName);
		GLuint createShader(GLenum shaderType,
							std::string source,
							const char * shaderName);
	};
}


#endif