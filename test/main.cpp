//
// Created by joe on 23/09/18.
//
#define SDL_MAIN_HANDLED
#include <iostream>
#include <GL/glew.h>
#include <utils/stringUtil.h>
#include "glish3/log/errorHandler.hpp"
#include "glish3/shader.hpp"
#include "glish3/Vao.hpp"
#include "glish3/programGL.hpp"
#include "GLFW/glfw3.h"
using namespace glish3;
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
int main() {
    glfwInit();
    int height = 768;
    int width = 768;

    GLFWwindow * window = glfwCreateWindow(width, height, "test", nullptr, nullptr);
    glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glfwSetKeyCallback(window, key_callback);
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
	auto const counter_frag = Shader::createShaderFromFile(GL_FRAGMENT_SHADER, "frag_counter.glsl");
    auto const program_gl = glish3::ProgramGL::create_program(
            vertex, frag
            );
    auto const program_counter = ProgramGL::create_program(vertex, counter_frag);
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

	GLfloat const colors[] = {0.5, 0.8, 0.2, 1};

	glish3::buffer block(colors);
	block.bind_base(GL_UNIFORM_BUFFER, 0);

	glish3::buffer atomic_counter;
	GLuint constexpr count = 0;
	atomic_counter.allocate(&count, 1, GL_DYNAMIC_STORAGE_BIT);

    bool run = true;
    float tess_level = 1.0f;
    while(!glfwWindowShouldClose(window)){
	    GLfloat constexpr clear_color[] = {
	            0.5, 0.5, 0.5, 1
	    };
	    GLfloat constexpr clear_depth = 0;
	    atomic_counter.sub_data(0, 1, &count);
	    atomic_counter.bind_base(GL_ATOMIC_COUNTER_BUFFER, 1);
		glClearBufferfv(GL_COLOR, 0, clear_color);
			/*switch(ev.type){
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
			}*/
		program_counter.use();
		glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glMemoryBarrier(GL_UNIFORM_BARRIER_BIT);
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
        atomic_counter.bind_base(GL_UNIFORM_BUFFER, 2);
		program_gl.use();
		
		glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();

	}

    glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}