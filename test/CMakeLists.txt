add_executable(sample_test)


target_sources(sample_test PRIVATE main.cpp)
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(sample_test PRIVATE glish3 SDL2::SDL2 SDL2::SDL2main)
file(GLOB shaders *.glsl)

add_custom_target(shaders_copy
        COMMAND cmake -E copy_if_different
        ${shaders}
        ${CMAKE_CURRENT_BINARY_DIR}
        )

add_dependencies(sample_test shaders_copy)
add_custom_command(TARGET sample_test POST_BUILD
        COMMAND cmake -E copy_if_different
        ${CMAKE_CURRENT_LIST_DIR}/black_hole.jpg $<TARGET_FILE_DIR:sample_test>
        )

set_target_properties(sample_test PROPERTIES
        CXX_STANDARD 20)
target_compile_options(sample_test PRIVATE -fconcepts)