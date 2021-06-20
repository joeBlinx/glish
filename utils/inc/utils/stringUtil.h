//
// Created by stiven on 17-09-29.
//

#ifndef GLENGINE_STRINGUTIL_H
#define GLENGINE_STRINGUTIL_H

#include <string>
#include <vector>
namespace utils{
    extern std::string extractExtension(std::string const & path);
    extern std::string extractPath(std::string const & path);
    extern std::string extractFile(std::string const & path);
	extern std::vector<std::string> split(std::string const & str, char delimiter);
	extern std::string removeChar(std::string str, char toRemove);
	// change only the letter
	extern std::string toLowerCase(std::string &&str);
	extern std::string toUpperCase(std::string &str);
	extern void replace(std::string & str, std::string && oldStr, std::string && newStr);
	extern void cleanPath(std::string &path);
	extern void advanceWhile(const char **data, char charToEscape);
}

#endif //GLENGINE_STRINGUTIL_H
