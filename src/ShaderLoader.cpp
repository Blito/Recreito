#include "ShaderLoader.h"

#include <fstream>
#include <vector>
#include <iostream>

using namespace Core;

GLuint ShaderLoader::createProgram(const char * vertexShaderFileName,
                                   const char * fragmentShaderFileName)
{
    //read the shader files and save the code
    std::string vertex_shader_code = readShader(vertexShaderFileName);
    std::string fragment_shader_code = readShader(fragmentShaderFileName);
 
    GLuint vertex_shader = createShader(GL_VERTEX_SHADER, vertex_shader_code, "vertex shader");
    GLuint fragment_shader = createShader(GL_FRAGMENT_SHADER, fragment_shader_code, "fragment shader");
 
    int link_result = 0;
    //create the program handle, attatch the shaders and link it
    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
 
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &link_result);

    //check for link errors
    if (link_result == GL_FALSE)
    {
        int info_log_length = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);
        std::vector<char> program_log(info_log_length);
        glGetProgramInfoLog(program, info_log_length, NULL, &program_log[0]);
        std::cout << "Shader Loader : LINK ERROR" << std::endl << &program_log[0] << std::endl;
        return 0;
    }
   
    return program;
 }

std::string ShaderLoader::readShader(const char * fileName)
{
    //TODO: Check for a better way to read a file.
    //TODO: Improve error handling.
    std::string shaderCode;
    std::ifstream file(fileName, std::ios::in);
 
    if(!file.good())
    {
        std::cout<< "Can't read file " << fileName << std::endl;
        return "";
    }
 
    file.seekg(0, std::ios::end);
    shaderCode.resize((unsigned int)file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&shaderCode[0], shaderCode.size());
    file.close();

    return shaderCode;
}

GLuint ShaderLoader::createShader(GLenum shaderType,
                                  std::string source,
                                  const char * shaderName)
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