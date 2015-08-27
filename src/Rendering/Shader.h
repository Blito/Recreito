#ifndef SHADER_H
#define SHADER_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <string>

namespace Mgrs
{
    class ShaderMgr;
}

namespace Rendering
{
    class Shader
    {
    public:
        Shader(Mgrs::ShaderMgr & shaderMgr,
               const std::string & programName,
               const std::string & vertexShaderFileName,
               const std::string & fragmentShaderFileName);

        GLuint id() const;

        void use() const;

    protected:
        GLuint program_id = 0;
        Mgrs::ShaderMgr & shaderMgr;

    private:
        std::string readShaderFile(const std::string & fileName) const;
        GLuint createShader(GLenum shaderType,
                            const std::string & source,
                            const std::string & shaderName);

    };
} // end Rendering

#endif // SHADER_H
