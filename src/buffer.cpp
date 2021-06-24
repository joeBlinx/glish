//
// Created by joe on 07/10/18.
//

#include "glish3/buffer.hpp"
#include "glish3/Vao.hpp"
namespace glish3{

	buffer::operator GLuint() {
		return _buffer.get();
	}

	buffer::operator bool() const {
		return (bool)_buffer.get();
	}
    void buffer::bind() const {
        glBindBuffer(target, _buffer.get());
    }
}