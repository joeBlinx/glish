//
// Created by joe on 23/09/18.
//
#define SDL_MAIN_HANDLED
#include <iostream>
#include <GL/glew.h>
#include <utils/stringUtil.h>
#include <glish3/sampler.hpp>
#include "glish3/log/errorHandler.hpp"
#include "glish3/shader.hpp"
#include "glish3/Vao.hpp"
#include "glish3/programGL.hpp"
#include "GLFW/glfw3.h"
#include "glish3/texture/texture2d.hpp"
#include "glish3/texture/texture2d_array.hpp"
#include <array>
using namespace glish3;
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    if(action == GLFW_PRESS){
        if(key == GLFW_KEY_E){
            glVertexAttrib1f(2, 1);
        }
    }
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

    auto const program_gl = glish3::ProgramGL::create_program(
            vertex, frag
            );
    program_gl.use();

    struct Vertex{
        struct Pos{
            float a,b,c,d;
        }pos;
        struct Uv{
            float u, v;
        }uv;
    };
    Vertex const vertices[]={{-1., 1., 1, 1.0, 10., 10.},
                              {-1., -1., 1, 1.0, 10., 11.},
                              {1., 1., 1, 1.0, 11., 10.},
                              {1., -1., 1, 1.0, 11., 11.}};

    glish3::Vao vao(program_gl);
    vao.set_attrib(glish3::Format<Vertex::Pos, Vertex::Uv>{.index_names{"pos", "uv"}});

    vao.add_vbo(glish3::buffer(vertices), 0);

    vao.bind_vbo(0);
    vao.bind();

	GLfloat const colors[] = {0.5, 0.8, 0.2, 1};

	glish3::buffer block(colors);
	block.bind_base(GL_UNIFORM_BUFFER, 0);
    using namespace std::string_view_literals;
    std::string_view paths[]{
        "black_hole.jpg"sv, "yoda.jpeg"sv
    };
    glish3::texture2d_array const textures{texture2d_array::read_images(paths)};

	glish3::sampler const sampler;
	sampler.linear();
    sampler.bind(1);
    glVertexAttrib1f(2, 0);
    sampler.repeat();
    textures.bind(1);

    while(!glfwWindowShouldClose(window)){
        GLfloat constexpr clear_color[] = {
	            0.5, 0.5, 0.5, 1
	    };

        glClearBufferfv(GL_COLOR, 0, clear_color);

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glfwSwapBuffers(window);
        glfwPollEvents();

	}

    glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}