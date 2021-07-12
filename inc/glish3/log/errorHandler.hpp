//
// Created by joe on 23/09/18.
//

#ifndef GLISH3_ERRORHANDLER_HPP
#define GLISH3_ERRORHANDLER_HPP

#include <GL/glew.h>
#include <GL/gl.h>
#include <cstring>
#include <string>
namespace glish3 {
    void use_debug_output();
#ifdef NDEBUG
	bool constexpr debug = false;
#else
	bool constexpr debug = true;
#endif

	std::string createLink(std::string const & functionName);

}

#endif //GLISH3_ERRORHANDLER_HPP
