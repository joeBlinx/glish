//
// Created by stiven on 10/31/18.
//
#include <glish3/uniform.hpp>
#include <glish3/glfunction.hpp>
#include <glish3/programGL.hpp>

namespace glish3 {
    Uniform::Uniform(std::string_view name, ProgramGL &prog):
                                                name(name),
                                                program(&prog)
    {
        uniform = glishGetUniformLocation((GLuint)prog, this->name.c_str());
    }

    Uniform::operator bool() const {
        return (bool) uniform;
    }

    Uniform::operator GLint() {
        return uniform;
    }
}
