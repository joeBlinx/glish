//
// Created by joe on 2/13/19.
//

#include "glish3/texture2d.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <sstream>
#include <filesystem>

namespace glish3 {
	Texture2D::Texture2D(const texture_settings &settings):_texture_id(make_unique_texture(GL_TEXTURE_2D)) {

        glTextureStorage2D(_texture_id.get(), 1, GL_RGBA8, settings.width, settings.height);
        glTextureSubImage2D(_texture_id.get(),
                0, 0, 0,
                settings.width, settings.height,
                GL_RGBA, GL_UNSIGNED_BYTE,
                settings.data.get());
	}

	void Texture2D::bind(int binding_point) const {
	    glBindTextureUnit(binding_point, _texture_id.get());
	}

	texture_settings Texture2D::readImage(const std::string &path) {

		int width{}, height{}, nb_chan{};
        auto data = stbi_load(path.c_str(), &width, &height, &nb_chan, 4);
        if(!data){
            std::stringstream error_message;
            error_message << "File: " << path << " not found. cwd is " << std::filesystem::current_path();
            std::string error = error_message.str();
            glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION,
                                 GL_DEBUG_TYPE_ERROR,
                                 0, GL_DEBUG_SEVERITY_HIGH,
                                 static_cast<GLsizei>(error.size()),
                                 error.c_str());
        }
		texture_settings textureSettings{width, height, decltype(texture_settings::data)(data)};
		return textureSettings;
	}
}
