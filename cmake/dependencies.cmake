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
        glew/2.2.0
        glfw/3.3.4
        OPTIONS glew:shared=True
        glfw:shared=True
        BASIC_SETUP CMAKE_TARGETS
        BUILD missing
        NO_OUTPUT_DIRS
        IMPORTS "bin, *.dll -> ./bin")