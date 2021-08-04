//
// Created by stiven on 03/08/2021.
//

#ifndef GLISH3_TEXTURE_BASE_HPP
#define GLISH3_TEXTURE_BASE_HPP
#include <memory>
namespace glish3 {
    struct texture_base{
        texture_base() = default;
        texture_base(glish3::UniqueTexture&& texture_id):
                                _texture_id(std::move(texture_id)){}
        GLuint get() const{ return _texture_id.get(); }

        virtual GLenum get_target() const = 0;
        void bind(int binding_point) const { glBindTextureUnit(binding_point, _texture_id.get());};
        virtual ~texture_base() = default;
    protected:
        glish3::UniqueTexture _texture_id{};
    };
}

#endif //GLISH3_TEXTURE_BASE_HPP
