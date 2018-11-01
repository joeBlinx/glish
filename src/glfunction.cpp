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
		glishError("glGetShader");
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
	void attachShader(GLuint programId, GLuint shader, PARAM){
		glAttachShader(programId, shader);
		glishError("glAttachShader");
	}
	void detachShader(GLuint programId, GLuint shader, PARAM){
		glDetachShader(programId, shader);
		glishError("glDetachShader");
	}
	GLuint createProgram(PARAM){
		GLuint res = glCreateProgram();
		glishError("glCreateProgram");
		return res;
	}

	void linkProgram(GLuint programId, PARAM){
		glLinkProgram(programId);
		glishError("glLinkProgram");
	}
	void getProgramiv(GLuint shader, GLenum pname, GLint* param, PARAM){
		glGetProgramiv(shader, pname, param);
		glishError("glGetProgram");
	}
	void getProgramInfoLog(GLuint shader, GLsizei bufsize,
						  GLsizei* length, GLchar* infoLog, PARAM){
		glGetProgramInfoLog(shader, bufsize, length, infoLog);
		glishError("glGetShaderInfoLog");
	}
	GLint getUniformLocation(GLuint program, char const * name, PARAM){
		GLint uni = glGetUniformLocation(program, name);
		glishError("glGetUniformLocation");
		return uni;

	}

	void deleteBuffer(GLsizei n, GLuint *vbo, PARAM) {
		glDeleteBuffers(n, vbo);
		glishError("glDeleteBuffers");
	}

    void genVertexArrays(GLsizei n, GLuint *vao, PARAM){
	    glGenVertexArrays(n, vao);
        glishError("glGenVertexArrays");
    }

    void bindVertexArray(GLuint vao, PARAM){
        glBindVertexArray(vao);
        glishError("glBindVertexArray");
	}

    void deleteVertexArrays(GLsizei n, GLuint *vao, PARAM){
        glDeleteVertexArrays(n, vao);
        glishError("glDeleteVertexArrays");

    }

    void bindBuffer(GLenum target, GLuint vbo, PARAM) {
		glBindBuffer(target, vbo);
		glishError("glBindBuffer");
	}

	void genBuffers(GLsizei n, GLuint *vbo, PARAM) {
		glGenBuffers(n, vbo);
		glishError("glGenBuffers");
	}

	void bufferData(GLenum target, GLsizeiptr size, const void *data, GLenum usage, PARAM) {
		glBufferData(target, size, data, usage);
		glishError("glBufferData");
	}

	void enableVertexAttribArray(GLuint index, PARAM) {
		glEnableVertexAttribArray(index);
		glishError("glEnableVertexAttribArray");
	}

	void vertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride,
									 const void *pointer, PARAM) {
		glVertexAttribPointer(index, size, type, normalized, stride, pointer);
		glishError("glVertexAttribPointer");
	}

	void uniform1fv(GLint location,  GLsizei count,  const GLfloat *value, PARAM){
		glUniform1fv(location, count, value);
		glishError("glUniform");
	}
	void uniform2fv(GLint location,  GLsizei count,  const GLfloat *value, PARAM){
		glUniform2fv(location, count, value);
		glishError("glUniform");
	}
	void uniform3fv(GLint location,  GLsizei count,  const GLfloat *value, PARAM){
		glUniform3fv(location, count, value);
		glishError("glUniform");
	}
	void uniform4fv(GLint location,  GLsizei count,  const GLfloat *value, PARAM){
		glUniform4fv(location, count, value);
		glishError("glUniform");
	}
	void uniform1iv(GLint location,  GLsizei count,  const GLint *value, PARAM){
		glUniform1iv(location, count, value);
		glishError("glUniform");
	}
	void uniform2iv(GLint location,  GLsizei count,  const GLint *value, PARAM){
		glUniform2iv(location, count, value);
		glishError("glUniform");
	}
	void uniform3iv(GLint location,  GLsizei count,  const GLint *value, PARAM){
		glUniform3iv(location, count, value);
		glishError("glUniform");
	}
	void uniform4iv(GLint location,  GLsizei count,  const GLint *value, PARAM){
		glUniform4iv(location, count, value);
		glishError("glUniform");
	}

}
