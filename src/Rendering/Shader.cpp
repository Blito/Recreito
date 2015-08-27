#include "Shader.h"

#include <fstream>
#include <vector>
#include <iostream>

#include "../Mgrs/ShaderMgr.h"

using namespace Rendering;

Shader::Shader(Mgrs::ShaderMgr & shaderMgr,
               const std::string & programName,
               const std::string & vertexShaderFileName,
               const std::string & fragmentShaderFileName)
    : shaderMgr(shaderMgr)
{
    // check for existing program
//    GLuint program = isValid(programName);
//    if (program != 0)
//        return program;

    //read the shader files and save the code
    std::string && vertex_shader_code = readShaderFile(vertexShaderFileName);
    std::string && fragment_shader_code = readShaderFile(fragmentShaderFileName);

    GLuint vertex_shader = createShader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
    GLuint fragment_shader = createShader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");

    int link_result = 0;
    //create the program handle, attatch the shaders and link it
    program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader);
    glAttachShader(program_id, fragment_shader);

    glLinkProgram(program_id);
    glGetProgramiv(program_id, GL_LINK_STATUS, &link_result);

    //check for link errors
    if (link_result == GL_FALSE)
    {
        int info_log_length = 0;
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &info_log_length);
        std::vector<char> program_log(info_log_length);
        glGetProgramInfoLog(program_id, info_log_length, NULL, &program_log[0]);
        std::cout << "Shader Loader : LINK ERROR" << std::endl << &program_log[0] << std::endl;
        program_id = 0;
    }
}

GLuint Shader::id() const
{
    return program_id;
}

std::string Shader::readShaderFile(const std::string & fileName) const
{
    //TODO: Check for a better way to read a file.
    //TODO: Improve error handling.
    std::string shaderCode;
    std::ifstream file(fileName.c_str(), std::ios::in);

    if(!file.good())
    {
        std::cout << "Can't read file " << fileName << std::endl;
        return "";
    }

    file.seekg(0, std::ios::end);
    shaderCode.resize((unsigned int)file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&shaderCode[0], shaderCode.size());
    file.close();

    return shaderCode;
}

GLuint Shader::createShader(GLenum shaderType,
                               const std::string & source,
                               const std::string & shaderName)
{
    int compile_result = 0;

    GLuint shader = glCreateShader(shaderType);
    const char * shader_code_ptr = source.c_str();
    const int shader_code_size = source.size();

    glShaderSource(shader, 1, &shader_code_ptr, &shader_code_size);
    glCompileShader(shader);

    //check for errors
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_result);
    if (compile_result == GL_FALSE)
    {
        int info_log_length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
        std::vector<char> shader_log(info_log_length);
        glGetShaderInfoLog(shader, info_log_length, NULL, &shader_log[0]);
        std::cout << "ERROR compiling shader: " << shaderName << std::endl << &shader_log[0] << std::endl;
        return 0;
    }

    return shader;
}
