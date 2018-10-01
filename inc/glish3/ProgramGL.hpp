//
// Created by joe on 01/10/18.
//

#ifndef GLISH3_PROGRAMGL_HPP
#define GLISH3_PROGRAMGL_HPP

#include <GL/gl.h>

namespace glish3{
	class ProgramGL{

		GLuint program;

	public:
		ProgramGL(ProgramGL const &) = delete;
		ProgramGL& operator=(ProgramGL const &) = delete;

		ProgramGL(ProgramGL && programGL);
		ProgramGL& operator=(ProgramGL && programGL);

		void use();

		~ProgramGL();

	};
}
#endif //GLISH3_PROGRAMGL_HPP
