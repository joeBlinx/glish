//
// Created by stiven on 10/31/18.
//

#ifndef GLISH3_UNIFORM_H
#define GLISH3_UNIFORM_H

#include <GL/glew.h>

#include <string>
#include <map>
#include <iostream>
namespace glish3 {
	struct ProgramGL;
	struct uni_settings{
		std::string name;
        GLint type;
	};

    class Uniform {
		friend struct ProgramGL;
    	static std::map<GLint, void(Uniform::*)(void*)const> function;
    	uni_settings settings;
		ProgramGL *program = nullptr;

        GLint uniform = 0;

		void uniform1fv(void * value)const;
		void uniform2fv(void * value)const;
		void uniform3fv(void * value)const;
		void uniform4fv(void * value)const;
		void uniform1iv(void * value)const;
		void uniform2iv(void * value)const;
		void uniform3iv(void * value)const;
		void uniform4iv(void * value)const;


		void uniform_matrix2fv(void * value)const;
		void uniform_matrix3fv(void * value)const;
		void uniform_matrix4fv(void * value)const;

    public:

        Uniform() = default;

        Uniform(uni_settings const & settings, ProgramGL &prog);

        Uniform(Uniform&&) = default;
        Uniform&operator=(Uniform&& uni) = default;
		Uniform(Uniform const&) = default;
		Uniform&operator=(Uniform const&) = default;
	
        operator bool() const;

        explicit operator GLint();

        template<class T> void operator=(T * value) const;

        //for debugging purpose
	friend std::ostream& operator<<(std::ostream &stream, Uniform const & uni);
    };
}


template<class T>
void glish3::Uniform::operator=(T *  value) const{
	(this->*Uniform::function[settings.type])((void*)value);
}
#endif //GLISH3_UNIFORM_H
