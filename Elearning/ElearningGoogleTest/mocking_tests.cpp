#include <gtest/gtest.h>
#include "MockStudentRepository.h"

#include "StudentDomain.h"
#include "Course.h"
#include "Catalog.h"

TEST(MockingTests, GetStudentById)
{
	MockStudentRepository mock;

	int id = 5;
	Student student("Ion", "Popescu", "a", "a", "a", "a", 3, id);

	EXPECT_CALL(mock, getStudentById(id)).WillOnce(testing::Return(student));

	mock.getStudentById(id);

	EXPECT_EQ(student.getFirstName(), "Ion");
}

TEST(MockingTests, CalculateAverageMark)
{
	MockStudentRepository mock;

	int id = 5;
	Student student("Ion", "Popescu", "a", "a", "a", "a", 3, id);

	EXPECT_CALL(mock, getStudentById(id)).WillOnce(testing::Return(student));

	Course curs1(1, "DAM", "");
	Course curs2(2, "TW", "");
	Course curs3(3, "PID", "");
	Course curs4(4, "VVSS", "");

	Catalog catalog;
	catalog.addGrade(student, curs1, 6);
	catalog.addGrade(student, curs2, 8);
	catalog.addGrade(student, curs3, 5);
	catalog.addGrade(student, curs4, 10);

	StudentDomain domain(mock, catalog);
	EXPECT_EQ(domain.calculateAverageMark(id), 7.25);
}

TEST(MockingTests, RepeatedGetStudentById)
{
	MockStudentRepository mock;

	int id = 5;
	Student student("Ion", "Popescu", "a", "a", "a", "a", 3, id);

	EXPECT_CALL(mock, getStudentById(id)).Times(5).WillRepeatedly(testing::Return(student));

	mock.getStudentById(id);
	mock.getStudentById(id);
	mock.getStudentById(id);
	mock.getStudentById(id);
	mock.getStudentById(id);
}