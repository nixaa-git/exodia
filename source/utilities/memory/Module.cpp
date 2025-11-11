#pragma once
#include <vector>

#include "Module.h"

std::vector<int32_t> PatternToBytes(const std::string& pattern)
{
	std::vector<int32_t> bytes;

	char* start = const_cast<char*>(pattern.data());
	char* end = start + pattern.size();

	for (char* c = start; c < end; ++c)
	{
		if (*c == '?')
		{
			++c;

			if (*c == '?') ++c;

			bytes.push_back(-1);
		}
		else
		{
			bytes.push_back(static_cast<int32_t>(std::strtoul(c, &c, 16)));
		}
	}

	return bytes;
};

std::vector<uint8_t> StringToBytes(const std::string& str)
{
	std::vector<std::uint8_t> bytes;

	char* start = const_cast<char*>(str.data());
	char* end = start + str.size();

	for (char* c = start; c < end; ++c)
		bytes.push_back(static_cast<std::uint8_t>(std::strtoul(c, &c, 16)));

	return bytes;
};

bool WriteMemory(void* address, const std::string& strBytes)
{
	DWORD old = 0;

	std::vector<std::uint8_t> bytes = StringToBytes(strBytes);

	if (!::VirtualProtect(address, bytes.size(), PAGE_EXECUTE_READWRITE, &old))
		return false;

	::memcpy(address, bytes.data(), bytes.size());

	return ::VirtualProtect(address, bytes.size(), old, &old);
}

c_address c_module::GetBaseAddress()
{
	c_address ret = 0;

	if (!IsLoaded())
		return ret;

	ret = GetModuleHandleA(m_name);

	return ret;
}

c_address c_module::GetProcAddress(const char* proc_name)
{
	c_address ret = 0;

	if (!IsLoaded())
		return ret;

	ret = ::GetProcAddress(m_module, proc_name);

	return ret;
}

c_address c_module::FindPattern(const std::string& pattern, std::string name)
{
	c_address ret = 0;

	if (!IsLoaded())
		return ret;

	std::vector<int32_t> bytes = PatternToBytes(pattern);
	for (std::size_t i = m_start; i < m_end; ++i)
	{
		for (std::size_t j = 0; j < bytes.size(); ++j)
		{
			if (*reinterpret_cast<uint8_t*>(i + j) != bytes[j] && bytes[j] != -1)
				break;

			if (j == bytes.size() - 1)
			{
				ret = i;
				std::printf("found address %s -> 0x%llx\n", name.c_str(), ret.Get());

				break;
			}
		}

		if (ret.IsValid())
			break;
	}

	if (!ret.IsValid())
		std::printf("failed to find %s\n", name.c_str());

	return ret;
}