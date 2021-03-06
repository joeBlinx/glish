//
// Created by stiven_perso on 11/07/2021.
//

#ifndef GLISH3_TEXTURE2D_ARRAY_H
#define GLISH3_TEXTURE2D_ARRAY_H
#include <GL/glew.h>
#include "glish3/gl_memory/unique_texture.hpp"
#include "texture_base.hpp"
#include <memory>
#include <cstring>
#include <array>
#include <span>
#include <string_view>
#include <cstddef>
namespace glish3{

    struct texture2d_array: texture_base{
        struct settings{
            int width, height;
            int number_images;
            std::unique_ptr<std::byte> data;
        };
        static GLenum constexpr target = GL_TEXTURE_2D_ARRAY;
        texture2d_array(settings const& settings);
        static settings read_images(std::span<std::string_view> image_paths);
        GLenum get_target() const override{return target;}
    };

}
#endif //GLISH3_TEXTURE2D_ARRAY_H
