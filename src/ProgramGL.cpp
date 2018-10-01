//
// Created by joe on 01/10/18.
//

#include <glish3/ProgramGL.hpp>
#include <glish3/glish3.hpp>

namespace glish3 {
	ProgramGL::~ProgramGL() {

		if (program) {
			glishDeleteProgram(program);
		}
	}

	ProgramGL::ProgramGL(ProgramGL &&programGL) :program(programGL.program){
		programGL.program = 0;
	}

	ProgramGL &ProgramGL::operator=(ProgramGL &&programGL) {
		program = programGL.program;
		programGL.program = 0;
		return *this;
	}

	void ProgramGL::use() {
		glishUseProgram(program);
	}
}

