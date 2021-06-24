//
// Created by joe on 01/10/18.
//

#include <glish3/programGL.hpp>

#include <iostream>
namespace glish3 {

	void ProgramGL::use() {
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


}

