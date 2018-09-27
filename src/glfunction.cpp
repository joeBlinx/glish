//
// Created by joe on 23/09/18.
//

#include <glish3/glfunction.hpp>
#include <glish3/log/errorHandler.hpp>

namespace glish3{
#
	void clearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha, const char *file, int line) {
		glClearColor(red, green, blue, alpha);
		getError("glClearColor", file, std::to_string(line));
	}

	void enable(GLenum cap) {
		glEnable(cap);
		//getError("glEnable");

	}

	void blendFunc(GLenum sfactor, GLenum dfactor) {
		glBlendFunc(sfactor, dfactor);
		//getError("glBlendFunc");

	}
}