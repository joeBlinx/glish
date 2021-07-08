//
// Created by joe on 23/09/18.
//

#include <GL/glew.h>
#include "glish3/log/errorHandler.hpp"
#include <iostream>
#include <string>
#include "glish3/log/log.hpp"
namespace glish3 {
	Log log;
	void init(const std::string &path, const std::string &project) {
		if constexpr (debug) {
			log = Log(path, project);
		}
	}

	std::string createLink(std::string const &functionName) {
		std::string website = "https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/" +
							  functionName + ".xhtml";
		std::string link = "for further information, see :"
					 "<a href=\""+ website +"\" target=\"_blank\" >"+ website +" </a>";
		return link;
	}

	static std::string enum_source_to_string(GLenum source){
	    switch(source){
	        case GL_DEBUG_SOURCE_API:
	            return {"GL_DEBUG_SOURCE_API"};
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
                return {"GL_DEBUG_SOURCE_WINDOW_SYSTEM"};
            case GL_DEBUG_SOURCE_SHADER_COMPILER:
                return {"GL_DEBUG_SOURCE_SHADER_COMPILER"};
            case GL_DEBUG_SOURCE_THIRD_PARTY:
                return {"GL_DEBUG_SOURCE_THIRD_PARTY"};
            case GL_DEBUG_SOURCE_APPLICATION:
                return {"GL_DEBUG_SOURCE_APPLICATION"};
            case GL_DEBUG_SOURCE_OTHER:
                return {"GL_DEBUG_SOURCE_OTHER"};
	    }
        return {};

    }
	static std::string enum_type_to_string(GLenum type){
	    switch(type){
            case GL_DEBUG_TYPE_ERROR:
                return {"GL_DEBUG_TYPE_ERROR"};
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
                return {"GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR"};
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
                return {"GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR"};
            case GL_DEBUG_TYPE_PORTABILITY:
                return {"GL_DEBUG_TYPE_PORTABILITY"};
            case GL_DEBUG_TYPE_PERFORMANCE:
                return {"GL_DEBUG_TYPE_PERFORMANCE"};
            case GL_DEBUG_TYPE_MARKER:
                return {"GL_DEBUG_TYPE_MARKER"};
            case GL_DEBUG_TYPE_PUSH_GROUP:
                return {"GL_DEBUG_TYPE_PUSH_GROUP"};
            case GL_DEBUG_TYPE_POP_GROUP:
                return {"GL_DEBUG_TYPE_POP_GROUP"};
            case GL_DEBUG_TYPE_OTHER:
                return {"GL_DEBUG_TYPE_OTHER"};
	    }
        return {};

    }
	static std::string enum_severity_to_string(GLenum severity){
	    switch(severity) {
            case GL_DEBUG_SEVERITY_HIGH:
                return {"GL_DEBUG_SEVERITY_HIGH"};
            case GL_DEBUG_SEVERITY_MEDIUM:
                return {"GL_DEBUG_SEVERITY_MEDIUM"};
            case GL_DEBUG_SEVERITY_LOW:
                return {"GL_DEBUG_SEVERITY_LOW"};
            case GL_DEBUG_SEVERITY_NOTIFICATION:
                return {"GL_DEBUG_SEVERITY_NOTIFICATION"};
        }
        return {};
	}
	void gl_debug_callback(GLenum source, GLenum type, GLuint,
                                  GLenum severity, GLsizei, const GLchar* message, const void*){
            std::cerr << "GLCALLBACK: \tSource: " << enum_source_to_string(source)
                      << "\n\tType: " << enum_type_to_string(type)
                      << "\n\tSeverity: " << enum_severity_to_string(severity)
                      << "\n\tMessage: " << message << "\n\n";

	}
    void use_debug_output(){
	    glEnable(GL_DEBUG_OUTPUT);
	    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);
        glDebugMessageCallback(gl_debug_callback, nullptr);
	}
}

