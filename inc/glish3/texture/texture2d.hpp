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
#include "texture_base.hpp"

namespace glish3 {
	struct deleter
	{
		void operator()(void * surface)
		{
			stbi_image_free(surface);
		}
	};

class texture2d: public texture_base {
	public:

        static GLenum constexpr target = GL_TEXTURE_2D;
        struct settings{
	        int width;
	        int height;
	        std::unique_ptr<void, deleter> data;

        };
        texture2d() = default;
		texture2d(const settings &settings);


		static settings readImage(const std::string &path);
		GLenum get_target() const override{return target;}
	};
}


#endif //TESTGLISH3_TEXTURE_HPP
