#include "Environment.h"
#include "LoggerSingleton.h"
#include "StudentRepository.h"
#include "Teacher.h"

int main()
{
	Database database("MSSQLSERVER_CONN_STRING");
	StudentRepository studentRepository(database);

	Student studentNou("Ion", "Vasile", "ion@yahoo.com", "Str.Brazilor 17",
		"0777123412", "GTEYE", 2, 1);
	studentRepository.updateStudent(studentNou);

	//studentRepository.deleteStudent(2005);

	const auto students = studentRepository.getAllStudents();
	if (students != std::nullopt)
		for (const auto& student : students.value())
			student.printInformation();

	const auto student = studentRepository.getStudentById(2);
	if (student != std::nullopt)
		student.value().printInformation();

	return 0;
}