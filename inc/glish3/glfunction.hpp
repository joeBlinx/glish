//
// Created by joe on 23/09/18.
//

#ifndef GLISH3_ERRORHANLDER_HPP
#define GLISH3_ERRORHANLDER_HPP

#include <GL/glew.h>

namespace glish3{

	void clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
	void enable(GLenum cap);
	void blendFunc(GLenum sfactor, GLenum dfactor);
}
#endif //GLISH3_ERRORHANLDER_HPP
