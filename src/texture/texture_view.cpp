//
// Created by stiven.aigle on 21/07/20.
//
#include "glish3/texture/texture_view.hpp"
namespace glish3{
    std::unordered_map<GLuint, std::vector<GLuint>> const corresponding_types{
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
}