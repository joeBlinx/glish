//
// Created by joe on 2/13/19.
//

#ifndef TESTGLISH3_TEXTURE_HPP
#define TESTGLISH3_TEXTURE_HPP

#include <glish3/gl_glew.hpp>
#include <string>
#include <memory>
#include <stb_image.h>
#include <glish3/gl_memory/unique_texture.hpp>

namespace glish3 {
	struct deleter
	{
		void operator()(void * surface)
		{
			stbi_image_free(surface);
		}
	};
	struct texture_settings
	{
		int width;
		int height;
		std::unique_ptr<void, deleter> data;

	};
	class Texture2D {

		UniqueTexture _texture_id = 0;
		static GLenum constexpr target = GL_TEXTURE_2D;

	public:
		Texture2D() = default;
		Texture2D(const texture_settings &settings);

		void bind(int texture_number) const;

		static texture_settings readImage(const std::string &path);

	};
}


#endif //TESTGLISH3_TEXTURE_HPP
