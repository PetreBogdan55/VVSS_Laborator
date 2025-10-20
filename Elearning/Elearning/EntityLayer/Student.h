#pragma once

#include "User.h"
#include "LoggerSingleton.h"

class Student : public User {
public:
    // Rule of 6
    Student() = default;
    Student(const std::string& firstName,
        const std::string& lastName,
        const std::string& email,
        const std::string& address,
        const std::string& phone,
        const std::string& matriculationNumber,
        int studyYear,
        int id = 0);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;
    ~Student() override = default;

public:
    std::string getMatriculationNumber() const;
    int getStudyYear() const;

public:
    void setMatriculationNumber(const std::string& matriculationNumber);
    void setStudyYear(int year);

public:
    void printInformation() const override;

private:
    std::string m_matriculationNumber;
    int m_studyYear;
};
