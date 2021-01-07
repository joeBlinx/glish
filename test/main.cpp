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
#include <glm/vec2.hpp>
#include <vector>
#include <glish3/uniform.hpp>
#include <map>

using namespace glish3;
int main() {

	SDL_Window * window = nullptr;
	SDL_GLContext  context = nullptr;
	glish3::init("../logTest", "testProject");

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
// Init code outside the scope of OpenGL API
	glishClearColor(0.5, 0.5, 0.5, 1);
	glishEnable (GL_BLEND);
	glishBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
// END Init
	glish3::Shader vertex = glish3::Shader::createShaderFromFile(GL_VERTEX_SHADER, "../test/vert_no_sprite.glsl");
	glish3::Shader frag = glish3::Shader::createShaderFromFile(GL_FRAGMENT_SHADER,
															   "../test/frag_no_sprite.glsl");
	glish3::Shader geo = glish3::Shader::createShaderFromFile(GL_GEOMETRY_SHADER,
			"../test/geometry.glsl");
	glish3::ProgramGL programGL{vertex/*, geo*/, frag};
	programGL.use();
	SDL_Event ev;
	Vao vao;

	std::vector<glm::vec2> square{
			{-0.5, 0.5},
			{-0.5, -0.5},
			{0.5, 0.5},
			{0.5, -0.5}
	};

	//VBO
	Vbo vbo(GL_ARRAY_BUFFER);
	glishBufferData(GL_ARRAY_BUFFER, square.size()*sizeof(glm::vec2),
	square.data(), GL_STATIC_DRAW);
	glishEnableVertexAttribArray(0);
	glishVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);


	bool run = true;

	float pos[] = {0, 0};
	float size [] = {1/6.0f, 1/6.0f};
	programGL["size"] = &size;
	programGL["posChange"] = &pos;
	float test [2] = {0, 0};
	int mouse_x, mouse_y;
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
		*test+=0.1;
		SDL_Delay(100);
		if(*test > 1){
			*test = 0;
		}
		float constexpr tile = 10.0f;
		SDL_GetMouseState(&mouse_x, &mouse_y);
		std::cout << mouse_x <<std::endl;
		mouse_x = -1+ 2.0f*(float)mouse_x/width;
		mouse_y = -1*(-1+ 2.0f*mouse_y/height);
		std::cout << mouse_x <<std::endl;
	//	programGL["col"] = &test;
		for(int i = 0; i < tile; i++){
			for(int j = 0; j < tile; j++){
				pos[0] = -1 +1/tile + i*2/tile;
				pos[1] = -1 +1/tile + j*2/tile;
				int is_select = 0;
				
				if(mouse_x > pos[0] - size[0] && mouse_x < pos[0] + size[0] ){
					is_select = 1;
					
				}
				programGL["is_select"] = &is_select;
				programGL["posChange"] = &pos;
				glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
			}
		}

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}