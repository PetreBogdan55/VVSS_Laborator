#include "Catalog.h"

Catalog::Catalog(const Catalog& other)
    : m_grades(other.m_grades) {
}

Catalog::Catalog(Catalog&& other) noexcept
    : m_grades(std::move(other.m_grades)) {
}

Catalog& Catalog::operator=(const Catalog& other) {
    if (this != &other) {
        m_grades = other.m_grades;
    }
    return *this;
}

Catalog& Catalog::operator=(Catalog&& other) noexcept {
    if (this != &other) {
        m_grades = std::move(other.m_grades);
    }
    return *this;
}

bool Catalog::validateGrade(double grade) const {
    return grade >= 1.0 && grade <= 10.0;
}

bool Catalog::recordExists(const Student& student, const Course& course) const {
    StudentCourseKey key{ student.getID(), course.getId() };
    return m_grades.find(key) != m_grades.end();
}

void Catalog::addGrade(const Student& student, const Course& course, double grade) {
    if (!validateGrade(grade)) {
        LoggerSingleton::getLoggerInstance()->log("Invalid grade. Must be between 1 and 10.",
            Logger::Level::Error);
        return;
    }

    StudentCourseKey key{ student.getID(), course.getId() };

    if (m_grades.find(key) != m_grades.end()) {
        LoggerSingleton::getLoggerInstance()->log("Grade for this student and course already exists.",
            Logger::Level::Error);
        return;
    }

    m_grades[key] = grade;
    LoggerSingleton::getLoggerInstance()->log("Added grade " + std::to_string(grade) +
        " for student " + student.getLastName() +
        " in course " + course.getTitle() + ".",
        Logger::Level::Info);
}

void Catalog::updateGrade(const Student& student, const Course& course, double grade) {
    if (!validateGrade(grade)) {
        LoggerSingleton::getLoggerInstance()->log("Invalid grade. Must be between 1 and 10.",
            Logger::Level::Error);
        return;
    }

    StudentCourseKey key{ student.getID(), course.getId() };

    if (m_grades.find(key) == m_grades.end()) {
        LoggerSingleton::getLoggerInstance()->log("Cannot update non-existent grade record.",
            Logger::Level::Error);
        return;
    }

    m_grades[key] = grade;
    LoggerSingleton::getLoggerInstance()->log("Updated grade to " + std::to_string(grade) +
        " for student " + student.getLastName() +
        " in course " + course.getTitle() + ".",
        Logger::Level::Info);
}

double Catalog::getGrade(const Student& student, const Course& course) const {
    StudentCourseKey key{ student.getID(), course.getId() };
    auto it = m_grades.find(key);
    if (it == m_grades.end()) {
        LoggerSingleton::getLoggerInstance()->log("Grade not found for given student and course.",
            Logger::Level::Error);
        return -1.0;
    }
    return it->second;
}

std::vector<double> Catalog::getAllGrades(const Student& student) const
{
    std::vector<double> grades;
    for (const auto& [key, grade] : m_grades) {
        if (key.studentId == student.getID())
            grades.push_back(grade);
    }
    return grades;
}

void Catalog::printAllGrades() const {
    for (const auto& [key, grade] : m_grades) {
        std::println("Student ID: {} | Course ID: {}, Grade: {}", key.studentId, key.courseId, grade);
    }
}
