//
// Created by stiven on 10/31/18.
//

#ifndef GLISH3_UNIFORM_H
#define GLISH3_UNIFORM_H

#include <glish3/gl_glew.hpp>

#include <string>
#include <map>
#include <iostream>
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

        Uniform(Uniform&&) = delete;
        Uniform&operator=(Uniform&& uni);
		Uniform(Uniform const&) = delete;
		Uniform&operator=(Uniform const&) = delete;
	
        operator bool() const;

        explicit operator GLint();

        template<class T> void operator=(T * value);

	friend std::ostream& operator<<(std::ostream &stream, Uniform const & uni){
		std::cout << "my address is " << &uni << std::endl;
		std::cout << "my name is "<< uni.settings.name << std::endl;
		std::cout << "my program is " << uni.program << std::endl;
		return stream;
	}
    };
}


template<class T>
void glish3::Uniform::operator=(T *  value){
	use_program();
	(this->*Uniform::function[settings.type])((void*)value);
}
#endif //GLISH3_UNIFORM_H
