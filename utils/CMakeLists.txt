cmake_minimum_required(VERSION 3.7)
project(utils)


add_library(utils STATIC)
target_include_directories(utils PUBLIC inc
								PRIVATE inc/utils)
target_link_libraries(utils PUBLIC CONAN_PKG::glm)
target_compile_features(utils PUBLIC cxx_std_17)
if(UNIX)
	target_compile_options(utils PRIVATE -Wall -pedantic -Wextra -fPIC)
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

target_sources(utils PRIVATE
		inc/utils/templateUtils.h
		inc/utils/type_trait.h
		inc/utils/stringUtil.h
		inc/utils/tupleUtils.hpp
		inc/utils/glmAdd.h
		inc/utils/stlUtils.h

		src/stringUtil.cpp
		src/glmAdd.cpp

		)