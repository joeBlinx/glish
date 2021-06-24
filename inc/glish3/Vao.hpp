//
// Created by stiven on 10/16/18.
//

#ifndef GLISH3_VAP_H
#define GLISH3_VAP_H

#include <glish3/gl_glew.hpp>
#include <vector>
#include <glish3/Vbo.hpp>
#include "glish3/gl_memory/unique_vao.hpp"

namespace glish3{
    struct attrib_settings
    {
        unsigned size;
        unsigned index = 0;
        unsigned stride = 0;
        unsigned offset = 0;
        attrib_settings(unsigned size, unsigned index = 0, unsigned stride = 0, unsigned offset = 0):
                size(size),
                index(index),
                stride(stride),
                offset(offset)
        {
        }
    };
    class Vao{
        UniqueVao _vao;
        std::vector<Vbo> _vbos;

        void set_attrib(const Vbo &vbo, const attrib_settings &settings);
    public:
        Vao();

        void bind();

        template<class ...Settings>
        void add_vbo (Vbo && vbo, Settings&& ... settings)
        requires (std::is_same_v<Settings, attrib_settings> && ...){
            _vbos.push_back(std::move(vbo));
            (set_attrib(_vbos.back(), settings), ...);
        }

        operator bool() const;

        operator GLuint();

    };
}
#endif //GLISH3_VAP_H
