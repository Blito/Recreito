#include "ShaderMgr.h"

#include "Shader.h"

#include <iostream>

using namespace Mgrs;

ShaderMgr::~ShaderMgr()
{
    for (auto program : programs)
    {
        glDeleteProgram(program.second->id());
    }
}

Rendering::Shader * ShaderMgr::getProgram(const std::string & programName) const
{
    auto shader = programs.find(programName);

    return shader != programs.end() ? shader->second : nullptr;
}

Rendering::Shader * ShaderMgr::getDefaultProgram() const
{
    return getProgram(defaultProgram);
}

GLuint ShaderMgr::getProgramID(const std::string & programName) const
{
    auto p = programs.find(programName);

    return p != programs.end() ? p->second->id() : 0;
}

Rendering::Shader *ShaderMgr::createProgram(const std::string & programName,
                                const std::string & vertexShaderFileName,
                                const std::string & fragmentShaderFileName,
                                bool setAsDefault)
{
    std::cout << programName << std::endl;
    // check for existing program
    auto program = getProgram(programName);
    if (program > 0)
        return program;

    program = new Rendering::Shader(*this,
                                    programName,
                                    vertexShaderFileName,
                                    fragmentShaderFileName);

    if (program->id())
    {
        programs[programName] = program;
    }

    if (setAsDefault)
    {
        defaultProgram = programName;
    }

    return program;
}
