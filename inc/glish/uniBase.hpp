//
// Created by Stiven on 28-Mar-18.
//

#ifndef INC_2DENGINE_UNIBASE_H
#define INC_2DENGINE_UNIBASE_H

#include <glm/vec2.hpp>
#include <glm/detail/type_mat.hpp>

namespace glish {
	struct UniBase {
		virtual void updateProg(class Program * prog) = 0;
		/*!
		  * \param value: valeur à passer à l'uniform
		  * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
		  *
		  */
		virtual void operator=(const int value) {

		}

		/*!
	   * \param value: valeur à passer à l'uniform
	   * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
	   *
	   */
		virtual void operator=(const float value) {

		}

		/*!
	   * \param value: valeur à passer à l'uniform
	   * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
	   *
	   */
		virtual void operator=(const double value) {

		}

		/*!
	   * \param value: valeur à passer à l'uniform
	   * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
	   *
	   */
		virtual void operator=(const glm::vec2 &value) {

		}

		/*!
	   * \param value: valeur à passer à l'uniform
	   * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
	   *
	   */
		virtual void operator=(const glm::vec3 &value) {

		}

		/*!
	   * \param value: valeur à passer à l'uniform
	   * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
	   *
	   */
		virtual void operator=(const glm::mat3 &value) {

		}

		/*!
	   * \param value: valeur à passer à l'uniform
	   * \brief l'opérateur = a été surchargé pour permettre d'écrire uni = value
	   *
	   */
		virtual void operator=(const bool value) {

		}

		virtual void operator=(const glm::mat4 &value) {

		}

		virtual void operator=(const glm::mat2 &value) {

		}

		virtual void operator=(const glm::vec4 &value) {

		}

	protected:
		UniBase() = default;
	};
}
#endif //INC_2DENGINE_UNIBASE_H
