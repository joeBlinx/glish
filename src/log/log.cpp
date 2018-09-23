//
// Created by joe on 23/09/18.
//

#include <glish3/log/log.hpp>
#include <ctime>
#include <utils/stringUtil.h>

Log::Log(const std::string &path) {

	std::time_t result = std::time(nullptr);
	std::string time = std::asctime(std::localtime(&result));
	utils::replace(time, " ", "_");
	utils::replace(time, ":", "_");
	stream = std::ofstream(path + "/" + time +".html");


}

void Log::info(const std::string &info) {
	stream << "test";
}

void Log::warning(const std::string &warn) {

}

void Log::error(const std::string &error) {

}

