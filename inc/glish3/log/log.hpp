//
// Created by joe on 23/09/18.
//

#ifndef GLISH3_LOG_HPP
#define GLISH3_LOG_HPP

#include <fstream>
struct Log{

	Log(const std::string &path);

	void info(const std::string &info);

	void warning(const std::string &warn);

	void error(const std::string &error);

	~Log();

private:
	std::ofstream stream;
	std::string time;
	void initHTML();
};
#endif //GLISH3_LOG_HPP
