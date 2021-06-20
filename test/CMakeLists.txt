add_executable(sample_test)


target_sources(sample_test PRIVATE main.cpp)
target_link_libraries(sample_test PRIVATE glish3 SDL2)
add_custom_command(TARGET sample_test POST_BUILD
        COMMAND cmake -E copy_if_different
            ${CMAKE_CURRENT_LIST_DIR}/vert.glsl
            ${CMAKE_CURRENT_LIST_DIR}/frag.glsl ${CMAKE_CURRENT_BINARY_DIR}
        )