#include "User.h"
#include "Environment.h"
#include "LoggerSingleton.h"
#include <vector>
#include <iostream>
#include <print>

int main()
{
	// Apel clase
	User user("Ion", "Popescu", "ion.popescu@gmail.com", "Str. Lunga, nr 67A, Brasov, Romania", "0712345678");
	user.PrintInformation();

	std::cout << Environment::getInstance()->getValue("MY_API_KEY");

	LoggerSingleton::getLoggerInstance()->log("Mesaj", Logger::Level::Info);
	LoggerSingleton::getLoggerInstance()->log("Mesaj", Logger::Level::Warning);
	LoggerSingleton::getLoggerInstance()->log("Mesaj", Logger::Level::Error);

	return 0;
}