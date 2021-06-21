//
// Created by stiven on 21/06/2021.
//

#ifndef GLISH3_UNIQUE_SHADER_HPP
#define GLISH3_UNIQUE_SHADER_HPP
#include <glish3/gl_glew.hpp>
namespace glish3 {
    struct UniqueShader {
        UniqueShader(GLuint shader) noexcept: _shader(shader) {}

        UniqueShader(UniqueShader const &) = delete;
        UniqueShader &operator=(UniqueShader const &) = delete;
        
        UniqueShader(UniqueShader &&old) noexcept : _shader(old._shader) { old._shader = 0; }
        UniqueShader &operator=(UniqueShader &&old) noexcept {
            _shader = old._shader;
            old._shader = 0;
            return *this;
        }

        ~UniqueShader() {
            if (_shader != 0) {
                glDeleteBuffers(1, &_shader);
            }
        }

        GLuint get() const { return _shader; }

    private:
        GLuint _shader{};
    };
}
#endif //GLISH3_UNIQUE_SHADER_HPP
