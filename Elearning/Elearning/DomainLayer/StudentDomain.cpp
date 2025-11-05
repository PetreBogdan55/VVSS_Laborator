#include "StudentDomain.h"


StudentDomain::StudentDomain(StudentRepository& repository,
	Catalog& catalog)
	: m_repository(repository), m_catalog(catalog)
{
}

double StudentDomain::calculateAverageMark(int studentID)
{
	auto studentOpt = m_repository.getStudentById(studentID);
	if (!studentOpt.has_value())
		return -1;
	const Student& student = studentOpt.value();
	std::vector<double> grades = m_catalog.getAllGrades(student);
	double average = calculateAverage(grades);
	return average;
}