//
// Created by joe on 2/13/19.
//

#include "glish3/texture/texture2d.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <sstream>
#include <filesystem>

namespace glish3 {
    texture2d::texture2d(const settings &settings): _texture_id(make_unique_texture(target)) {

        glTextureStorage2D(_texture_id.get(), 1, GL_RGBA8, settings.width, settings.height);
        glTextureSubImage2D(_texture_id.get(),
                0, 0, 0,
                settings.width, settings.height,
                GL_RGBA, GL_UNSIGNED_BYTE,
                settings.data.get());
	}

	void texture2d::bind(int binding_point) const {
	    glBindTextureUnit(binding_point, _texture_id.get());
	}

	texture2d::settings texture2d::readImage(const std::string &path) {

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
        return {width, height, decltype(settings::data)(data)};
	}
}
