//
// Created by joe on 01/10/18.
//
#include "glish3/shader.hpp"
#include "glish3/log/errorHandler.hpp" // IWYU pragma: keep
#include <map>
#include <vector>
#include <sstream>
#include <filesystem>
#include <string>
#include <fstream>

namespace glish3 {
	static std::map<GLenum, std::string> match{
			{GL_VERTEX_SHADER, "vertex shader"},
			{GL_FRAGMENT_SHADER, "fragment shader"},
			{GL_GEOMETRY_SHADER, "geometry shader"},
			{GL_COMPUTE_SHADER, "compute shader"}
	};

	Shader::Shader(GLenum shader_type, const char *data):
	_shader(make_unique_shader(shader_type)),
	shaderType(shader_type){
		if(!data){
		    const char error[] = "data pass to shader is null, shader will not be compiled";
		    glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION,
                                 GL_DEBUG_TYPE_ERROR,
                                 0, GL_DEBUG_SEVERITY_HIGH,
                                 sizeof(error),
                                 error);
			return;
		}
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
			std::vector<char> error (infoLog + 1);
            glGetShaderInfoLog(shaderID, infoLog, nullptr, error.data());

            std::stringstream error_message;
            error_message << "Shader data is: " << data << "\nerror is: "<< error.data();
            glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION,
                                 GL_DEBUG_TYPE_ERROR,
                                 0, GL_DEBUG_SEVERITY_HIGH,
                                 error_message.str().size(),
                                 error_message.str().data());

		}
	}

	Shader Shader::createShaderFromFile(GLenum shaderType, const char *path) {

		std::ifstream stream{path};
		const char * cdata = nullptr;
		std::string data;
		if(!stream){
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

	Shader::operator  GLuint () const{
		return _shader.get();
	}


}