//
// Created by joe on 01/10/18.
//
#include <glish3/gl_glew.hpp>
#include <glish3/shader.hpp>
#include <glish3/log/errorHandler.hpp>
#include <fstream>
#include <map>
#include <vector>
#include <utils/stringUtil.h>
#include <sstream>
#include <filesystem>

namespace glish3 {
	static std::map<GLenum, std::string> match{
			{GL_VERTEX_SHADER, "vertex shader"},
			{GL_FRAGMENT_SHADER, "fragment shader"},
			{GL_GEOMETRY_SHADER, "geometry shader"},
			{GL_COMPUTE_SHADER, "compute shader"}
	};

	Shader::Shader(GLenum shaderType, const char *data):
	_shader(glCreateShader(shaderType)),
	shaderType(shaderType){
		if(!data){
			log.warning("data pass to shader is null, shader will not be compiled");
			return;
		}
		findUniformsName(data);
		compileShader(data);
	}

	void Shader::compileShader(const char * data) {

		GLint result = GL_FALSE;
		auto shaderID = _shader.get();
		int infoLog;
		glShaderSource(shaderID, 1, &data, nullptr);
		glCompileShader(shaderID);
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLog);

		if (infoLog > 0) {
			std::vector<char> VertexShaderErrorMessage (infoLog + 1);
			glGetShaderInfoLog(shaderID, infoLog, nullptr, VertexShaderErrorMessage.data());
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
			std::stringstream error_message;
			error_message << "File: " << path << " not found. cwd is " << std::filesystem::current_path();
			std::string error = error_message.str();
            glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION,
                    GL_DEBUG_TYPE_ERROR,
                    0, GL_DEBUG_SEVERITY_HIGH,
                    error.size(),
                    error.c_str());
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
		return _shader.get();
	}

	void Shader::findUniformsName(const char *data) {

		data = strstr(data, "uniform");
		uni_settings settings{};
		unsigned long  size;

		while(data){

			data = strstr(data, " ");
			utils::advanceWhile(&data, ' ');

			size =  strstr(data," ") - data ; // get type
			settings.type.resize(size);
			std::strncpy(settings.type.data(), data, size);

			data = strstr(data, " ");
			utils::advanceWhile(&data, ' ');
			size =  strstr(data,";") - data ; //get name

			settings.name.resize(size);
			std::strncpy(settings.name.data(), data, size);

			uniforms_settings.emplace_back(settings);

			data = strstr(data, "uniform");
		}

	}

	const std::vector<uni_settings> & Shader::getUniSettings() {
		return uniforms_settings;
	}
}