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
namespace glish3{
	class ProgramGL{

		GLuint program;


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
			int InfoLogLength;
			glishGetProgramiv(program, GL_LINK_STATUS, &Result);
			glishGetProgramiv(program, GL_INFO_LOG_LENGTH, &InfoLogLength);
			if (InfoLogLength > 0) {
				std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
				glishGetProgramInfoLog(program, InfoLogLength, NULL, ProgramErrorMessage.data());
				log.title("compile Program");
				log.info(ProgramErrorMessage.data());
			}
		}
		void use();

		~ProgramGL();

	};
}
#endif //GLISH3_ProgramGL_HPP
