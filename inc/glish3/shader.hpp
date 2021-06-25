//
// Created by joe on 01/10/18.
//

#ifndef GLISH3_SHADER_HPP
#define GLISH3_SHADER_HPP


#include <GL/gl.h>
#include <string>
#include <vector>
#include <glish3/uniform.hpp>
#include <glish3/gl_memory/unique_shader.hpp>

namespace glish3 {

	class Shader {

		UniqueShader _shader = 0;
		GLenum shaderType{};

		std::vector<uni_settings> uniforms_settings;
		Shader() = default;

		Shader(GLenum shader_type, const char * data);
		void compileShader(const char * data);

	public:

		static Shader createShaderFromFile(GLenum shaderType, const char * path);
		static Shader createShaderFromData(GLenum shaderType, const char * data);
		operator  GLuint () const;
		GLenum get_type() const{
		    return shaderType;
		}


	};
}

#endif //GLISH3_SHADER_HPP
