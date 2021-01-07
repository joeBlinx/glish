//
// Created by stiven on 10/16/18.
//

#ifndef GLISH3_VAP_H
#define GLISH3_VAP_H

#include <glish3/gl_glew.hpp>
#include <vector>
#include <glish3/Vbo.hpp>

namespace glish3{

    class Vao{
        GLuint vao = 0;
        std::vector<Vbo> _vbos;


    public:
        Vao();
        Vao(Vao const &) = delete;
        Vao& operator=(Vao const &) = delete;

        Vao(Vao && vao);
        Vao&operator=(Vao && vao);

        void bind();
        void addVbo (Vbo && vbo);
        operator bool() const;
        operator GLuint();
        ~Vao();
    };
}
#endif //GLISH3_VAP_H
