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

	//PROGRAM
	void deleteProgram(GLuint program, PARAM);
	void useProgram(GLuint program, PARAM);

	//SHADER
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
	GLint getUniformLocation(GLuint program, char const * name, PARAM);

	//VAO
	void genVertexArrays(GLsizei n, GLuint *vao, PARAM);
	void bindVertexArray(GLuint vao, PARAM);
	void deleteVertexArrays(GLsizei n, GLuint *vao, PARAM);

	//BUFFER
	void genBuffers(GLsizei n, GLuint * vbo, PARAM);
	void bindBuffer(GLenum target, GLuint vbo, PARAM);
	void bufferData(GLenum target, GLsizeiptr size, const void* data, GLenum usage,
			PARAM);
	void enableVertexAttribArray(GLuint index, PARAM);
	void vertexAttribPointer(GLuint index, GLint size,
			GLenum type, GLboolean normalized,
			GLsizei stride,
			const void * pointer, PARAM);
	void deleteBuffer(GLsizei n, GLuint * vbo, PARAM);
	void uniform1fv(GLint location,  GLsizei count,  const GLfloat *value, PARAM);
	void uniform2fv(GLint location,  GLsizei count,  const GLfloat *value, PARAM);
	void uniform3fv(GLint location,  GLsizei count,  const GLfloat *value, PARAM);
	void uniform4fv(GLint location,  GLsizei count,  const GLfloat *value, PARAM);
	void uniform1iv(GLint location,  GLsizei count,  const GLint *value, PARAM);
	void uniform2iv(GLint location,  GLsizei count,  const GLint *value, PARAM);
	void uniform3iv(GLint location,  GLsizei count,  const GLint *value, PARAM);
	void uniform4iv(GLint location,  GLsizei count,  const GLint *value, PARAM);

	void drawArrays(GLenum mode, GLint first, GLsizei count, PARAM);

	//TEXTURES
	void genTextures(GLsizei n, GLuint * ids, PARAM);
	void bindTextures(GLenum target , GLuint id, PARAM);

	void texImage2D(	GLenum target,
						  GLint level,
						  GLint internalFormat,
						  GLsizei width,
						  GLsizei height,
						  GLint border,
						  GLenum format,
						  GLenum type,
						  const GLvoid * data, PARAM);
	void activeTexture(GLenum texture, PARAM);
	void deleteTexture(GLsizei count, GLuint *ids, PARAM);


}
#define FILE_LINE __FILE__, __LINE__
// macro to have the file and the line in the logTest file
#define glishClearColor(r, g, b, a) glish3::clearColor(r, g, b, a, FILE_LINE)
#define glishEnable(cap) glish3::enable(cap, FILE_LINE)
#define glishBlendFunc(sfactor, dfactor) glish3::blendFunc(sfactor, dfactor, FILE_LINE)
#define glishClear(mask) glish3::clear(mask, FILE_LINE)
//PROGRAM
#define glishDeleteProgram(program) glish3::deleteProgram(program, FILE_LINE)
#define glishUseProgram(program) glish3::useProgram(program, FILE_LINE)
#define glishAttachShader(programId, shader) glish3::attachShader(programId, shader, FILE_LINE)
#define glishDetachShader(programId, shader) glish3::detachShader(programId, shader, FILE_LINE)
#define glishCreateProgram() glish3::createProgram(FILE_LINE)
#define glishLinkProgram(programId) glish3::linkProgram(programId, FILE_LINE)
#define glishGetProgramiv(programId, pname, param) glish3::getProgramiv(programId, pname, param, FILE_LINE)
#define glishGetProgramInfoLog(programId, bufsize, length, infoLog) glish3::getProgramInfoLog(programId, bufsize, length, infoLog, FILE_LINE)
//SHADER
#define glishCreateShader(type) glish3::createShader(type, FILE_LINE)
#define glishCompileShader(shaderId) glish3::compileShader(shaderId, FILE_LINE)
#define glishShadersource(shader, count, string, length) glish3::shaderSource(shader, count, string, length, FILE_LINE)
#define glishGetShaderiv(shader, pname, param) glish3::getShaderiv(shader, pname, param, FILE_LINE)
#define glishGetShaderInfoLog(shader, bufsize, length, infoLog) glish3::getShaderInfoLog(shader, bufsize, length, infoLog, FILE_LINE)
#define glishDeleteShader(shader) glish3::deleteShader(shader, FILE_LINE)

//UNIFORM
#define glishGetUniformLocation(program, name) glish3::getUniformLocation(program, name, FILE_LINE)


//VAO
#define glishGenVertexArrays(n, vao) glish3::genVertexArrays(n, vao, FILE_LINE)
#define glishBindVertexArray glish3::bindVertexArray(vao, FILE_LINE);

#define glishDeleteVertexArrays(n, vao) glish3::deleteVertexArrays(n, vao, FILE_LINE)

//BUFFERS
#define glishGenBuffers(n, p_vbo) glish3::genBuffers(n, p_vbo, FILE_LINE)
#define glishBindBuffer(target, vbo) 	glish3::bindBuffer(target, vbo, FILE_LINE)
#define glishBufferData(target, size, pdata, usage) \
				glish3::bufferData(target, size, pdata, usage, FILE_LINE)
#define glishEnableVertexAttribArray(index) glish3::enableVertexAttribArray(index, FILE_LINE)
#define glishVertexAttribPointer(index, size, \
						  type, normalized, \
						  stride, \
						 pointer) glish3::vertexAttribPointer(index, size, type, normalized,\
						 		stride, pointer, FILE_LINE)


#define glishDeleteBuffer(n, pVbo) glish3::deleteBuffer(n, pVbo, FILE_LINE)
#define glishUniform1fv(location, count, pvalue) glish3::uniform1fv(location, count,  pvalue, FILE_LINE)
#define glishUniform2fv(location, count, pvalue) glish3::uniform2fv(location, count,  pvalue, FILE_LINE)
#define glishUniform3fv(location, count, pvalue) glish3::uniform3fv(location, count,  pvalue, FILE_LINE)
#define glishUniform4fv(location, count, pvalue) glish3::uniform4fv(location, count,  pvalue, FILE_LINE)
#define glishUniform1iv(location, count, pvalue) glish3::uniform1iv(location, count,  pvalue, FILE_LINE)
#define glishUniform2iv(location, count, pvalue) glish3::uniform2iv(location, count,  pvalue, FILE_LINE)
#define glishUniform3iv(location, count, pvalue) glish3::uniform3iv(location, count,  pvalue, FILE_LINE)
#define glishUniform4iv(location, count, pvalue) glish3::uniform4iv(location, count,  pvalue, FILE_LINE)


//TEXTURE
#define glishGenTextures(n, pids)  glish3::genTextures(n, pids, FILE_LINE)
#define glishBindTextures(target, id) glish3::bindTextures(target, id, FILE_LINE)

#define glishTexImage2D(	target, \
					  level,\
					  internalFormat,\
					  width,\
					  height,\
					  border,\
					  format,\
					  type,\
					  pdata) glish3::texImage2D(target,\
									level,\
									internalFormat, \
									width, \
									height, \
									border, \
									format, \
									type, \
									pdata, FILE_LINE)

#define glishActiveTexture(texture) glish3::activeTexture(texture, FILE_LINE)
#define glishDeleteTextures(count, pid) glish3::deleteTexture(count, pid, FILE_LINE)

#define glishDrawArrays(mode, first, count) glish3::drawArrays(mode, first, count, FILE_LINE )
#endif //GLISH3_ERRORHANLDER_HPP