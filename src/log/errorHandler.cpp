//
// Created by joe on 23/09/18.
//

#include <glish3/log/errorHandler.hpp>
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
}
