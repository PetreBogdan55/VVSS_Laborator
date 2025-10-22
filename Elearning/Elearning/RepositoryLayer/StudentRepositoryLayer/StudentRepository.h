#pragma once
#include "Database.h"
#include "IStudentRepository.h"

class StudentRepository : public IStudentRepository
{
public:
	StudentRepository(Database& db);

public:
	// Inherited via IStudentRepository
	std::optional<Student> getStudentById(int id) override;
	std::optional<std::vector<Student>> getAllStudents() override;

private:
	Database& m_db;
};

