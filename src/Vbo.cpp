//
// Created by joe on 07/10/18.
//

#include <glish3/Vbo.hpp>
#include <glish3/glfunction.hpp>
#include <utility>

namespace glish3{

	Vbo::operator GLuint() {
		return vbo;
	}

	Vbo::~Vbo() {
		if(!vbo){
			glishDeleteBuffer(1, &vbo);
		}
	}

	Vbo::Vbo(Vbo &&oldVbo) {
		*this = std::move(oldVbo);
	}

	Vbo &Vbo::operator=(Vbo &&oldVbo) {
		vbo = oldVbo.vbo;
		target = oldVbo.target;
		oldVbo.vbo = 0;
		return *this;
	}

	Vbo::operator bool() const {
		return (bool)vbo;
	}

	void Vbo::bind() {
		glishBindBuffer(target, vbo);
	}
}