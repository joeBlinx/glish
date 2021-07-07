//
// Created by joe on 01/10/18.
//

#include <glish3/programGL.hpp>

#include <iostream>
namespace glish3 {
    std::map<GLenum, GLenum> ProgramGL::shader_to_stage{
            {GL_VERTEX_SHADER, GL_VERTEX_SHADER_BIT},
            {GL_FRAGMENT_SHADER, GL_FRAGMENT_SHADER_BIT},
            {GL_TESS_CONTROL_SHADER, GL_TESS_CONTROL_SHADER_BIT},
            {GL_GEOMETRY_SHADER, GL_GEOMETRY_SHADER_BIT},
            {GL_TESS_EVALUATION_SHADER, GL_TESS_EVALUATION_SHADER_BIT},
            {GL_COMPUTE_SHADER, GL_COMPUTE_SHADER_BIT}
    };
	void ProgramGL::use() const{
		if (ProgramGL::currentProgram != _program.get()) {
			glUseProgram(_program.get());
			ProgramGL::currentProgram = _program.get();
		}
	}

    ProgramGL::operator GLuint() const {
        return _program.get();
    }

	void ProgramGL::createUniform() {

		GLint active_uniform {};
		glGetProgramInterfaceiv(_program, GL_UNIFORM, GL_ACTIVE_RESOURCES, &active_uniform);
		for (GLint i = 0; i < active_uniform; i++){
            constexpr int buf_size = 15;
            char name[buf_size];
		    GLsizei length{};
		    glGetProgramResourceName(_program, GL_UNIFORM, i, buf_size, &length, name);
		    GLenum prop = GL_TYPE;
		    GLint type{};
		    glGetProgramResourceiv(_program,
		            GL_UNIFORM,
		            i,
		            1,
		            &prop,
		            sizeof(GLint),
		            &length,
		            &type
		            );
		    uni_settings settings{
		        .name = name,
		        .type = type
		    };
            uniforms[settings.name] = Uniform(settings, *this);
		}
	}

	Uniform const& ProgramGL::operator[](const std::string &name) const{
		return uniforms.at(name);
	}
	ProgramGL ProgramGL::create_separate_program(Shader const& shader){
           return ProgramGL(GL_TRUE, shader);
	}

    void ProgramGL::gather_attributes() {
        GLint active_attributes {};
        glGetProgramInterfaceiv(_program, GL_PROGRAM_INPUT, GL_ACTIVE_RESOURCES, &active_attributes);
        for (GLint i = 0; i < active_attributes; i++){
            constexpr int buf_size = 15;
            char name[buf_size];
            GLsizei length{};
            glGetProgramResourceName(_program, GL_PROGRAM_INPUT, i, buf_size, &length, name);
            _attributes.insert(std::pair(name, glGetAttribLocation(_program, name)));

        }
    }

}

