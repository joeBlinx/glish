//
// Created by joe on 2/13/19.
//

#ifndef TESTGLISH3_TEXTURE_HPP
#define TESTGLISH3_TEXTURE_HPP

#include <GL/glew.h>
#include <string>
#include <memory>
#include <stb_image.h>
#include "glish3/gl_memory/unique_texture.hpp"

namespace glish3 {
	struct deleter
	{
		void operator()(void * surface)
		{
			stbi_image_free(surface);
		}
	};

	class texture2d {

		UniqueTexture _texture_id = 0;
		static GLenum constexpr target = GL_TEXTURE_2D;

	public:
	    struct settings{
	        int width;
	        int height;
	        std::unique_ptr<void, deleter> data;

        };
		texture2d() = default;
		texture2d(const settings &settings);

		void bind(int binding_point) const;

		static settings readImage(const std::string &path);

	};
}


#endif //TESTGLISH3_TEXTURE_HPP
