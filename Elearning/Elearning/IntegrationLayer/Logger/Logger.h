#pragma once
#include <string>
#include <fstream>
#include <time.h>
#include <stdint.h>
#include <iomanip>

class Logger
{
public:
	enum class Level
	{
		Info,
		Warning,
		Error
	};

public:
	Logger(const std::string& filename);
	void log(const std::string& message, Level level);
	void setMinimumLevel(Level minimumLevel);

private:
	std::ostream& m_os;
	std::ofstream m_fout;
	Level m_minimumLevel;
};

