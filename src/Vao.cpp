//
// Created by stiven on 10/19/18.
//

#include <glish3/Vao.hpp>
#include <glish3/glfunction.hpp>

namespace glish3 {
    Vao::Vao() {
        glishGenVertexArrays(1, &vao);
        bind();
    }

    Vao::Vao(Vao &&vao):vao(vao.vao), _vbos(std::move(vao._vbos)) {
        vao.vao = 0;
    }

    Vao &Vao::operator=(Vao &&vao) {
        this->vao = vao.vao;
        vao.vao = 0;
        _vbos = std::move(vao._vbos);
        return *this;
    }

    void Vao::bind() {
        glishBindVertexArray(vao);
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
            vao = 0;
        }
    }

	void Vao::addVbo(Vbo &&vbo) {
        bind();
        _vbos.push_back(std::move(vbo));
	}

}