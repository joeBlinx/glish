//
// Created by stiven on 21/06/2021.
//

#ifndef GLISH3_UNIQUE_VBO_H
#define GLISH3_UNIQUE_VBO_H
#include "glish3/gl_glew.hpp"
namespace glish3 {
    struct UniqueBuffer {
        UniqueBuffer() = default;
        UniqueBuffer(GLuint vbo) noexcept: _buffer(vbo) {}

        UniqueBuffer(UniqueBuffer const &) = delete;
        UniqueBuffer &operator=(UniqueBuffer const &) = delete;

        UniqueBuffer(UniqueBuffer &&old)noexcept : _buffer(old._buffer) { old._buffer = 0; }
        UniqueBuffer &operator=(UniqueBuffer &&old) noexcept {
            _buffer = old._buffer;
            old._buffer = 0;
            return *this;
        }

        ~UniqueBuffer() {
            if (_buffer != 0) {
                glDeleteBuffers(1, &_buffer);
            }
        }
        GLuint get() const{ return _buffer;}

    private:
        GLuint _buffer{};
    };
}
#endif //GLISH3_UNIQUE_VBO_H
