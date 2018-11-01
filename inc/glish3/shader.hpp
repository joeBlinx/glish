//
// Created by joe on 01/10/18.
//

#ifndef GLISH3_SHADER_HPP
#define GLISH3_SHADER_HPP


#include <GL/gl.h>
#include <string>
#include <vector>
#include <glish3/uniform.hpp>

namespace glish3 {

	class Shader {

		GLuint shaderId = 0;
		GLenum shaderType;

		std::vector<uni_settings> uniforms_settings;
		Shader() = default;

		Shader(GLenum shaderType, const char * data);
		void compileShader(const char * data);
		void findUniformsName(const char * data);

	public:

		Shader(Shader const &) = delete;
		Shader& operator= (Shader const &) = delete;

		Shader(Shader &&)= delete;
		Shader& operator=(Shader &&) = delete;

		const std::vector<uni_settings> & getUniSettings();

		static Shader createShaderFromFile(GLenum shaderType, const char * path);
		static Shader createShaderFromData(GLenum shaderType, const char * data);
		explicit operator  GLuint ();
		~Shader();

	};
}

#endif //GLISH3_SHADER_HPP
