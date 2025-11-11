#include "Logger.h"


void Logger::LogInfo(const std::string& message)
{
	Log("INFO", message);
}

void Logger::Log(const std::string& moduleName, const std::string& message)
{
	printf("[%s]: %s", moduleName.c_str(), message.c_str());
}