//
// Created by joe on 01/10/18.
//

#ifndef GLISH3_ProgramGL_HPP
#define GLISH3_ProgramGL_HPP
#include <GL/glew.h>
#include <string>
#include <vector>
#include "glish3/log/log.hpp"
#include <unordered_map>
#include "glish3/log/errorHandler.hpp"// IWYU pragma: keep
#include "glish3/gl_memory/unique_programgl.hpp"
#include "glish3/uniform.hpp"
#include "glish3/shader.hpp" // IWYU pragma: keep

namespace glish3{
	struct ProgramGL{
		inline static GLuint currentProgram = 0;
		static std::map<GLenum, GLenum> shader_to_stage;
		UniqueProgramGL _program = 0;
		std::unordered_map<std::string, Uniform> uniforms;
        GLbitfield _stages{};
        void createUniform();

	public:

		template <class ...Shaders>
		ProgramGL(GLboolean separable, Shaders  &... shaders):
		_program(make_unique_gl_program()),
		_stages((shader_to_stage[shaders.get_type()] | ...))
		{

			(glAttachShader(_program, (GLuint)shaders), ...);
            glProgramParameteri(_program, GL_PROGRAM_SEPARABLE, separable);
			glLinkProgram(_program);
			(glDetachShader(_program, (GLuint)shaders), ...);
			GLint Result;
			int InfoLogLength = 0;
			glGetProgramiv(_program, GL_LINK_STATUS, &Result);
			glGetProgramiv(_program, GL_INFO_LOG_LENGTH, &InfoLogLength);

			if (InfoLogLength > 0) {
				std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
				glGetProgramInfoLog(_program, InfoLogLength, nullptr, ProgramErrorMessage.data());
                glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION,
                                     GL_DEBUG_TYPE_ERROR,
                                     0, GL_DEBUG_SEVERITY_HIGH,
                                     ProgramErrorMessage.size(),
                                     ProgramErrorMessage.data());
				log.title("compile Program");
				log.info(ProgramErrorMessage.data());
			}

            createUniform();
			gather_attributes();
		}
		std::unordered_map<std::string, GLint> gather_attributes() const;
		void use()const;
		explicit operator GLuint()const ;
        GLbitfield get_types() const{return _stages;}
		Uniform const& operator[](const std::string &name) const;
        static ProgramGL create_separate_program(Shader const& shader);

        template<class ...Shaders>
        static ProgramGL create_program(Shaders const& ...shaders)
        requires (std::is_same_v<Shader, Shaders> && ...){
            return ProgramGL(GL_FALSE, shaders ...);
        }

	};
}
#endif //GLISH3_ProgramGL_HPP
