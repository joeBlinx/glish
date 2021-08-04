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
#include <cassert>
#include "texture_base.hpp"
#include <unordered_map>
namespace glish3{
    struct texture_view: texture_base{
        GLenum get_target() const override{return _target;}

        static texture_view
        create_view(texture_base const &origin, GLenum target, GLuint min_level, GLuint num_levels,
                    GLuint min_layer, GLuint num_layers);
    private:
        texture_view(glish3::UniqueTexture &&texture, GLenum target);
        GLenum _target;
        static std::unordered_map<GLuint, std::vector<GLuint>> const corresponding_types;

        static bool check_corresponding_type(GLuint base, GLuint target){
            auto const& compatibility_array = corresponding_types.at(base);

            return std::ranges::any_of(compatibility_array, [&](auto const& target_value){
                return target_value == target;
            });
        }
    };

}
#endif //GLISH3_TEXTURE_VIEW_HPP
