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
	void deleteStudent(int id) override;
	void addStudent(const Student& student) override;
	void updateStudent(const Student& student) override;

private:
	Database& m_db;
};

