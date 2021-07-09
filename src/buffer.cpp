//
// Created by joe on 07/10/18.
//

#include "glish3/buffer.hpp"
namespace glish3{

	buffer::operator GLuint() {
		return _buffer.get();
	}

	buffer::operator bool() const {
		return (bool)_buffer.get();
	}
    void buffer::bind(GLenum target) const {
        glBindBuffer(target, _buffer.get());
    }
    void buffer::allocate(std::size_t size, GLbitfield flags) const{
        glNamedBufferStorage(_buffer, size, nullptr, flags);
    }

    void buffer::bind_base(GLenum target, GLuint index) const {
        glBindBufferBase(target, index, _buffer);
    }


}