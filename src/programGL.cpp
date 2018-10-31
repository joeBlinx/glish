//
// Created by joe on 01/10/18.
//

#include <glish3/glfunction.hpp>
#include <glish3/programGL.hpp>

namespace glish3 {
	ProgramGL::~ProgramGL() {
		if (program) {
			glishDeleteProgram(program);
		}
	}

	ProgramGL::ProgramGL(ProgramGL &&ProgramGL) :program(ProgramGL.program){
		ProgramGL.program = 0;
	}

	ProgramGL &ProgramGL::operator=(ProgramGL &&ProgramGL) {
		program = ProgramGL.program;
		ProgramGL.program = 0;
		return *this;
	}

	void ProgramGL::use() {
		glishUseProgram(program);
	}

    ProgramGL::operator GLuint() const {
        return program;
    }

	void ProgramGL::createUniform(Shader &shader) {

		std::vector<std::string> const & uniformsName = shader.getUniformsName();
		for(auto & name: uniformsName){
			uniforms[name] = Uniform(name, *this);
		}
	}

	Uniform &ProgramGL::operator[](const std::string &name) {
		return uniforms[name];
	}


}

