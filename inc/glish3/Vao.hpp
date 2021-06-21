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

    class Vao{
        UniqueVao _vao;
        std::vector<Vbo> _vbos;

    public:
        Vao();

        void bind();
        void addVbo (Vbo && vbo);
        operator bool() const;
        operator GLuint();

    };
}
#endif //GLISH3_VAP_H
