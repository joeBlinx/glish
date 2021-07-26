//
// Created by stiven.aigle on 21/07/20.
//

#ifndef GLISH3_TEXTURE_VIEW_HPP
#define GLISH3_TEXTURE_VIEW_HPP

#include <GL/glew.h>
#include <glish3/gl_memory/unique_texture.hpp>
#include <unordered_map>
#include <vector>
#include <array>
#include <algorithm>

namespace glish3{
    struct texture_view{
        template<class Texture>
        texture_view(Texture const& texture_base, GLuint target);
    private:
        static GLuint constexpr corresponding_types[][5]{
            {GL_TEXTURE_1D, GL_TEXTURE_1D, GL_TEXTURE_1D_ARRAY, 0, 0},
            {GL_TEXTURE_2D, GL_TEXTURE_2D, GL_TEXTURE_2D_ARRAY, 0, 0},
            {GL_TEXTURE_3D, GL_TEXTURE_3D, 0, 0, 0},
            {GL_TEXTURE_CUBE_MAP, GL_TEXTURE_CUBE_MAP,
                                   GL_TEXTURE_2D,
                                   GL_TEXTURE_2D_ARRAY,
                                   GL_TEXTURE_CUBE_MAP_ARRAY},
           {GL_TEXTURE_1D_ARRAY, GL_TEXTURE_1D, GL_TEXTURE_1D_ARRAY, 0, 0},
           {GL_TEXTURE_2D_ARRAY, GL_TEXTURE_2D, GL_TEXTURE_2D_ARRAY, 0, 0},
           {GL_TEXTURE_CUBE_MAP_ARRAY, GL_TEXTURE_CUBE_MAP,
                                        GL_TEXTURE_2D,
                                        GL_TEXTURE_2D_ARRAY,
                                        GL_TEXTURE_CUBE_MAP_ARRAY},
            {GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_2D_MULTISAMPLE_ARRAY, 0, 0},
            {GL_TEXTURE_2D_MULTISAMPLE_ARRAY, GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_2D_MULTISAMPLE_ARRAY, 0, 0}
        };
        UniqueTexture _texture_id;
        static constexpr bool check_correspdonding_type(GLuint base, GLuint target){
            auto const compatibility_array_it = std::ranges::find_if(corresponding_types, [&](auto const& array){
                return array[0] == base;
            });

            return std::ranges::any_of(*compatibility_array_it, [&](auto const& target_value){
                return target_value == target;
            });
        }
    };


    template<class Texture>
            texture_view::texture_view(Texture const& texture_base, GLuint target){
        static_assert(check_correspdonding_type(Texture::target, target),
                "The base texture type and the target texture type are not compatible");
        {
            GLuint texture_id;
            glGenTextures(1, &texture_id);
            _texture_id = UniqueTexture(texture_id);
        }

    }
}
#endif //GLISH3_TEXTURE_VIEW_HPP
