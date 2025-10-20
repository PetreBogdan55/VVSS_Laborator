#pragma once

#include "User.h"
#include "LoggerSingleton.h"

class Teacher : public User {
public:
    // Rule of 6
    Teacher() = default;
    Teacher(const std::string& firstName,
        const std::string& lastName,
        const std::string& email,
        const std::string& address,
        const std::string& phone,
        const std::string& academicTitle,
        const std::string& department,
        int id = 0);

    Teacher(const Teacher& other);
    Teacher(Teacher&& other) noexcept;
    Teacher& operator=(const Teacher& other);
    Teacher& operator=(Teacher&& other) noexcept;
    ~Teacher() override = default;

public:
    std::string getAcademicTitle() const;
    std::string getDepartment() const;

public:
    void setAcademicTitle(const std::string& title);
    void setDepartment(const std::string& department);

public:
    void printInformation() const override;

private:
    std::string m_academicTitle;
    std::string m_department;
};

