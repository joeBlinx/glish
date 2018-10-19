//
// Created by stiven on 10/19/18.
//

#include <glish3/Vao.hpp>

namespace glish3 {
    Vao::Vao() {
        glGenVertexArrays();
    }

    Vao::Vao(Vao &&vao):vao(vao.vao) {
        vao.vao = 0;
    }

    Vao &Vao::operator=(Vao &&vao) {
        this->vao = vao.vao;
        vao.vao = 0;
        return *this;
    }

    Vao::operator bool() const {
        return (bool)vao;
    }

    Vao::operator GLuint() {
        return vao;
    }

    Vao::~Vao() {
        if(vao){

        }
    }

}