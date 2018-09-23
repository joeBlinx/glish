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

Log::Log(const std::string &path, std::string const &project) :project(project){

	std::time_t result = std::time(nullptr);
	time = std::asctime(std::localtime(&result));
	std::string filePath = time;
	utils::replace(filePath, " ", "_");
	utils::replace(filePath, ":", "_");
	stream = std::ofstream(path + "/" + filePath +".html");
	if(!stream.is_open()){
		stream = std::ofstream("log.txt");
		stream << "path given is invalid : " << path << std::endl;
		stream.close();
	}else{
		initHTML();
	}


}

void Log::info(const std::string &info) {
	stream << "[INFO]: " << info << std::endl;
}

void Log::warning(const std::string &warn) {
	stream << "<p><span class = \"warning\">\n"
			  "\t[WARNING]: </span> "<< warn<< "</p>" << std::endl;
}

void Log::error(const std::string &error) {
	stream << "<p><span class = \"error\">\n"
		   "\t[ERROR]: </span> "<< error<< "</p>" << std::endl;
}

Log::~Log() {

	stream << "\n </body> \n </html>";
}

void Log::initCSS() {

	stream << "<style> \n"
		   "div.center{\n "
	 "\ttext-align :center\n}\n"
  ".error{\n "
  "\tcolor :red}\n"
			  ".warning{\n "
			  "\tcolor :yellow}\n"
			  "</style>\n";
}

void Log::initHTML() {
	stream << "<html> \n <head> \n <title>" << time << "\n</title> \n </head>" <<std::endl;
	stream << "<body>";
	initCSS();
	stream << "<div class = \"center\">\n"
		   "<h1> " << time  << "\n"
							 "</h1> \n"<<
		"<h2>Project : " << project << "</h2>\n</div>";
}

bool Log::isInit() const {
	return init;
}

