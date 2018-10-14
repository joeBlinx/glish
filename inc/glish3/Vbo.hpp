//
// Created by joe on 07/10/18.
//

#ifndef GLISH3_VBO_HPP
#define GLISH3_VBO_HPP

#include <glish3/gl_glew.hpp>
#include <type_traits>
namespace glish3{

	class Vbo{

		GLuint vbo = 0;
		GLenum target ;

	public:

		Vbo(Vbo const &) = delete;
		Vbo& operator=(Vbo const &) = delete;

		Vbo(Vbo && oldVbo);
		Vbo& operator= (Vbo && oldVbo);

		void bind();

		explicit operator GLuint();
		operator bool() const;
		~Vbo();
	};
}
#endif //GLISH3_VBO_HPP
