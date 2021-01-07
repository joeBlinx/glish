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

	void title(const std::string &title);

	void fileNotFound (const std::string & file);

	Log(Log&&) = default;
	Log&operator=(Log&&) = default;
	~Log();

	bool isInit() const;
private:
	std::ofstream _stream;
	std::string _time;
	std::string _project;

	bool _init = false;
	void initHTML();
	void initCSS();
};
#endif //GLISH3_LOG_HPP
