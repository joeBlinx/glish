//
// Created by joe on 07/10/18.
//

#include "glish3/Vbo.hpp"

namespace glish3{

	Vbo::operator GLuint() {
		return _vbo.get();
	}

	Vbo::operator bool() const {
		return (bool)_vbo.get();
	}

	void Vbo::bind() {
		glBindBuffer(target, _vbo.get());
	}
}