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

Log::Log(const std::string &path) {

	std::time_t result = std::time(nullptr);
	time = std::asctime(std::localtime(&result));
	utils::replace(time, " ", "_");
	utils::replace(time, ":", "_");
	stream = std::ofstream(path + "/" + time +".html");
	if(!stream.is_open()){
		stream = std::ofstream("log.txt");
		stream << "path given is invalid : " << path << std::endl;
		stream.close();
	}else{
		initHTML();
	}


}

void Log::info(const std::string &info) {
	stream << "test";
}

void Log::warning(const std::string &warn) {

}

void Log::error(const std::string &error) {

}

Log::~Log() {

	stream << "\n </body> \n </html>";
}

void Log::initCSS() {

	stream << "<style> \n"
		   "div.center{ "
	 "	text-align :center"
  "</style>";
}

void Log::initHTML() {
	stream << "<html> \n <head> \n <title> Log " << time << "\n</title> \n </head>" <<std::endl;
	stream << "<body>";
	initCSS();
	stream << "<div class = a>\n"
		   "<h1> Log " << time  << "\n"
							 "</h1> \n</div>";
}

