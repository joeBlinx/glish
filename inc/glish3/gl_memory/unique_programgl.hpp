//
// Created by stiven on 21/06/2021.
//

#ifndef GLISH3_UNIQUE_PROGRAMGL_HPP
#define GLISH3_UNIQUE_PROGRAMGL_HPP
namespace glish3 {
    struct UniqueProgramGL {
        UniqueProgramGL(GLuint program_gl) noexcept: _program_gl(program_gl) {}

        UniqueProgramGL(UniqueProgramGL const &) = delete;
        UniqueProgramGL &operator=(UniqueProgramGL const &) = delete;

        UniqueProgramGL(UniqueProgramGL &&old) noexcept : _program_gl(old._program_gl) { old._program_gl = 0; }
        UniqueProgramGL &operator=(UniqueProgramGL &&old) noexcept {
            _program_gl = old._program_gl;
            old._program_gl = 0;
            return *this;
        }

        ~UniqueProgramGL() {
            if (_program_gl != 0) {
                glDeleteBuffers(1, &_program_gl);
            }
        }
        GLuint get() const{ return _program_gl;}
        operator GLuint() const{return get();}

    private:
        GLuint _program_gl{};
    };
    inline UniqueProgramGL make_unique_gl_program(){
        return {glCreateProgram()};
    }
}
#endif //GLISH3_UNIQUE_PROGRAMGL_HPP
