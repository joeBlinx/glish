//
// Created by joe on 01/10/18.
//

#ifndef GLISH3_ProgramGL_HPP
#define GLISH3_ProgramGL_HPP

#include <glish3/gl_glew.hpp>
#include <glish3/shader.hpp>
#include <glish3/log/errorHandler.hpp>
#include <vector>
#include <map>
#include <glish3/gl_memory/unique_programgl.hpp>
#include "uniform.hpp"

namespace glish3{
    class Shader;
	class ProgramGL{
		inline static GLuint currentProgram = 0;
		UniqueProgramGL _program = 0;
		std::map<std::string, Uniform> uniforms;

        void createUniform(Shader &shader);
	public:


		template <class ...Shaders>
		ProgramGL(Shaders  &... shaders){

			GLuint program = glCreateProgram();
			(glAttachShader(program, (GLuint)shaders), ...);
			glLinkProgram(program);
			(glDetachShader(program, (GLuint)shaders), ...);
			GLint Result;
			int InfoLogLength = 0;
			glGetProgramiv(program, GL_LINK_STATUS, &Result);
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &InfoLogLength);

			if (InfoLogLength > 0) {
				std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
				glGetProgramInfoLog(program, InfoLogLength, NULL, ProgramErrorMessage.data());
				log.title("compile Program");
				log.info(ProgramErrorMessage.data());
			}
			_program = UniqueProgramGL(program);
            (createUniform(shaders), ...);
		}
		void use();
		explicit operator GLuint()const ;

		Uniform &operator[](const std::string &name);


	};
}
#endif //GLISH3_ProgramGL_HPP
