
//
// Created by darkblinx on 29/06/17.
//

#ifndef GLENGINE_LOG_HPP
#define GLENGINE_LOG_HPP

#include <iostream>
#include <cassert>


namespace glish {
#ifdef NDEBUG
	constexpr bool debug = false;
#else
	constexpr bool debug = true;
#endif
    void getError();
}
#endif //GLENGINE_LOG_HPP

