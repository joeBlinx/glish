//
// Created by joe on 23/09/18.
//

#ifndef GLISH3_ERRORHANLDER_HPP
#define GLISH3_ERRORHANLDER_HPP

#include <GL/glew.h>



namespace glish3{
#define PARAM const char* file, int line
	void clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha, PARAM);
	void enable(GLenum cap, PARAM);
	void blendFunc(GLenum sfactor, GLenum dfactor, PARAM);


}
#define FILE_LINE __FILE__, __LINE__
// macro to have the file and the line in the log file
#define glishClearColor(r, g, b, a) glish3::clearColor(r, g, b, a, FILE_LINE)
#define glishEnable(cap) glish3::enable(cap, FILE_LINE)
#define glishBlendFunc(sfactor, dfactor) glish3::blendFunc(sfactor, dfactor, FILE_LINE)

#endif //GLISH3_ERRORHANLDER_HPP