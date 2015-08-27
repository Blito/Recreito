#ifndef SHADER_MGR_H
#define SHADER_MGR_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <string>
#include <map>

namespace Rendering
{
    class Shader;
}

namespace Mgrs
{
    class ShaderMgr
    {
    public:
        ~ShaderMgr();

        Rendering::Shader * getProgram(const std::string & programName) const;

        GLuint getProgramID(const std::string & programName) const;

        Rendering::Shader * createProgram(
                                const std::string & programName,
                                const std::string & vertexShaderFileName,
                                const std::string & fragmentShaderFileName);

    private:
        std::map<std::string, Rendering::Shader*> programs;
    };
}

#endif
