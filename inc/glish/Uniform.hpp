//
// Created by stiven on 07/03/16.
//

#ifndef LIBRARY_UNIFORM_HPP
#define LIBRARY_UNIFORM_HPP

#include <GL/glew.h>
#include <string>
#include <typeinfo>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glish/program/Program.hpp"
#include <glish/uniBase.hpp>
namespace glish {


    /*! \class Uniform
     *  \brief génere un identifiant pour un uniforme
     *  et conserve une reference vers le program auquel il est associé */
    template <class T>
    class Uniform : public UniBase {
    	using type = T;

        Program *prog = nullptr;
        GLint uni;
        //T type;

    public :

        /*!
         * \param program: program auquel on asssocie l'uniform que l'on va créer
         * \param name: identifiant de l'uniform dans le shader dans lequel  va être utilisé
         */
        Uniform () = default;
        Uniform(Program *program, std::string &&name){
            prog = program;
            uni = glGetUniformLocation(prog->getProgram(),
                                       name.c_str());
        }
        void init (Program *program, std::string &&name){

            prog = program;
            uni = glGetUniformLocation(prog->getProgram(),
                                             name.c_str());
        }
        Uniform (Uniform const &) = delete;


        /*!
         * \param value: valeur à passer à l'uniform
         * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
         *
         */
        void operator=(const int value)override ;
        /*!
       * \param value: valeur à passer à l'uniform
       * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
       *
       */
        void operator=(const float value)override ;
        /*!
       * \param value: valeur à passer à l'uniform
       * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
       *
       */
        void operator=(const double value)override ;
        /*!
       * \param value: valeur à passer à l'uniform
       * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
       *
       */
        void operator=(const glm::vec2 &value)override ;
        /*!
       * \param value: valeur à passer à l'uniform
       * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
       *
       */
        void operator= (const glm::vec3 &value)override ;
        /*!
       * \param value: valeur à passer à l'uniform
       * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
       *
       */
        void operator= (const glm::mat3 &value)override ;
        /*!
       * \param value: valeur à passer à l'uniform
       * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
       *
       */
        void operator= (const bool value)override ;

        void operator=(const glm::mat4 & value)override ;
        void operator=(const glm::mat2 & value)override ;
        void operator=(const glm::vec4 & value)override ;
    };




}

#include <glish/Uniform.tpp>


#endif //LIBRARY_UNIFORM_HPP
