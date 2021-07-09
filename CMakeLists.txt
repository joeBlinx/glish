cmake_minimum_required(VERSION 3.12)
project(glish3)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(dependencies)
add_subdirectory(utils)

find_program(iwyu
		NAMES include-what-you-use iwyu)
if(NOT ${iwyu} STREQUAL "iwyu-NOTFOUND")
	message(STATUS "IWYU: include what you use have been found here \"${iwyu}\" and thus will be used")
	set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE ${iwyu})
endif()

option(BUILD_SAMPLE OFF)
if(${BUILD_SAMPLE})
	add_subdirectory(test)
endif()
add_library(glish3 STATIC)

if(WIN32)
	target_compile_options(glish3 PRIVATE /W4)
else()
	target_compile_options(glish3 PRIVATE -Wall -pedantic -Wextra)
endif()
find_package(OpenGL REQUIRED)
target_link_libraries(glish3 PUBLIC utils CONAN_PKG::stb OpenGL::GL CONAN_PKG::glew)
target_include_directories(glish3 PUBLIC inc)

set_target_properties(glish3 PROPERTIES
		CXX_STANDARD 20
		CXX_EXTENSIONS OFF
		POSITION_INDEPENDENT_CODE ON
		)

install(
		TARGETS glish3
		ARCHIVE DESTINATION lib
)
install(
		DIRECTORY inc/glish3
		DESTINATION include
)

target_sources(glish3
		PRIVATE

		inc/glish3/gl_glew.hpp
		inc/glish3/Vao.hpp
		inc/glish3/log/errorHandler.hpp
		inc/glish3/log/log.hpp
		inc/glish3/texture2d.hpp
		inc/glish3/programGL.hpp
		inc/glish3/program_pipeline.hpp
		inc/glish3/shader.hpp
		inc/glish3/uniform.hpp
        inc/glish3/buffer.hpp
		inc/glish3/gl_memory/unique_vao.hpp
		inc/glish3/gl_memory/unique_buffer.hpp
		inc/glish3/gl_memory/unique_programgl.hpp
		inc/glish3/gl_memory/unique_shader.hpp
		inc/glish3/gl_memory/unique_texture.hpp
		inc/glish3/gl_memory/unique_program_pipeline.hpp

		src/programGL.cpp
		src/program_pipeline.cpp
		src/log/errorHandler.cpp
		src/log/log.cpp
		src/shader.cpp
        src/buffer.cpp
		src/Vao.cpp
		src/texture2d.cpp
		src/uniform.cpp


		)