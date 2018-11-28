//
// Created by joe on 01/10/18.
//

#include <glish3/glfunction.hpp>
#include <glish3/programGL.hpp>

#include <iostream>
namespace glish3 {
	ProgramGL::~ProgramGL() {
		if (program) {
			glishDeleteProgram(program);
		}
	}

	ProgramGL::ProgramGL(ProgramGL &&ProgramGL) :program(ProgramGL.program), uniforms(std::move(ProgramGL.uniforms)){
		ProgramGL.program = 0;
	}

	ProgramGL &ProgramGL::operator=(ProgramGL &&ProgramGL) {
		program = ProgramGL.program;
		ProgramGL.program = 0;
		uniforms = std::move(ProgramGL.uniforms);
		return *this;
	}

	void ProgramGL::use() {
		if (ProgramGL::currentProgram != program) {
			glishUseProgram(program);
			ProgramGL::currentProgram = program;
		}
	}

    ProgramGL::operator GLuint() const {
        return program;
    }

	void ProgramGL::createUniform(Shader &shader) {

		auto const & uniformsName = shader.getUniSettings();
		for(auto & settings: uniformsName){
			uniforms[settings.name] = Uniform(settings, *this);
			std::cout << uniforms[settings.name] ;
		}
	}

	Uniform &ProgramGL::operator[](const std::string &name) {
		return uniforms[name];
	}


}

