//
// Created by joe on 23/09/18.
//

#ifndef GLISH3_ERRORHANLDER_HPP
#define GLISH3_ERRORHANLDER_HPP

#include <GL/glew.h>



namespace glish3{

	void clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha, const char *file, int line);
	void enable(GLenum cap);
	void blendFunc(GLenum sfactor, GLenum dfactor);

}
#define glishClearColor(r, g, b, a) glish3::clearColor(r, g, b, a, __FILE__, __LINE__)

#endif //GLISH3_ERRORHANLDER_HPP
