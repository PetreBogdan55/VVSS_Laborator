#include "Environment.h"
#include "LoggerSingleton.h"
#include "Student.h"
#include "Teacher.h"
#include <vector>
#include <iostream>

int main()
{
	// Apel clase
	User user("Ion", "Popescu", "ion.popescu@gmail.com", "Str. Lunga, nr 67A, Brasov, Romania", "0712345678");
	user.printInformation();

	Student student("Vlad", "Adrian", "vlad.adrian@student.unitbv.ro", "Bd. Victoriei, nr 4, Bucuresti, Romania", "0712345678", "LZ267", 3);
	student.printInformation();

	Teacher teacher("Dan", "Filip", "dan.filip@unitbv.ro", "Str. Portului, nr 16, Constanta, Romania", "0712345678", "Lect. Dr.", "Matematica si Informatica");
	teacher.printInformation();

	// Apel Environemnt & Logger
	std::cout << Environment::getInstance()->getValue("MY_API_KEY");

	LoggerSingleton::getLoggerInstance()->log("Mesaj", Logger::Level::Info);
	LoggerSingleton::getLoggerInstance()->log("Mesaj", Logger::Level::Warning);
	LoggerSingleton::getLoggerInstance()->log("Mesaj", Logger::Level::Error);

	student.setStudyYear(-3);       // check log.txt
	teacher.setAcademicTitle("");   // check log.txt

	return 0;
}