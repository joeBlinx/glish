//
// Created by joe on 23/09/18.
//
#define SDL_MAIN_HANDLED
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
#include "glish3/log/errorHandler.hpp"
#include "glish3/shader.hpp"
#include "glish3/Vao.hpp"
#include "glish3/programGL.hpp"
#include "glish3/texture2d.hpp"
#include "glish3/program_pipeline.hpp"

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
	int major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    std::cout << major << '.' << minor << '\n';
// Init code outside the scope of OpenGL API
	glClearColor(0.5, 0.5, 0.5, 1);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
// END Init
	glish3::Shader const vertex = glish3::Shader::createShaderFromFile(GL_VERTEX_SHADER, "vert.glsl");
	glish3::Shader const frag = glish3::Shader::createShaderFromFile(GL_FRAGMENT_SHADER,
															   "frag.glsl");
    glish3::Shader const tess_eval = glish3::Shader::createShaderFromFile(GL_TESS_EVALUATION_SHADER, "tess_eval.glsl");
    glish3::Shader const tess_control = glish3::Shader::createShaderFromFile(GL_TESS_CONTROL_SHADER, "tess_control.glsl");
    glish3::Shader const geometry = glish3::Shader::createShaderFromFile(GL_GEOMETRY_SHADER, "geometry.glsl");


    auto const program_gl = glish3::ProgramGL::create_program(
            vertex, tess_control, tess_eval, geometry, frag
            );
    program_gl.use();

    GLfloat const vertices[]={0.25, -0.25, 0.5, 1.0,
                                -0.25, -0.25, 0.5, 1.0,
                                0.25, 0.25, 0.5, 1.0};

    glish3::Vao vao;
    vao.bind();
    vao.add_vbo(glish3::buffer(vertices), 4, glish3::attrib_settings(4, 1));
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    glPatchParameteri(GL_PATCH_VERTICES, 3);
	SDL_Event ev;
    glPointSize(5.0f);
    bool run = true;
    float tess_level = 1.0f;
	while(run){
		glClear(GL_COLOR_BUFFER_BIT);
		while(SDL_PollEvent(&ev)){
			switch(ev.type){
				case SDL_KEYDOWN:
					if(ev.key.keysym.sym == SDLK_ESCAPE) {
					    tess_level += 1.f;
					}
					break;
				case SDL_QUIT:
					run = false;
					break;
                case SDL_WINDOWEVENT:

                    if (ev.window.event == SDL_WINDOWEVENT_RESIZED) {

                        width = ev.window.data1;
                        height = ev.window.data2;
                        std::cout << "width: " << width << " height: " << height << "\n";
                        //set_view_uniform(programGLvertex, width, height);
                    }
                    break;
			}
		}
        glVertexAttrib1f(0, tess_level);
        glDrawArrays(GL_PATCHES, 0, 3);
		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}