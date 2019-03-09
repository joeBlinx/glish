//
// Created by joe on 2/13/19.
//

#include <glish3/texture2d.hpp>

#include "glish3/texture2d.hpp"

#include <glish3/glfunction.hpp>
#include <SDL2/SDL_image.h>

namespace glish3 {
	Texture2D::Texture2D(const texture_settings &settings) {

		glishGenTextures(1, &textureId);
		bind();
		glishTexImage2D(target, 0, GL_RGBA, settings.width,
				settings.height,
				0, GL_RGBA, GL_UNSIGNED_BYTE,
				settings.data);

		glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	}

	void Texture2D::bind() {
		glishBindTextures(target, textureId);
	}

	void Texture2D::activeTexture(int id) {

		glishActiveTexture(GL_TEXTURE0 + id);
		bind();
	}

	Texture2D::~Texture2D() {
		if(textureId) {
			glishDeleteTextures(1, &textureId);
			textureId = 0;
		}

	}

	Texture2D::Texture2D(Texture2D &&rhs) :textureId(rhs.textureId){
		rhs.textureId = 0;
	}

	Texture2D &Texture2D::operator=(Texture2D &&rhs) {
		textureId = rhs.textureId;
		rhs.textureId = 0;

		return *this;
	}

	texture_settings Texture2D::readImage(const std::string &path) {

		SDL_Surface * image = IMG_Load(path.c_str());
		texture_settings textureSettings{image->w, image->h, image->pixels, decltype(texture_settings::surface)(image) };
		return textureSettings;
	}
}
