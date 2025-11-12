#include <gtest/gtest.h>
#include "Database.h"
#include "StudentRepository.h"

//$(SolutionDir)Elearning/EntityLayer/
//$(SolutionDir)Elearning/IntegrationLayer/Database/
//$(SolutionDir)Elearning/IntegrationLayer/Logger/
//$(SolutionDir)Elearning/IntegrationLayer/Environment/
//$(SolutionDir)Elearning/RepositoryLayer/StudentRepositoryLayer/

TEST(IntegrationTests, AddStudent)
{
	Database database("MSSQLSERVER_CONN_STRING");
	StudentRepository studentRepository(database);
	Student student("a", "a", "a", "a", "a", "a", 3);

	int count1 = studentRepository.getAllStudents().value().size();
	studentRepository.addStudent(student);
	int count2 = studentRepository.getAllStudents().value().size();

	EXPECT_EQ(count1 + 1, count2);
}
TEST(IntegrationTest, DeleteStudent)
{
	Database database("MSSQLSERVER_CONN_STRING");
	StudentRepository studentRepository(database);

	int count1 = studentRepository.getAllStudents().value().size();
	studentRepository.deleteStudent(4007);
	int count2 = studentRepository.getAllStudents().value().size();
	EXPECT_EQ(count1 - 1, count2);
}