cmake_minimum_required(VERSION 3.7)
project(utils)

set(CMAKE_CXX_STANDARD 17)




file(GLOB_RECURSE HPP_FILES inc/utils/*.h inc/utils/*.tpp)
file(GLOB_RECURSE CPP_FILES src/*.cpp)

set(SOURCE_FILES ${HPP_FILES} ${CPP_FILES} inc/utils/tupleUtils.hpp)

include_directories(BEFORE_SYSTEM PRIVATE inc )
include_directories(BEFORE_SYSTEM PRIVATE inc/utils)

add_library(utils SHARED ${SOURCE_FILES})
target_link_libraries(utils PUBLIC CONAN_PKG::glm)
if(!WIN32)
	add_compile_options(-Wall -pedantic -Wextra -fPIC)
else(!WIN32)
	add_compile_options("/std:c++latest")
endif()


install(
		TARGETS utils
		ARCHIVE DESTINATION lib
		LIBRARY DESTINATION lib
)
install(
		DIRECTORY inc/utils
		DESTINATION include
)
