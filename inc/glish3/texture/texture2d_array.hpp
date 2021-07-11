//
// Created by stiven_perso on 11/07/2021.
//

#ifndef GLISH3_TEXTURE2D_ARRAY_H
#define GLISH3_TEXTURE2D_ARRAY_H
#include <GL/glew.h>
#include "glish3/gl_memory/unique_texture.hpp"
#include <memory>
#include <cstring>
#include <array>
#include <span>
namespace glish3{

    struct texture2d_array{
        struct settings{
            int width, height;
            int number_images;
            std::unique_ptr<std::byte> data;
        };

        texture2d_array(settings const& settings);
        void bind(int binding_point) const;
        static settings read_images(std::span<std::string_view> image_paths);
    private:
        UniqueTexture _texture_unit{make_unique_texture(GL_TEXTURE_2D_ARRAY)};
    };

}
#endif //GLISH3_TEXTURE2D_ARRAY_H
