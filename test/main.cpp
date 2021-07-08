//
// Created by joe on 23/09/18.
//
#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <utils/stringUtil.h>
#include "glish3/log/errorHandler.hpp"
#include "glish3/shader.hpp"
#include "glish3/Vao.hpp"
#include "glish3/programGL.hpp"

using namespace glish3;

int main() {

	SDL_Window * window = nullptr;
	SDL_GLContext  context = nullptr;

	int width = 768;
	int height = 768;
// INIT SDL et GL
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		throw std::runtime_error("error while initialize SDL2 " + std::string{SDL_GetError()});
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window = SDL_CreateWindow("test",
	        SDL_WINDOWPOS_CENTERED,
	        SDL_WINDOWPOS_CENTERED,
	        width, height,
	        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

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
	glish3::use_debug_output();

// Init code outside the scope of OpenGL API
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
// END Init
	glish3::Shader const vertex = glish3::Shader::createShaderFromFile(GL_VERTEX_SHADER, "vert.glsl");
	glish3::Shader const frag = glish3::Shader::createShaderFromFile(GL_FRAGMENT_SHADER,
															   "frag.glsl");
    auto const program_gl = glish3::ProgramGL::create_program(
            vertex, frag
            );
    program_gl.use();

    struct vec4{
        float a,b,c,d;
    };
    GLfloat const vertices[]={0.25, -0.25, 1, 1.0,
                                -0.25, -0.25, 1, 1.0,
                                0.25, 0.25, 1, 1.0};

    GLfloat const vertices2[]={0.25, -0.50, 1, 1.0,
                              -0.25, -0.25, 1, 1.0,
                              0.25, 0, 1, 1.0};

    glish3::Vao vao(program_gl);
    vao.set_attrib(glish3::Format<vec4>{.index_names{"pos"},
                                                    .size_of_data{4}});

    vao.add_vbo(glish3::buffer(vertices), 0);
    vao.add_vbo(glish3::buffer(vertices2), 1);

    vao.bind_vbo("pos", 1);
    vao.bind();
	SDL_Event ev;

	GLfloat const colors[] = {0.5, 0.8, 0.2, 1};

	glish3::buffer block(colors);
	block.bind_base(GL_UNIFORM_BUFFER, 0);
    bool run = true;
    float tess_level = 1.0f;
	while(run){
	    GLfloat constexpr clear_color[] = {
	            0.5, 0.5, 0.5, 1
	    };
	    GLfloat constexpr clear_depth = 0;
		glClearBufferfv(GL_COLOR, 0, clear_color);
		while(SDL_PollEvent(&ev)){
			switch(ev.type){
				case SDL_KEYDOWN:
					if(ev.key.keysym.sym == SDLK_ESCAPE) {
					   run = false;
					   break;
					}else if(ev.key.keysym.sym == SDLK_e){
					    vao.bind_vbo("pos", 0);
					}
					break;
				case SDL_QUIT:
					run = false;
					break;
			}
		}
        glDrawArrays(GL_TRIANGLES, 0, 3);
		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}