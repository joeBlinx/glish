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
	void clear(GLbitfield mask, PARAM);
	void deleteProgram(GLuint program, PARAM);
	void useProgram(GLuint program, PARAM);
	GLuint createShader(GLenum type, PARAM);
	void compileShader(GLuint shaderId, PARAM);
	void shaderSource(GLuint shader, GLsizei count,
					  const GLchar** string, const GLint *length,
					  PARAM);
	void getShaderiv(GLuint shader, GLenum pname, GLint* param, PARAM);
	void getShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei* length, GLchar* infoLog, PARAM);
	void deleteShader(GLuint shader, PARAM);
	void attachShader(GLuint programId, GLuint shader, PARAM);
	void detachShader(GLuint programId, GLuint shader, PARAM);
	GLuint createProgram(PARAM);
	void linkProgram(GLuint programId, PARAM);
	void getProgramiv(GLuint programId, GLenum pname, GLint* param, PARAM);
	void getProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infoLog, PARAM);

}
#define FILE_LINE __FILE__, __LINE__
// macro to have the file and the line in the logTest file
#define glishClearColor(r, g, b, a) glish3::clearColor(r, g, b, a, FILE_LINE)
#define glishEnable(cap) glish3::enable(cap, FILE_LINE)
#define glishBlendFunc(sfactor, dfactor) glish3::blendFunc(sfactor, dfactor, FILE_LINE)
#define glishClear(mask) glish3::clear(mask, FILE_LINE)
#define glishDeleteProgram(program) glish3::deleteProgram(program, FILE_LINE)
#define glishUseProgram(program) glish3::useProgram(program, FILE_LINE)
#define glishCreateShader(type) glish3::createShader(type, FILE_LINE)
#define glishCompileShader(shaderId) glish3::compileShader(shaderId, FILE_LINE)
#define glishShadersource(shader, count, string, length) glish3::shaderSource(shader, count, string, length, FILE_LINE)
#define glishGetShaderiv(shader, pname, param) glish3::getShaderiv(shader, pname, param, FILE_LINE)
#define glishGetShaderInfoLog(shader, bufsize, length, infoLog) glish3::getShaderInfoLog(shader, bufsize, length, infoLog, FILE_LINE)
#define glishDeleteShader(shader) glish3::deleteShader(shader, FILE_LINE);
#define glishAttachShader(programId, shader) glish3::attachShader(programId, shader, FILE_LINE)
#define glishDetachShader(programId, shader) glish3::detachShader(programId, shader, FILE_LINE)
#define glishCreateProgram() glish3::createProgram(FILE_LINE)
#define glishLinkProgram(programId) glish3::linkProgram(programId, FILE_LINE)
#define glishGetProgramiv(programId, pname, param) glish3::getProgramiv(programId, pname, param, FILE_LINE)
#define glishGetProgramInfoLog(programId, bufsize, length, infoLog) glish3::getProgramInfoLog(programId, bufsize, length, infoLog, FILE_LINE)
#endif //GLISH3_ERRORHANLDER_HPP