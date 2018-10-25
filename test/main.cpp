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

template <class T>
concept bool Vertices =
		std::is_same_v<decltype(T::x), decltype(T::y)> &&
		std::is_same_v<decltype(T::y), decltype(T::z)>;
template <class T>
concept bool Vertices2 =
		std::is_same_v<decltype(T::x), decltype(T::y)>;

template <class T>
struct trait;

template<Vertices V>
struct trait<V>{
	static int constexpr a = 3;
};
template<Vertices2 V>
struct trait<V>{
	static int constexpr a = 2;
};
template <class T>
int returnTrait(T){
	return trait<T>::a;
}

template<template<class, class...>class  Container, class U, class ...Ts>
		concept bool ContinuousContainer = requires (Container<U, Ts...> a){
{a[0]} -> U;
		};



 template<template<class...> class T, class U, class ...Ts>
 void f(T<U, Ts ...>&&) requires ContinuousContainer<T, U, Ts...>{}
 using namespace glish3;
int main() {

	SDL_Window * window = nullptr;
	SDL_GLContext  context = nullptr;
	glish3::init("../logTest", "testProject");

	int constexpr width = 768;
	int constexpr height = 768;
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
	glish3::Shader vertex = glish3::Shader::createShaderFromFile(GL_VERTEX_SHADER, "../test/vert.glsl");
	glish3::Shader frag = glish3::Shader::createShaderFromFile(GL_FRAGMENT_SHADER,
															   "../test/frag.glsl");
	glish3::Shader geo = glish3::Shader::createShaderFromFile(GL_GEOMETRY_SHADER,
			"../test/geometry.glsl");
	glish3::ProgramGL programGL{vertex, geo, frag};
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
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glishBindBuffer(GL_ARRAY_BUFFER, vbo);
	glishBufferData(GL_ARRAY_BUFFER, square.size()*sizeof(glm::vec2),
	square.data(), GL_STATIC_DRAW);
	glishEnableVertexAttribArray(0);
	glishVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	f(std::vector<glm::vec2>());
	std::cout <<returnTrait(glm::vec2());
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
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}