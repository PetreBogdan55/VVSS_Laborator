#pragma once

#include "StudentRepository.h"
#include "Catalog.h"
#include "Utils.h"

class StudentDomain
{
public:
	StudentDomain(IStudentRepository& repository,
		Catalog& catalog);

public:
	double calculateAverageMark(int studentID);

private:
	IStudentRepository& m_repository;
	Catalog& m_catalog;
};

