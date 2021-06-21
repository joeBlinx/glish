//
// Created by joe on 07/10/18.
//

#ifndef GLISH3_VBO_HPP
#define GLISH3_VBO_HPP

#include <glish3/gl_glew.hpp>
#include <initializer_list>

#include <type_traits>
#include <glish3/gl_memory/unique_vbo.hpp>

namespace glish3{

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
	class Vbo{

		UniqueVbo _vbo;
		GLenum target ;
	template<class T>
		void set(vbo_settings const & settings1)
		{
			glEnableVertexAttribArray(settings1.index);
			glVertexAttribPointer(settings1.index, settings1.size,
					GL_FLOAT, GL_FALSE, settings1.stride*sizeof(T) ,
					(void*)(settings1.begin*sizeof(T)));
		}
	public:

		template<class T, size_t N, class ...Settings>
				Vbo(GLenum target, T(&data) [N], Settings &&...sets)
		:target(target)
		{
			static_assert((std::is_same<Settings, vbo_settings>::value && ... && true), "Type must be settings");
			GLuint vbo;
			glGenBuffers(1, &vbo);
			_vbo = UniqueVbo(vbo);
			bind();
			glBufferData(target, N*sizeof(T),
							data, GL_STATIC_DRAW);
			(set<T>(sets),...);

		}
		template<class T, class ...Settings>
				Vbo(GLenum target, T * data, size_t size, Settings && ...sets):
				target(target)
		{
			static_assert((std::is_same<Settings, vbo_settings>::value && ... && true), "Type must be settings");
            GLuint vbo;
            glGenBuffers(1, &vbo);
            _vbo = UniqueVbo(vbo);
			bind();
			glBufferData(target, size*sizeof(T),
							data, GL_STATIC_DRAW);
			(set<T>(sets),...);
		}


		void bind();

		explicit operator GLuint();
		operator bool() const;

	};
}
#endif //GLISH3_VBO_HPP
