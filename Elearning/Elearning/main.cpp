#include "Environment.h"
#include "LoggerSingleton.h"
#include "StudentService.h"
#include "Course.h"

int main()
{
	Database database("MSSQLSERVER_CONN_STRING");
	StudentRepository studentRepository(database);
	Student student = studentRepository.getStudentById(1).value();

	Course curs1(1, "DAM", "");
	Course curs2(2, "TW", "");
	Course curs3(3, "PID", "");
	Course curs4(4, "VVSS", "");

	Catalog catalog;
	catalog.addGrade(student, curs1, 6);
	catalog.addGrade(student, curs2, 8);
	catalog.addGrade(student, curs3, 5);
	catalog.addGrade(student, curs4, 10);
	std::println("{}", catalog.getAllGrades(student));
	
	StudentDomain studentDomain(studentRepository, catalog);
	StudentService studentService(studentDomain);
	std::println("{}", studentService.calculateAverageMark(1));

	return 0;
}