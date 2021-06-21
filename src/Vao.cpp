//
// Created by stiven on 10/19/18.
//

#include <glish3/Vao.hpp>

namespace glish3 {
    Vao::Vao() {
        GLuint vao;
        glGenVertexArrays(1, &vao);
        _vao = UniqueVao(vao);
    }


    void Vao::bind() {
        glBindVertexArray(_vao.get());
    }

    Vao::operator bool() const {
        return (bool)_vao.get();
    }

    Vao::operator GLuint() {
        return _vao.get();
    }



	void Vao::addVbo(Vbo &&vbo) {
        bind();
        _vbos.push_back(std::move(vbo));
	}

}