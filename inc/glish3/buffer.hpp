//
// Created by joe on 07/10/18.
//

#ifndef GLISH3_BUFFER_HPP
#define GLISH3_BUFFER_HPP

#include <glish3/gl_glew.hpp>
#include <initializer_list>

#include <type_traits>
#include <glish3/gl_memory/unique_buffer.hpp>


namespace glish3{
    class Vao;
	struct vbo_settings
	{
		unsigned size;
		unsigned index = 0;
		unsigned stride = 0;
		unsigned begin = 0;
		vbo_settings(unsigned size, unsigned index = 0, unsigned stride = 0, unsigned begin = 0):
		size(size),
		index(index),
		stride(stride),
		begin(begin)
		{
		}
	};
	class buffer{
        friend class Vao;
		UniqueBuffer _buffer;
		GLenum target ;
        std::size_t _size_of_data{};

	public:

		template<class T, size_t N>
				buffer(GLenum target, T(&data) [N])
		:_buffer(make_unique_buffer()), target(target), _size_of_data(sizeof(T))
		{
			glNamedBufferData(_buffer.get(), N * sizeof(T),
                              data, GL_STATIC_DRAW);

		}
		template<class T>
				buffer(GLenum target, T * data, size_t size):
				_buffer(make_unique_buffer()),
				target(target), _size_of_data(sizeof(T))
		{
            glNamedBufferData(_buffer.get(), size * sizeof(T),
                              data, GL_STATIC_DRAW);
		}
        void bind()const;
		explicit operator GLuint();
		operator bool() const;

	};
}
#endif //GLISH3_BUFFER_HPP
