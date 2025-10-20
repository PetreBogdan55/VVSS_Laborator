#include "Teacher.h"

Teacher::Teacher(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& address, const std::string& phone, const std::string& academicTitle, const std::string& department, int id)
    : User(firstName, lastName, email, address, phone, id),
    m_academicTitle{ academicTitle },
    m_department{ department }
{
    if (m_academicTitle.empty()) {
        LoggerSingleton::getLoggerInstance()->log("Missing academic title for teacher.", Logger::Level::Error);
    }

    if (m_department.empty()) {
        LoggerSingleton::getLoggerInstance()->log("Missing department for teacher.", Logger::Level::Error);
    }
}

Teacher::Teacher(const Teacher& other)
    : User(other),
    m_academicTitle{ other.m_academicTitle },
    m_department{ other.m_department }
{
}

Teacher::Teacher(Teacher&& other) noexcept
    : User(std::move(other)),
    m_academicTitle{ std::move(other.m_academicTitle) },
    m_department{ std::move(other.m_department) }
{
}

Teacher& Teacher::operator=(const Teacher& other)
{
    if (this != &other) {
        User::operator=(other);
        m_academicTitle = other.m_academicTitle;
        m_department    = other.m_department;
    }
    return *this;
}

Teacher& Teacher::operator=(Teacher&& other) noexcept
{
    if (this != &other) {
        User::operator=(std::move(other));
        m_academicTitle = std::move(other.m_academicTitle);
        m_department    = std::move(other.m_department);
    }
    return *this;
}

std::string Teacher::getAcademicTitle() const
{
	return m_academicTitle;
}

std::string Teacher::getDepartment() const
{
	return m_department;
}

void Teacher::setAcademicTitle(const std::string& title)
{
    if (title.empty()) {
        LoggerSingleton::getLoggerInstance()->log("Attempted to set empty academic title.", Logger::Level::Error);
    }
    else {
        m_academicTitle = title;
    }
}

void Teacher::setDepartment(const std::string& department)
{
    if (department.empty()) {
        LoggerSingleton::getLoggerInstance()->log("Attempted to set empty department.", Logger::Level::Error);
    }
    else {
        m_department = department;
    }
}

void Teacher::printInformation() const
{
    std::println("Teacher: {}, {}, {}, {}, {}, {}, {}, {}",
        m_firstName,
        m_lastName,
        m_email,
        m_address,
        m_phone,
        m_academicTitle,
        m_department,
        m_id);
}
