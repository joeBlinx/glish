#[[
    Find glish to be able to use find_package
]]


if(NOT EXIST GLISH_ROOT)
    if(UNIX)
        set(GLISH_ROOT /usr)
    endif()
endif()

find_library(glish_lib
        NAMES glish
        PATHS ${GLISH_ROOT}/lib
)
if(${glish_lib} STREQUAL "glish_lib-NOTFOUND")
    message(SEND_WARNING "glish library has not been found. You can specified a custom root directory by specifying a GLISH_ROOT variable")
endif()

add_library(glish STATIC IMPORTED GLOBAL)
add_library(gl::ish ALIAS glish)
set_target_properties(glish PROPERTIES
        IMPORTED_LOCATION ${glish_lib}
        )

target_include_directories(glish INTERFACE ${GLISH_ROOT}/include)

set(glish_FOUND 1)