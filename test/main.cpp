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
#include <glish3/texture2d.hpp>

using namespace glish3;
void set_view_uniform(ProgramGL const& program_gl, int width, int height){
    if (width == 0 && height == 0) {
        return;
    }
    float const view[]={
        2.0f/
        static_cast<float>(width), 0, 0,
        0, 2.0f/static_cast<float>(height), 0,
        0, 0, 1
    };
    program_gl["view"] = view;
}
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

	glish3::Texture2D texture = glish3::Texture2D::readImage("black_hole.jpg");
	texture.bind(0);
	//glish3::Shader geo = glish3::Shader::createShaderFromFile(GL_GEOMETRY_SHADER,
	//		"geometry.glsl");
	glish3::ProgramGL programGL{vertex/*, geo*/, frag};
	programGL.use();
	SDL_Event ev;
	glish3::Vao vao;

	float square[]={
			-0.5, 0.5, 0, 0,
			-0.5, -0.5, 0, 1,
			0.5, 0.5, 1, 0,
			0.5, -0.5, 1, 1
	};
    vao.bind();
	//VBO
    vao.add_vbo(buffer(GL_ARRAY_BUFFER,
                       square),
                glish3::attrib_settings(2, 0, 4, 0),
                glish3::attrib_settings(2, 1, 4, 2));
    set_view_uniform(programGL, width, height);


    GLuint values[]={
            4, 1, 0, 1
    };

    buffer indirect_draw(GL_DRAW_INDIRECT_BUFFER, values);
    indirect_draw.bind();

    bool run = true;
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
                case SDL_WINDOWEVENT:

                    if (ev.window.event == SDL_WINDOWEVENT_RESIZED) {

                        width = ev.window.data1;
                        height = ev.window.data2;
                        set_view_uniform(programGL, width, height);
                    }
                    break;
			}
		}

        glDrawArraysIndirect(GL_TRIANGLE_STRIP, (void*)0);
		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}