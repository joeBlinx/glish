//
// Created by joe on 01/10/18.
//

#ifndef GLISH3_ProgramGL_HPP
#define GLISH3_ProgramGL_HPP

#include <glish3/gl_glew.hpp>
#include <glish3/shader.hpp>
#include <glish3/glfunction.hpp>
#include <glish3/log/errorHandler.hpp>
#include <vector>
#include <map>
#include "uniform.hpp"

namespace glish3{
    class Shader;
	class ProgramGL{
		inline static GLuint currentProgram = 0;
		GLuint program = 0;
		std::map<std::string, Uniform> uniforms;

        void createUniform(Shader &shader);
	public:
		ProgramGL(ProgramGL const &) = delete;
		ProgramGL& operator=(ProgramGL const &) = delete;

		ProgramGL(ProgramGL && ProgramGL);
		ProgramGL& operator=(ProgramGL && ProgramGL);

		ProgramGL() = default;

		template <class ...Shaders>
		ProgramGL(Shaders  &... shaders){

			program = glishCreateProgram();
			(glishAttachShader(program, (GLuint)shaders), ...);
			glishLinkProgram(program);
			(glishDetachShader(program, (GLuint)shaders), ...);
			GLint Result;
			int InfoLogLength = 0;
			glishGetProgramiv(program, GL_LINK_STATUS, &Result);
			glishGetProgramiv(program, GL_INFO_LOG_LENGTH, &InfoLogLength);

			if (InfoLogLength > 0) {
				std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
				glishGetProgramInfoLog(program, InfoLogLength, NULL, ProgramErrorMessage.data());
				log.title("compile Program");
				log.info(ProgramErrorMessage.data());
			}
            (createUniform(shaders), ...);
		}
		void use();
		explicit operator GLuint()const ;

		Uniform &operator[](const std::string &name);

		~ProgramGL();

	};
}
#endif //GLISH3_ProgramGL_HPP
