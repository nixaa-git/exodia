#pragma once
#include <iostream>

/*
* Logger class to cleanup the console logs a bit
*/
class Logger
{
public:
	Logger() = default;
	~Logger() = default;

public:
	static void LogInfo(const std::string & message);

private:
	static void Log(const std::string& moduleName, const std::string& message);

};