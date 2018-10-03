//
// Created by joe on 23/09/18.
//

#include <glish3/glfunction.hpp>
#include <glish3/log/errorHandler.hpp>

namespace glish3{
#define glishError(function) getError(function, file, std::to_string(line))
	void clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha, PARAM) {
		glClearColor(red, green, blue, alpha);
		glishError("glClearColor");
	}

	void enable(GLenum cap, PARAM) {
		glEnable(cap);
		glishError("glEnable");

	}

	void blendFunc(GLenum sfactor, GLenum dfactor, PARAM) {
		glBlendFunc(sfactor, dfactor);
		glishError("glBlendFunc");

	}
	void clear(GLbitfield mask, PARAM){
		glClear(mask);
		glishError("glClear");
	}
	void deleteProgram(GLuint program, PARAM){

		glDeleteProgram(program);
		glishError("glDeleteProgram");
	}
	void useProgram(GLuint program, PARAM){
		glUseProgram(program);
		glishError("glUseProgram");
	}
	GLuint createShader(GLenum type, PARAM){
		GLuint shader = glCreateShader(type);
		glishError("glCreateShader");
		return shader;
	}
	void compileShader(GLuint shaderId, PARAM){
		glCompileShader(shaderId);
		glishError("glCompileShader");
	}
	void shaderSource(GLuint shader, GLsizei count,
					  const GLchar** string, const GLint *length,
						PARAM){
		glShaderSource(shader, count, string, length);
		glishError("glShaderSource");
	}
	void getShaderiv(GLuint shader, GLenum pname, GLint* param, PARAM){
		glGetShaderiv(shader, pname, param);
		glishError("glGetShaderiv");
	}
	void getShaderInfoLog(GLuint shader, GLsizei bufsize,
			GLsizei* length, GLchar* infoLog, PARAM){
		glGetShaderInfoLog(shader, bufsize, length, infoLog);
		glishError("glGetShaderInfoLog");
	}

	void deleteShader(GLuint shader, PARAM){
		glDeleteShader(shader);
		glishError("glDeleteShader");
	}
}
