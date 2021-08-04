//
// Created by stiven.aigle on 21/07/20.
//
#include "glish3/texture/texture_view.hpp"
namespace glish3{
    std::unordered_map<GLuint, std::vector<GLuint>> const texture_view::corresponding_types{
            {GL_TEXTURE_1D, {GL_TEXTURE_1D, GL_TEXTURE_1D_ARRAY}},
            {GL_TEXTURE_2D, {GL_TEXTURE_2D, GL_TEXTURE_2D_ARRAY}},
            {GL_TEXTURE_3D, {GL_TEXTURE_3D}},
            {GL_TEXTURE_CUBE_MAP, {GL_TEXTURE_CUBE_MAP,
                                   GL_TEXTURE_2D,
                                   GL_TEXTURE_2D_ARRAY,
                                   GL_TEXTURE_CUBE_MAP_ARRAY}},
           {GL_TEXTURE_1D_ARRAY, {GL_TEXTURE_1D, GL_TEXTURE_1D_ARRAY}},
           {GL_TEXTURE_2D_ARRAY, {GL_TEXTURE_2D, GL_TEXTURE_2D_ARRAY}},
           {GL_TEXTURE_CUBE_MAP_ARRAY, {GL_TEXTURE_CUBE_MAP,
                                  GL_TEXTURE_2D,
                                  GL_TEXTURE_2D_ARRAY,
                                  GL_TEXTURE_CUBE_MAP_ARRAY}},
          {GL_TEXTURE_2D_MULTISAMPLE, {GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_2D_MULTISAMPLE_ARRAY}},
          {GL_TEXTURE_2D_MULTISAMPLE_ARRAY, {GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_2D_MULTISAMPLE_ARRAY}},
    };
    texture_view
    texture_view::create_view(texture_base const &origin, GLenum target, GLuint min_level, GLuint num_levels,
                              GLuint min_layer, GLuint num_layers) {
        GLuint texture{};
        glGenTextures(1, &texture);
        assert(check_corresponding_type(origin.get_target(), target) && "Type of view are not compatible");
        glTextureView(texture, target, origin.get(),
                      GL_RGBA8,
                      min_level,
                      num_levels,
                      min_layer,
                      num_layers);

        return {texture, target};
    }

    texture_view::texture_view(glish3::UniqueTexture &&texture, GLenum target):
    texture_base(std::move(texture)),
    _target(target)
    {

    }
}