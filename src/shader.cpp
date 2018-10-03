//
// Created by joe on 01/10/18.
//
#include <glish3/gl_glew.hpp>
#include <glish3/shader.hpp>
#include <glish3/log/errorHandler.hpp>

#include <glish3/glfunction.hpp>
#include <fstream>
#include <map>
#include <vector>

namespace glish3 {
	std::map<GLenum, std::string> match{
			{GL_VERTEX_SHADER, "vertex shader"},
			{GL_FRAGMENT_SHADER, "fragment shader"},
			{GL_GEOMETRY_SHADER, "geometry shader"},
			{GL_COMPUTE_SHADER, "compute shader"}
	};
	Shader::Shader(GLenum shaderType, const char *data):
	shaderId(glishCreateShader(shaderType)),
	shaderType(shaderType){
		if(!data){
			log.warning("data pass to shader is null, shader will not be compiled");
			return;
		}

		compileShader(data);
	}

	void Shader::compileShader(const char * data) {

		GLint result = GL_FALSE;
		int infoLog;
		glishShadersource(shaderId, 1, &data, nullptr);
		glishCompileShader(shaderId);
		glishGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
		glishGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLog);

		if (infoLog > 0) {
			std::vector<char> VertexShaderErrorMessage (infoLog + 1);
			glishGetShaderInfoLog(shaderId, infoLog, nullptr, VertexShaderErrorMessage.data());
			log.title("compile " + match[shaderType]);
			log.info(VertexShaderErrorMessage.data());
		}
	}

	Shader Shader::createShaderFromFile(GLenum shaderType, const char *path) {

		std::ifstream stream{path};
		const char * cdata = nullptr;
		std::string data;
		if(!stream){
			log.fileNotFound(path);
		}else{
			std::string read;
			while (getline(stream, read)) {
				data += "\n" + read;
			}
			cdata = data.c_str();
		}

		return Shader(shaderType, cdata);
	}

	Shader Shader::createShaderFromData(GLenum shaderType, const char *data) {
		return Shader(shaderType, data);
	}

	Shader::operator  GLuint () {
		return shaderId;
	}

	Shader::~Shader() {
		if(shaderId) {
			glishDeleteShader(shaderId);
		}

	}
}