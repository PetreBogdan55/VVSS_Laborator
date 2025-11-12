#pragma once

#include "IStudentRepository.h"
#include <gmock/gmock.h>

class MockStudentRepository : public IStudentRepository
{
public:
	// Inherited via IStudentRepository
	MOCK_METHOD(std::optional<Student>             , getStudentById, (int id)                , (override));
	MOCK_METHOD(std::optional<std::vector<Student>>, getAllStudents, ()                      , (override));
	MOCK_METHOD(void                               , deleteStudent , (int id)                , (override));
	MOCK_METHOD(void                               , addStudent    , (const Student& student), (override));
	MOCK_METHOD(void                               , updateStudent , (const Student& student), (override));
};