//
// Created by stiven on 10/31/18.
//

#ifndef GLISH3_UNIFORM_H
#define GLISH3_UNIFORM_H
#include <glish3/gl_glew.hpp>
#include <string>
namespace glish3 {

    class ProgramGL;

    class Uniform {

        std::string name;
        ProgramGL *program = nullptr;
        GLint uniform = 0;

    public:

        Uniform() = default;

        Uniform(std::string_view name, ProgramGL &prog);


        operator bool() const;

        explicit operator GLint();


    };
}
#endif //GLISH3_UNIFORM_H
