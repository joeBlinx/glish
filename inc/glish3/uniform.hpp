//
// Created by stiven on 10/31/18.
//

#ifndef GLISH3_UNIFORM_H
#define GLISH3_UNIFORM_H

#include <glish3/gl_glew.hpp>

#include <string>
#include <map>

namespace glish3 {
	class ProgramGL;
	struct uni_settings{
		std::string name;
		std::string type;
	};

    class Uniform {

    	static std::map<std::string, void(Uniform::*)(void*)> function;
    	uni_settings settings;
		ProgramGL *program = nullptr;

        GLint uniform = 0;

		void uniform1fv(void * value);
		void uniform2fv(void * value);
		void uniform3fv(void * value);
		void uniform4fv(void * value);
		void uniform1iv(void * value);
		void uniform2iv(void * value);
		void uniform3iv(void * value);
		void uniform4iv(void * value);

		void use_program(); // here to avoid circular dependencies
    public:

        Uniform() = default;

        Uniform(uni_settings const & settings, ProgramGL &prog);

        Uniform(Uniform&&) = default;
        Uniform&operator=(Uniform&&) = default;
		Uniform(Uniform const&) = default;
		Uniform&operator=(Uniform const&) = default;

        operator bool() const;

        explicit operator GLint();

        template<class T> void operator=(T * value);


    };
}


template<class T>
void glish3::Uniform::operator=(T *  value){
	use_program();
	(this->*Uniform::function[settings.type])((void*)value);
}
#endif //GLISH3_UNIFORM_H
