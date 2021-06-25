//
// Created by joe on 23/09/18.
//

#include <glish3/log/log.hpp>
#include <ctime>
#include <utils/stringUtil.h>

#include <glish3/log/log.hpp>
#include <ctime>
#include <utils/stringUtil.h>
#include <iostream>
#include <filesystem>

Log::Log(const std::string &path, std::string const &project) :_project(project){

	std::time_t result = std::time(nullptr);
	_time = std::asctime(std::localtime(&result));
	std::string filePath = _time;
	utils::replace(filePath, " ", "_");
	utils::replace(filePath, ":", "_");
	_stream = std::ofstream(path + "/" + filePath +".html");
	if(!_stream.is_open()){
		_stream = std::ofstream("logTest.txt");
		_stream << "path given is invalid : " << path << std::endl;
		fileNotFound(path);
		_stream.close();
	}else{
		initHTML();
	}


}

void Log::info(const std::string &info) {
	_stream << "[INFO]: " << info << std::endl;
}

void Log::warning(const std::string &warn) {
	_stream << "<p><span class = \"warning\">\n"
			  "\t[WARNING]: </span> "<< warn<< "</p>" << std::endl;
}

void Log::error(const std::string &error) {
	_stream << "<p><span class = \"error\">\n"
		   "\t[ERROR]: </span> "<< error<< "</p>" << std::endl;
}

Log::~Log() {

	_stream << "\n </body> \n </html>";
}

void Log::initCSS() {

	_stream << "<style> \n"
		   "div.center{\n "
	 "\ttext-align :center\n}\n"
  ".error{\n "
  "\tcolor :red}\n"
			  ".warning{\n "
			  "\tcolor :yellow}\n"
			  "</style>\n";
}

void Log::initHTML() {
	_stream << "<html> \n <head> \n <title>" << _time << "\n</title> \n </head>" <<std::endl;
	_stream << "<body>";
	initCSS();
	_stream << "<div class = \"center\">\n"
		   "<h1> " << _time  << "\n"
							 "</h1> \n"<<
		"<h2>Project : " << _project << "</h2>\n</div>";
}

bool Log::isInit() const {
	return _init;
}

void Log::title(const std::string &title) {
	_stream << "<h4> " << title << "</h4>";
}

void Log::fileNotFound(const std::string &file) {
	std::string warn{"file not found : \""};
	warn += file + std::string("\"");
	warn += "<br/> Working directory is :";
	//warn += std::filesystem::current_path();
	warning(warn);
}

