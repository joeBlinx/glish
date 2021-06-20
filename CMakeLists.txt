cmake_minimum_required(VERSION 3.12)
project(glish3)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

include(dependencies)
add_subdirectory(utils)

add_library(glish3 STATIC)

if(WIN32)
	target_compile_options(glish3 PRIVATE /Wall)
else()
	target_compile_options(glish3 PRIVATE -Wall -pedantic -Wextra -fconcepts )
endif()

target_link_libraries(glish3 PUBLIC utils CONAN_PKG::stb)
target_include_directories(glish3 PUBLIC inc)
target_compile_features(glish3 PRIVATE cxx_std_20)

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
		inc/glish3/glish3.hpp
		inc/glish3/programGL.hpp
		inc/glish3/shader.hpp
		inc/glish3/uniform.hpp
		inc/glish3/glfunction.hpp
		inc/glish3/Vbo.hpp

		src/programGL.cpp
		src/log/errorHandler.cpp
		src/log/log.cpp
		src/shader.cpp
		src/Vbo.cpp

		)