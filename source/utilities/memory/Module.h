#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <Psapi.h>

std::vector<int32_t> PatternToBytes(const std::string&);
std::vector<uint8_t> StringToBytes(const std::string&);
bool WriteMemory(void*, const std::string&);

class c_address
{
public:
	template<typename T>
	c_address(T value)
	{
		m_value = (uintptr_t)value;
	}

	template <typename T = void*>
	T Get()
	{
		return (T)(m_value);
	}

	template <typename T>
	void Get(T& dest)
	{
		dest = Get<T>();
	}

	c_address& AddOffset(int offset)
	{
		if (m_value) m_value += offset;
		return *this;
	}

	c_address& ToAbsolute(int pre_offset, int post_offset)
	{
		if (m_value)
		{
			AddOffset(pre_offset);
			m_value += sizeof(int) + *(int*)(m_value);
			AddOffset(post_offset);
		}

		return *this;
	}

	c_address& Relative()
	{
		if (*reinterpret_cast<std::uint8_t*>(m_value) != 0xE8)
			return *this;

		std::int32_t relative_address = *reinterpret_cast<std::int32_t*>(m_value + 1);
		m_value += relative_address + 5;

		return *this;
	}

	c_address& Dereference(int amount = 1)
	{
		if (m_value) while (amount-- != 0) m_value = *(uintptr_t*)(m_value);
		return *this;
	}

	bool IsValid() { return m_value != 0; };

private:
	uintptr_t m_value;
};

class c_module
{
public:
	explicit c_module(const char* name) : m_name(name) { Initialize(); };

	void Initialize()
	{
		InitializeModule();
		InitializeBounds();
	}

	c_address GetBaseAddress();
	c_address GetProcAddress(const char* proc_name);
	c_address FindPattern(const std::string& pattern, std::string name = "");

	bool IsLoaded() const { return m_module != 0; };
	const char* GetName() const { return m_name; };

private:
	HMODULE m_module = NULL;
	uintptr_t m_start = 0;
	uintptr_t m_end = 0;
	const char* m_name = "";

	void InitializeModule()
	{
		m_module = GetModuleHandleA(m_name);
	}

	void InitializeBounds()
	{
		if (!IsLoaded())
			return;

		MODULEINFO mi;
		BOOL status = K32GetModuleInformation(GetCurrentProcess(), m_module, &mi, sizeof(mi));

		if (!status)
		{
			std::printf("failed to initialize bounds for %s", m_name);
			return;
		}

		m_start = reinterpret_cast<uintptr_t>(m_module);
		m_end = m_start + static_cast<uintptr_t>(mi.SizeOfImage);
	}
};