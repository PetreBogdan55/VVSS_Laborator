#pragma once
#include "Student.h"
#include <vector>
#include <optional>

class IStudentRepository {
	virtual std::optional<Student> getStudentById(int id) = 0;
	virtual std::optional<std::vector<Student>> getAllStudents() = 0;
};
