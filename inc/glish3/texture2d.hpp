//
// Created by joe on 2/13/19.
//

#ifndef TESTGLISH3_TEXTURE_HPP
#define TESTGLISH3_TEXTURE_HPP

#include <glish3/gl_glew.hpp>
namespace glish3 {
	struct texture_settings
	{
		int width;
		int height;
		void * data;

	};
	class Texture2D {

		GLuint textureId = 0;
		static GLenum constexpr target = GL_TEXTURE_2D;

	public:
		Texture2D() = default;
		Texture2D(const texture_settings &settings);

		void bind();

		void activeTexture(int id);

		Texture2D(Texture2D const &) = delete;

		Texture2D &operator=(Texture2D const &) = delete;

		Texture2D(Texture2D  && rhs) ;

		Texture2D &operator=(Texture2D && rhs);

		~Texture2D();
	};
}


#endif //TESTGLISH3_TEXTURE_HPP
