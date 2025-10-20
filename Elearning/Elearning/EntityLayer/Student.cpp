#include "Student.h"

Student::Student(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& address, const std::string& phone, const std::string& matriculationNumber, int studyYear, int id)
    : User(firstName, lastName, email, address, phone, id),
    m_matriculationNumber{ matriculationNumber },
    m_studyYear{ studyYear }
{
    if (m_matriculationNumber.empty()) {
        LoggerSingleton::getLoggerInstance()->log("Invalid matriculation number (empty).", Logger::Level::Error);
    }

    if (m_studyYear <= 0) {
        LoggerSingleton::getLoggerInstance()->log("Invalid study year (must be > 0).", Logger::Level::Error);
    }
}

Student::Student(const Student& other)
    : User(other),
    m_matriculationNumber{ other.m_matriculationNumber },
    m_studyYear{ other.m_studyYear }
{
}

Student::Student(Student&& other) noexcept
    : User(std::move(other)),
    m_matriculationNumber{ std::move(other.m_matriculationNumber) },
    m_studyYear{ other.m_studyYear }
{
    other.m_studyYear = 0;
}

Student& Student::operator=(const Student& other)
{
    if (this != &other) {
        User::operator=(other);
        m_matriculationNumber = other.m_matriculationNumber;
        m_studyYear           = other.m_studyYear;
    }
    return *this;
}

Student& Student::operator=(Student&& other) noexcept
{
    if (this != &other) {
        User::operator=(std::move(other));
        m_matriculationNumber = std::move(other.m_matriculationNumber);
        m_studyYear           = other.m_studyYear;
        other.m_studyYear = 0;
    }
    return *this;
}

std::string Student::getMatriculationNumber() const
{
    return m_matriculationNumber;
}

int Student::getStudyYear() const
{
    return m_studyYear;
}

void Student::setMatriculationNumber(const std::string& matriculationNumber)
{
    if (matriculationNumber.empty()) {
        LoggerSingleton::getLoggerInstance()->log("Attempted to set empty matriculation number.", Logger::Level::Error);
    }
    else {
        m_matriculationNumber = matriculationNumber;
    }
}

void Student::setStudyYear(int year)
{
    if (year <= 0) {
        LoggerSingleton::getLoggerInstance()->log("Attempted to set invalid study year (<=0).", Logger::Level::Error);
    }
    else {
        m_studyYear = year;
    }
}

void Student::printInformation() const
{
    std::println("Student: {}, {}, {}, {}, {}, {}, {}, {}",
        m_firstName,
        m_lastName,
        m_email,
        m_address,
        m_phone,
        m_matriculationNumber,
        m_studyYear,
        m_id);
}
