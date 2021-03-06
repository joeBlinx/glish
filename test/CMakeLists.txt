add_executable(sample_test)


target_sources(sample_test PRIVATE main.cpp)

target_link_libraries(sample_test PRIVATE glish3 CONAN_PKG::glfw CONAN_PKG::glm CONAN_PKG::glew)
file(GLOB shaders shaders/*.glsl)

add_custom_command(TARGET sample_test POST_BUILD
        COMMAND cmake -E copy_if_different
        ${shaders}
        $<TARGET_FILE_DIR:sample_test>
        )

file(GLOB _images images/*)
add_custom_command(TARGET sample_test POST_BUILD
        COMMAND cmake -E copy_if_different
        ${_images} $<TARGET_FILE_DIR:sample_test>
        )
file(GLOB _binaries ${CMAKE_BINARY_DIR}/bin/*)

if( NOT _binaries STREQUAL "")
    add_custom_command(TARGET sample_test POST_BUILD
        COMMAND cmake -E copy_if_different
         ${_binaries} $<TARGET_FILE_DIR:sample_test>)
endif()
set_target_properties(sample_test PROPERTIES
        CXX_STANDARD 20)