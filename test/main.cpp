//
// Created by joe on 23/09/18.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <ctime>
#include <utils/stringUtil.h>
#include <glm/vec2.hpp>
#include <vector>
#include <glish3/uniform.hpp>
#include <map>
#include <glish3/log/errorHandler.hpp>
#include <glish3/shader.hpp>
#include <glish3/Vao.hpp>
#include <glish3/programGL.hpp>

using namespace glish3;
int main() {

	SDL_Window * window = nullptr;
	SDL_GLContext  context = nullptr;

	float constexpr width = 768;
	float constexpr height = 768;
// INIT SDL et GL
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		throw std::runtime_error("error while initialize SDL2 " + std::string{SDL_GetError()});
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
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
	glish3::use_debug_output();
// Init code outside the scope of OpenGL API
	glClearColor(0.5, 0.5, 0.5, 1);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
// END Init
	glish3::Shader vertex = glish3::Shader::createShaderFromFile(GL_VERTEX_SHADER, "vert.glsl");
	glish3::Shader frag = glish3::Shader::createShaderFromFile(GL_FRAGMENT_SHADER,
															   "frag.glsl");
	//glish3::Shader geo = glish3::Shader::createShaderFromFile(GL_GEOMETRY_SHADER,
	//		"geometry.glsl");
	glish3::ProgramGL programGL{vertex/*, geo*/, frag};
	programGL.use();
	SDL_Event ev;
	glish3::Vao vao;

	std::vector<glm::vec2> square{
			{-0.5, 0.5},
			{-0.5, -0.5},
			{0.5, 0.5},
			{0.5, -0.5}
	};

	//VBO
	GLuint vbo;
	glCreateBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, square.size()*sizeof(glm::vec2),
	square.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);


	bool run = true;

	int mouse_x, mouse_y;
	while(run){
		glClear(GL_COLOR_BUFFER_BIT);
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

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}