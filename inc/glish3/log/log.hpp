//
// Created by joe on 23/09/18.
//

#ifndef GLISH3_LOG_HPP
#define GLISH3_LOG_HPP

#include <fstream>

struct Log{

	Log() = default;
	Log(const std::string &path, std::string const &project = "undefined");

	void info(const std::string &info);

	void warning(const std::string &warn);

	void error(const std::string &error);

	Log(Log&&) = default;
	Log&operator=(Log&&) = default;
	~Log();

	bool isInit() const;
private:
	std::ofstream stream;
	std::string time;
	std::string project;

	bool init = false;
	void initHTML();
	void initCSS();
};
#endif //GLISH3_LOG_HPP
