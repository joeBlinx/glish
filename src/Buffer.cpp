//
// Created by joe on 07/10/18.
//

#include "glish3/Buffer.hpp"
#include "glish3/Vao.hpp"
namespace glish3{

	Buffer::operator GLuint() {
		return _buffer.get();
	}

	Buffer::operator bool() const {
		return (bool)_buffer.get();
	}
    void Buffer::bind() const {
        glBindBuffer(target, _buffer.get());
    }
}