#pragma once

#include "StudentRepository.h"
#include "Catalog.h"
#include "Utils.h"

class StudentDomain
{
public:
	StudentDomain(StudentRepository& repository,
		Catalog& catalog);

public:
	double calculateAverageMark(int studentID);

private:
	StudentRepository& m_repository;
	Catalog& m_catalog;
};

