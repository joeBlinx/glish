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

	void ProgramGL::createUniform(Shader &shader) {

		auto const & uniformsName = shader.getUniSettings();
		for(auto & settings: uniformsName){
			uniforms[settings.name] = Uniform(settings, *this);
		}
	}

	Uniform const& ProgramGL::operator[](const std::string &name) const{
		return uniforms.at(name);
	}


}

