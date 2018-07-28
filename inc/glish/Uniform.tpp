//
// Created by stiven on 18/03/16.
//

namespace glish {

	template<typename T>
	void Uniform<T>::operator=(const int value) {
		assert((std::is_same<type, int>::value && "Uniform's type is not int"));
		glUniform1i( uni, value);
		if constexpr (std::is_same<T, int>::value)
			lastValue = value;
		getError();
	}

	template<typename T>
	void Uniform<T>::operator=(const float value) {
		assert((std::is_same<type, float>::value && "Uniform's type is not float"));
		glUniform1f( uni, value);
		if constexpr (std::is_same<T, float>::value)
			lastValue = value;
		getError();
	}

	template<typename T>
	void Uniform<T>::operator=(const double value) {
		assert((std::is_same<type, double>::value && "Uniform's type is not double"));
		glUniform1d( uni, value);
		if constexpr (std::is_same<T, double>::value)
			lastValue = value;
		getError();
	}

	template<typename T>
	void Uniform<T>::operator=(const glm::vec2 &value) {
		assert((std::is_same<type, glm::vec2>::value && "Uniform's type is not glm::vec2"));

		glUniform2fv( uni, 1, glm::value_ptr(value));
		if constexpr (std::is_same<T, glm::vec2>::value)
			lastValue = value;
		getError();
	}

	template<typename T>
	void Uniform<T>::operator=(const glm::vec3 &value) {
		assert((std::is_same<type, glm::vec3>::value && "Uniform's type is not glm::vec3"));
		glUniform3fv( uni, 1, glm::value_ptr(value));
		if constexpr (std::is_same<T, glm::vec3>::value)
			lastValue = value;
		getError();
	}

	template<typename T>
	void Uniform<T>::operator=(const glm::mat3 &value) {
		assert((std::is_same<type, glm::mat3>::value && "Uniform's type is not glm::mat3"));
		glUniformMatrix3fv( uni, 1, GL_FALSE, glm::value_ptr(value));
		if constexpr (std::is_same<T, glm::mat3>::value)
			lastValue = value;
		getError();
	}

	template<typename T>
	void Uniform<T>::operator=(const glm::mat4 &value) {
		assert((std::is_same<type, glm::mat4>::value && "Uniform's type is not glm::mat4"));
		glUniformMatrix4fv( uni, 1, GL_FALSE, glm::value_ptr(value));
		if constexpr (std::is_same<T, glm::mat4>::value)
			lastValue = value;
		getError();

	}

	template<typename T>
	void Uniform<T>::operator=(const bool value) {
		assert((std::is_same<type, bool>::value && "Uniform's type is not bool"));
		glUniform1i( uni, value);
		if constexpr (std::is_same<T, bool>::value)
			lastValue = value;
		getError();
	}

	template<typename T>
	void Uniform<T>::operator=(const glm::mat2 &value) {
		assert((std::is_same<type, glm::mat2>::value && "Uniform's type is not glm::mat2"));
		glUniformMatrix2fv( uni, 1, GL_FALSE, glm::value_ptr(value));
		if constexpr (std::is_same<T, glm::mat2>::value)
			lastValue = value;
		getError();

	}

	template<typename T>
	void Uniform<T>::operator=(const glm::vec4 &value) {
		assert((std::is_same<type, glm::vec4>::value && "Uniform's type is not glm::vec4"));
		glUniform4fv( uni, 1, glm::value_ptr(value));
		if constexpr (std::is_same<T, glm::vec4>::value)
			lastValue = value;
		getError();

	}


}

