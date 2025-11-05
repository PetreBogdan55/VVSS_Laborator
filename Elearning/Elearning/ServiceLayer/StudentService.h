#pragma once

#include "StudentDomain.h"

class StudentService
{
public:
	StudentService(StudentDomain& domain);

public:
	double calculateAverageMark(int studentID);

private:
	StudentDomain& m_domain;
};

