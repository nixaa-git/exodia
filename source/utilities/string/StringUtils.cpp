#include "StringUtils.h"

#include <stdarg.h>
#include <vector>

std::string FormatString(const char* fmt, ...)
{
	va_list args = {};
	va_start(args, fmt);

	va_list argsCpy = {};	
	va_copy(argsCpy, args);
	int size = vsnprintf(NULL, 0, fmt, argsCpy);
	va_end(argsCpy);

	if (size < 0)
	{
		va_end(args);
		return "";
	}

	std::vector<char> buffer(size + 1);
	std::vsnprintf(buffer.data(), buffer.size(), fmt, args);
	va_end(args);

	return std::string(buffer.data(), size);
}