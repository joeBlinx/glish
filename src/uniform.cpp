//
// Created by stiven on 10/31/18.
//
#include <glish3/uniform.hpp>
#include <glish3/programGL.hpp>

namespace glish3 {
    std::map<GLint, void(Uniform::*)(void*)const> Uniform::function{
			{GL_INT, &Uniform::uniform1iv},
			{GL_SAMPLER_2D, &Uniform::uniform1iv},
			{GL_BOOL, &Uniform::uniform1iv},
			{GL_INT_VEC2, &Uniform::uniform2iv},
			{GL_INT_VEC3, &Uniform::uniform3iv},
			{GL_INT_VEC4, &Uniform::uniform4iv},

			{GL_FLOAT, &Uniform::uniform1fv},
			{GL_FLOAT_VEC2, &Uniform::uniform2fv},
			{GL_FLOAT_VEC3, &Uniform::uniform3fv},
			{GL_FLOAT_VEC4, &Uniform::uniform4fv},
			{GL_FLOAT_MAT2, &Uniform::uniform_matrix2fv},
			{GL_FLOAT_MAT3, &Uniform::uniform_matrix3fv},
			{GL_FLOAT_MAT4, &Uniform::uniform_matrix4fv}

    };
    Uniform::Uniform(uni_settings const & settings, ProgramGL &prog):
    											settings(settings),
                                                program(&prog)
    {
        uniform = glGetUniformLocation((GLuint)prog, this->settings.name.c_str());
    }

    Uniform::operator bool() const {
        return (bool) uniform;
    }
    Uniform::operator GLint() {
        return uniform;
    }

	void Uniform::uniform1fv(void *value) const {
		glProgramUniform1fv((GLuint)*program, uniform, 1, (GLfloat*) value);
	}

	void Uniform::uniform2fv(void *value) const {
		glProgramUniform2fv((GLuint)*program, uniform, 1, (GLfloat*) value);
	}

	void Uniform::uniform3fv(void *value) const {
		glProgramUniform3fv((GLuint)*program, uniform, 1, (GLfloat*) value);
	}

	void Uniform::uniform4fv(void *value) const {
		glProgramUniform4fv((GLuint)*program, uniform, 1, (GLfloat*) value);
	}

	void Uniform::uniform1iv(void *value) const {
		glProgramUniform1iv((GLuint)*program, uniform, 1, (GLint*)value);
	}

	void Uniform::uniform2iv(void *value) const {
		glProgramUniform2iv((GLuint)*program, uniform, 1, (GLint*)value);
	}

	void Uniform::uniform3iv(void *value) const {
		glProgramUniform3iv((GLuint)*program, uniform, 1, (GLint*)value);
	}

	void Uniform::uniform4iv(void *value) const {
		glProgramUniform4iv((GLuint)*program, uniform, 1, (GLint*)value);
	}

	void Uniform::use_program() const{
		program->use();
	}

	 std::ostream& operator<<(std::ostream &stream, Uniform const & uni){
                std::cout << "my address is " << &uni << std::endl;
                std::cout << "my name is "<< uni.settings.name << std::endl;
                std::cout << "my (GLuint)program is " << uni.program << std::endl;
                std::cout << "my (GLuint)program ID is " << (GLuint)*uni.program << std::endl;
                return stream;
        }



	void Uniform::uniform_matrix2fv(void *value) const {
		glProgramUniformMatrix2fv((GLuint)*program, uniform, 1, GL_FALSE, (GLfloat *)value);
	}

	void Uniform::uniform_matrix3fv(void *value) const {
		glProgramUniformMatrix3fv((GLuint)*program, uniform, 1, GL_FALSE, (GLfloat *)value);
	}

	void Uniform::uniform_matrix4fv(void *value) const {
		glProgramUniformMatrix4fv((GLuint)*program, uniform, 1, GL_FALSE, (GLfloat *)value);
	}



}
