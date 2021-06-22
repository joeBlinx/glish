//
// Created by stiven on 21/06/2021.
//

#ifndef GLISH3_UNIQUE_VBO_H
#define GLISH3_UNIQUE_VBO_H
#include "glish3/gl_glew.hpp"
namespace glish3 {
    struct UniqueVbo {
        UniqueVbo() = default;
        UniqueVbo(GLuint vbo) noexcept: _vbo(vbo) {}

        UniqueVbo(UniqueVbo const &) = delete;
        UniqueVbo &operator=(UniqueVbo const &) = delete;

        UniqueVbo(UniqueVbo &&old)noexcept : _vbo(old._vbo) { old._vbo = 0; }
        UniqueVbo &operator=(UniqueVbo &&old) noexcept {
            _vbo = old._vbo;
            old._vbo = 0;
            return *this;
        }

        ~UniqueVbo() {
            if (_vbo != 0) {
                glDeleteBuffers(1, &_vbo);
            }
        }
        GLuint get() const{ return _vbo;}

    private:
        GLuint _vbo{};
    };
}
#endif //GLISH3_UNIQUE_VBO_H
