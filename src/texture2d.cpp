//
// Created by joe on 2/13/19.
//

#include "glish3/texture2d.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
namespace glish3 {
	Texture2D::Texture2D(const texture_settings &settings) {
        GLuint texture_id{};
		glGenTextures(1, &texture_id);
        _texture_id = UniqueTexture(texture_id);
		bind();

        glTexImage2D(target, 0, GL_RGBA, settings.width,
                        settings.height,
                        0, GL_RGBA, GL_UNSIGNED_BYTE,
                        settings.data.get());

		glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	}

	void Texture2D::bind() {
		glBindTexture(target, _texture_id.get());
	}

	void Texture2D::activeTexture(int id) {
		glActiveTexture(GL_TEXTURE0 + id);
		bind();
	}


	texture_settings Texture2D::readImage(const std::string &path) {

		int width{}, height{}, nb_chan{};
        auto data = stbi_load(path.c_str(), &width, &height, &nb_chan, 4);
		texture_settings textureSettings{width, height, decltype(texture_settings::data)(data)};
		return textureSettings;
	}
}
