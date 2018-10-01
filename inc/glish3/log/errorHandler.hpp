//
// Created by joe on 23/09/18.
//

#ifndef GLISH3_ERRORHANDLER_HPP
#define GLISH3_ERRORHANDLER_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <cstring>
#include "log.hpp"

namespace glish3 {
#ifdef NDEBUG
	bool constexpr debug = false;
#else
	bool constexpr debug = true;
#endif
	extern Log log;
	void init(const std::string &path, std::string const &project = "undefined") ;

	std::string createLink(std::string const & functionName);

	static void getError(std::string const &functionName, std::string const & file, std::string const & line) {
		if constexpr(debug) {
			GLenum error = glGetError();
			if (error) {
				char unsigned const * a = gluErrorString(error);
				char * b = new char[std::strlen((char * const)a)];
				std::strcpy(b, (char * const)a);
				std::string message = "file : " + file + ", line: " + line +" "+ b;
				log.error(message+", " + createLink(functionName)) ;
			}
		}
	}
}

#endif //GLISH3_ERRORHANDLER_HPP
