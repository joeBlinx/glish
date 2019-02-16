//
// Created by stiven on 10/31/18.
//
#include <glish3/uniform.hpp>
#include <glish3/glfunction.hpp>
#include <glish3/programGL.hpp>

namespace glish3 {
    std::map<std::string, void(Uniform::*)(void*)> Uniform::function{
			{"int", &Uniform::uniform1iv},
			{"sampler2D", &Uniform::uniform1iv},
			{"bool", &Uniform::uniform1iv},
			{"ivec2", &Uniform::uniform2iv},
			{"ivec3", &Uniform::uniform3iv},
			{"ivec4", &Uniform::uniform4iv},

			{"float", &Uniform::uniform1fv},
			{"vec2", &Uniform::uniform2fv},
			{"vec3", &Uniform::uniform3fv},
			{"vec4", &Uniform::uniform4fv},
			{"mat2", &Uniform::uniform_matrix2fv},
			{"mat3", &Uniform::uniform_matrix3fv},
			{"mat4", &Uniform::uniform_matrix4fv}

    };
    Uniform::Uniform(uni_settings const & settings, ProgramGL &prog):
    											settings(settings),
                                                program(&prog)
    {
        uniform = glishGetUniformLocation((GLuint)prog, this->settings.name.c_str());
    }

    Uniform::operator bool() const {
        return (bool) uniform;
    }
    Uniform::operator GLint() {
        return uniform;
    }

	void Uniform::uniform1fv(void *value) {
		glishUniform1fv(uniform, 1, (GLfloat*) value);
	}

	void Uniform::uniform2fv(void *value) {
		glishUniform2fv(uniform, 1, (GLfloat*) value);
	}

	void Uniform::uniform3fv(void *value) {
		glishUniform3fv(uniform, 1, (GLfloat*) value);
	}

	void Uniform::uniform4fv(void *value) {
		glishUniform4fv(uniform, 1, (GLfloat*) value);
	}

	void Uniform::uniform1iv(void *value) {
		glishUniform1iv(uniform, 1, (GLint*)value);
	}

	void Uniform::uniform2iv(void *value) {
		glishUniform2iv(uniform, 1, (GLint*)value);
	}

	void Uniform::uniform3iv(void *value) {
		glishUniform3iv(uniform, 1, (GLint*)value);
	}

	void Uniform::uniform4iv(void *value) {
		glishUniform4iv(uniform, 1, (GLint*)value);
	}

	void Uniform::use_program() {
		std::cout << *this << std::endl;
		program->use();
	}

	 std::ostream& operator<<(std::ostream &stream, Uniform const & uni){
                std::cout << "my address is " << &uni << std::endl;
                std::cout << "my name is "<< uni.settings.name << std::endl;
                std::cout << "my program is " << uni.program << std::endl;
                std::cout << "my program ID is " << (GLuint)*uni.program << std::endl;
                return stream;
        }



	void Uniform::uniform_matrix2fv(void *value) {
		glUniformMatrix2fv(uniform, 1, GL_FALSE, (GLfloat *)value);
	}

	void Uniform::uniform_matrix3fv(void *value) {
		glUniformMatrix3fv(uniform, 1, GL_FALSE, (GLfloat *)value);
	}

	void Uniform::uniform_matrix4fv(void *value) {
		glUniformMatrix4fv(uniform, 1, GL_FALSE, (GLfloat *)value);
	}



}
