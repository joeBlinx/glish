//
// Created by stiven on 22/06/2021.
//

#ifndef GLISH3_UNIQUE_TEXTURE_HPP
#define GLISH3_UNIQUE_TEXTURE_HPP
#include "glish3/gl_glew.hpp"
namespace glish3 {
    struct UniqueTexture {
        UniqueTexture() = default;
        UniqueTexture(GLuint id) noexcept: _id(id) {}

        UniqueTexture(UniqueTexture const &) = delete;
        UniqueTexture &operator=(UniqueTexture const &) = delete;

        UniqueTexture(UniqueTexture &&old)noexcept : _id(old._id) { old._id = 0; }
        UniqueTexture &operator=(UniqueTexture &&old) noexcept {
            _id = old._id;
            old._id = 0;
            return *this;
        }

        ~UniqueTexture() {
            if (_id != 0) {
                glDeleteTextures(1, &_id);
            }
        }
        GLuint get() const{ return _id;}

    private:
        GLuint _id{};
    };
    inline UniqueTexture make_unique_texture(GLenum target){
        GLuint texture;
        glCreateTextures(target, 1, &texture);
        return {texture};
    }
}
#endif //GLISH3_UNIQUE_TEXTURE_HPP
