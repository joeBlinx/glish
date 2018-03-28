//
// Created by Stiven on 28-Mar-18.
//

#include "glish/utils/uniContainer.hpp"
namespace glish{

	UniBase &UniContainer::operator[](std::string &&uniform) {
		return *uniforms[std::move(uniform)];
	}

	void UniContainer::use() {
		prog.useProgram();
	}
}
