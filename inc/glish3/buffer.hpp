//
// Created by joe on 07/10/18.
//

#ifndef GLISH3_BUFFER_HPP
#define GLISH3_BUFFER_HPP

#include <GL/glew.h>
#include <cstddef>

#include "glish3/gl_memory/unique_buffer.hpp"
#include <limits>

namespace glish3{
	class buffer{
        friend class Vao;
		UniqueBuffer _buffer;
        std::size_t _size_of_data = std::numeric_limits<std::size_t>::max();

	public:
        buffer():_buffer(make_unique_buffer()){}

        template<class T, size_t N>
        void allocate(T(&data)[N], GLbitfield flags) {
            _size_of_data = sizeof(T);
            glNamedBufferStorage(_buffer, N*_size_of_data, data, flags);
        }

        template<class T>
        void allocate(T const* data, size_t size, GLbitfield flags) {
            _size_of_data = sizeof(T);
            glNamedBufferStorage(_buffer, size*_size_of_data, data, flags);
        }

        template<class T>
        requires
        requires (T a){ a.size(); a.size_type; a.data();}
        void allocate(T const& data, GLbitfield flags)
        {
            _size_of_data = data.size_type;
            glNamedBufferStorage(_buffer, data.size() * _size_of_data, data.data(), flags);
        }
        void allocate(std::size_t size, GLbitfield flags) const;

		template<class T, size_t N>
				buffer(T(&data) [N])
		:_buffer(make_unique_buffer()), _size_of_data(sizeof(T))
		{
           allocate(data, 0);
		}
		template<class T>
				buffer(T * data, size_t size):
				_buffer(make_unique_buffer()), _size_of_data(sizeof(T))
		{
            allocate(data, size, 0);
		}

        void bind(GLenum target) const;
		void bind_base(GLenum target, GLuint index) const;
		template<class T>
        void sub_data(std::size_t offset, std::size_t number_of_element, const T *data) const{
		            glNamedBufferSubData(_buffer, offset, number_of_element*sizeof(T), data);
		        }
		explicit operator GLuint();
		operator bool() const;

	};
}
#endif //GLISH3_BUFFER_HPP
