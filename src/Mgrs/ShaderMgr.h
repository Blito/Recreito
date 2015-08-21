#ifndef SHADER_MGR_H
#define SHADER_MGR_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <string>
#include <map>

namespace Mgrs
{
    class ShaderMgr
    {
    public:
        ~ShaderMgr();

        GLuint isValid(const std::string & programName) const;

        GLuint createProgram(const std::string & programName,
                             const std::string & vertexShaderFileName,
                             const std::string & fragmentShaderFileName);

    private:
        std::string readShader(const std::string & fileName);
        GLuint createShader(GLenum shaderType,
                            const std::string & source,
                            const std::string & shaderName);

        std::map<std::string, GLuint> programs;


    };
}

#endif
