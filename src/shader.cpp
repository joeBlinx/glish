//
// Created by joe on 01/10/18.
//

#include <glish3/shader.hpp>
#include <fstream>
#include <glish3/glish3.hpp>

#include "glish3/shader.hpp"
namespace glish3 {
	Shader::Shader(GLenum shaderType, const char *data) {

	}

	Shader Shader::createShaderFromFile(GLenum shaderType, const char *path) {
		std::ifstream stream{path};
		std::string data;
		if(!stream){
			std::string warn{"file not found"};
			warn += path;
			log.warning(warn);
		}else{

		}

		return Shader(shaderType, data.c_str());
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