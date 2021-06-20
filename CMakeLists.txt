cmake_minimum_required(VERSION 3.7)
project(glish3)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HPP_FILES inc/glish3/*.hpp inc/glish3/*.tpp)
file(GLOB_RECURSE CPP_FILES src/*.cpp)

set(SOURCE_FILES ${HPP_FILES} ${CPP_FILES} )
# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
	message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
	file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
			"${CMAKE_BINARY_DIR}/conan.cmake"
			TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(REQUIRES glm/0.9.9.8
		stb/20200203
		BASIC_SETUP CMAKE_TARGETS
		BUILD missing)

if(WIN32) # do it again, it sucks
	MESSAGE("OS is Windows")
	add_compile_options(/Wall)
else(WIN32)
	MESSAGE("OS is not WINDOWS")
	add_compile_options(-Wall -pedantic -Wextra -fconcepts )

endif(WIN32)

add_library(glish3 STATIC ${SOURCE_FILES})
add_subdirectory(utils)
add_dependencies(glish3 utils)


target_link_libraries(glish3 PUBLIC utils CONAN_PKG::stb)
target_include_directories(glish3 PUBLIC inc utils/inc)
execute_process(COMMAND ${CMAKE_HOME_DIRECTORY}/headerGeneration glish3
		WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/inc)
install(
		TARGETS glish3
		ARCHIVE DESTINATION lib
)
install(
		DIRECTORY inc/glish3
		DESTINATION include
)
