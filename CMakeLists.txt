cmake_minimum_required(VERSION 3.7)
project(glish3)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HPP_FILES inc/glish3/*.hpp inc/glish3/*.tpp)
file(GLOB_RECURSE CPP_FILES src/*.cpp)

set(SOURCE_FILES ${HPP_FILES} ${CPP_FILES} )


include_directories(BEFORE_SYSTEM PRIVATE inc)


if(WIN32) # do it again, it sucks
	MESSAGE("OS is Windows")
	add_compile_options(/Wall)
else(WIN32)
	MESSAGE("OS is not WINDOWS")
    add_compile_options(-Wall -pedantic -Wextra)

endif(WIN32)

add_library(glish3 STATIC ${SOURCE_FILES})
add_subdirectory(utils)
add_dependencies(glish3 utils)


target_link_libraries(glish3 PUBLIC utils)

install(
        TARGETS glish3
        ARCHIVE DESTINATION lib
)
install(
        DIRECTORY inc/glish3
        DESTINATION include
)

add_executable(testProject test/main.cpp)
add_dependencies(testProject glish3)
target_link_libraries(testProject glish3 GL GLU SDL2 GLEW )