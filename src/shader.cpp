//
// Created by joe on 01/10/18.
//

#include <glish3/glish3.hpp>
#include <glish3/shader.hpp>
#include <fstream>

#include "glish3/shader.hpp"
namespace glish3 {
	Shader::Shader(GLenum shaderType, const char *data):
	shaderId(glishCreateShader(shaderType)),
	shaderType(shaderType){
		compileShader(data);
	}

	void Shader::compileShader(const char * data) {
		GLint result = GL_FALSE;
		int infoLog;
		glishShadersource(shaderId, 1, &data, NULL);

	}
	Shader Shader::createShaderFromFile(GLenum shaderType, const char *path) {
		std::ifstream stream{path};
		if(!stream){
			std::string warn{"file not found"};
			warn += path;
			log.warning(warn);
			return Shader();
		}
		std::string shader;
		std::string read;
		while(getline(stream, read)){
			shader += "\n" + read;
		}

		return Shader(shaderType, shader.c_str());
	}

	Shader Shader::createShaderFromData(GLenum shaderType, const char *data) {
		return Shader(shaderType, data);
	}

	Shader::operator GLuint const() {
		return shaderType;
	}

	Shader::~Shader() {

	}
}