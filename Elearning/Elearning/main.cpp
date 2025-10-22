#include "Environment.h"
#include "LoggerSingleton.h"
#include "StudentRepository.h"
#include "Teacher.h"

int main()
{
	Database database("MSSQLSERVER_CONN_STRING");
	StudentRepository studentRepository(database);
	const auto students = studentRepository.getAllStudents();
	if (students != std::nullopt)
		for (const auto& student : students.value())
			student.printInformation();

	const auto student = studentRepository.getStudentById(2);
	if (student != std::nullopt)
		student.value().printInformation();

	return 0;
}