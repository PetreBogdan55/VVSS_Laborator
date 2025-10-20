#pragma once
#include "Logger.h"
#include <mutex>

class LoggerSingleton
{
public:
	LoggerSingleton(LoggerSingleton const&) = delete;
	LoggerSingleton(LoggerSingleton&&) = delete;
	LoggerSingleton& operator=(LoggerSingleton const&) = delete;
	LoggerSingleton& operator=(LoggerSingleton&&) = delete;

	static Logger* getLoggerInstance();

protected:
	LoggerSingleton() = default;
	~LoggerSingleton() = default;

	inline static Logger* m_instance = nullptr;
	inline static std::mutex m_mutex;  // thread safety
};

