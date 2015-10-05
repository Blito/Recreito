#ifndef SHADER_H
#define SHADER_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <string>
#include <unordered_map>

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

        GLint getUniform(const std::string & uniformName) const;

        void enable() const;

    protected:
        GLuint program_id = 0;
        Mgrs::ShaderMgr & shaderMgr;
        std::unordered_map<std::string, GLint> uniforms;

    private:
        std::string readShaderFile(const std::string & fileName) const;
        GLuint createShader(GLenum shaderType,
                            const std::string & source,
                            const std::string & shaderName);

        /**
         * @brief loadUniformIndices Queries OpenGL for the uniforms locations
         * and stores them in the uniforms cache.
         * @return true if at least one active uniform was found
         */
        bool loadUniformIndices();
        bool uniformsLoaded = false;
    };
} // end Rendering

#endif // SHADER_H
