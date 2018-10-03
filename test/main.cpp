//
// Created by joe on 23/09/18.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <ctime>
#include <utils/stringUtil.h>
#include <glish3/glish3.hpp>

int main() {

	SDL_Window * window = nullptr;
	SDL_GLContext  context = nullptr;
	glish3::init("../logTest", "testProject");

	int constexpr width = 1366;
	int constexpr height = 768;
// INIT SDL et GL
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		throw std::runtime_error("error while initialize SDL2 " + std::string{SDL_GetError()});
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	if(!window){
		std::string erreur {SDL_GetError()};
		SDL_Quit();
		throw std::runtime_error("error while initialize window "+ erreur);
	}

	context = SDL_GL_CreateContext(window);
	glewExperimental = GL_TRUE;
	auto err = glewInit();
	if(err!= GLEW_OK){
		std::cerr << glewGetErrorString(err) << std::endl;
		throw std::runtime_error("error while initialize glew" );
	}
	glGetError();
// Init code outside the scope of OpenGL API
	glishClearColor(0.5, 0.5, 0.5, 1);
	glishEnable (GL_BLEND);
	glishBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
// END Init
	glish3::Shader vertex = glish3::Shader::createShaderFromFile(GL_VERTEX_SHADER, "../test/vert.glsl");
	glish3::Shader frag = glish3::Shader::createShaderFromData(GL_FRAGMENT_SHADER,
															   "#version 330\n"
				  "void main(){}");
	glish3::ProgramGL programGL{vertex, frag};
	SDL_Event ev;
	bool run = true;
	while(run){
		glishClear(GL_COLOR_BUFFER_BIT);
		while(SDL_PollEvent(&ev)){
			switch(ev.type){
				case SDL_KEYDOWN:
					if(ev.key.keysym.sym == SDLK_ESCAPE) {
						run = false;
					}
					break;
				case SDL_QUIT:
					run = false;
					break;
			}
		}

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}