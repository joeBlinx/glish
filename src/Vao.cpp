//
// Created by stiven on 10/19/18.
//

#include <glish3/Vao.hpp>
#include <glish3/glfunction.hpp>

namespace glish3 {
    Vao::Vao() {
        glishGenVertexArrays(1, &vao);
    }

    Vao::Vao(Vao &&vao):vao(vao.vao) {
        vao.vao = 0;
    }

    Vao &Vao::operator=(Vao &&vao) {
        this->vao = vao.vao;
        vao.vao = 0;
        return *this;
    }

    void Vao::bind() {

    }

    Vao::operator bool() const {
        return (bool)vao;
    }

    Vao::operator GLuint() {
        return vao;
    }

    Vao::~Vao() {
        if(vao){
            glishDeleteVertexArrays(1, &vao);
        }
    }

}