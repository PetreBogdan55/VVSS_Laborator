#include "CourseManager.h"

CourseManager::CourseManager(const CourseManager& other)
    : m_courseTeachers(other.m_courseTeachers),
    m_courseStudents(other.m_courseStudents) {
}

CourseManager::CourseManager(CourseManager&& other) noexcept
    : m_courseTeachers(std::move(other.m_courseTeachers)),
    m_courseStudents(std::move(other.m_courseStudents)) {
}

CourseManager& CourseManager::operator=(const CourseManager& other) {
    if (this != &other) {
        m_courseTeachers = other.m_courseTeachers;
        m_courseStudents = other.m_courseStudents;
    }
    return *this;
}

CourseManager& CourseManager::operator=(CourseManager&& other) noexcept {
    if (this != &other) {
        m_courseTeachers = std::move(other.m_courseTeachers);
        m_courseStudents = std::move(other.m_courseStudents);
    }
    return *this;
}

void CourseManager::assignTeacher(const Course& course, const Teacher& teacher) {
    if (!isValidCourse(course)) {
        LoggerSingleton::getLoggerInstance()->log("Invalid course!", Logger::Level::Error);
        return;
    }
    if (!isValidTeacher(teacher)) {
        LoggerSingleton::getLoggerInstance()->log("Invalid Teacher!", Logger::Level::Error);
        return;
    }

    m_courseTeachers[course.getId()] = teacher;
    LoggerSingleton::getLoggerInstance()->log("The teacher " + teacher.getLastName() +
        " was enroled to course " + course.getTitle() + ".", Logger::Level::Info);
}

void CourseManager::enrollStudent(const Course& course, const Student& student) {
    if (!isValidCourse(course)) {
        LoggerSingleton::getLoggerInstance()->log("Invalid course!", Logger::Level::Error);
        return;
    }
    if (!isValidStudent(student)) {
        LoggerSingleton::getLoggerInstance()->log("Invalid Student!", Logger::Level::Error);
        return;
    }

    m_courseStudents[course.getId()].push_back(student);
    LoggerSingleton::getLoggerInstance()->log("The student " + student.getLastName() +
        " was enroled to course " + course.getTitle() + ".", Logger::Level::Info);
}

Teacher* CourseManager::getTeacherFromCourse(int courseId) {
    if (m_courseTeachers.find(courseId) == m_courseTeachers.end())
        return nullptr;
    return &m_courseTeachers[courseId];
}

std::vector<Student>* CourseManager::getStudentsFromCourse(int courseId) {
    if (m_courseStudents.find(courseId) == m_courseStudents.end())
        return nullptr;
    return &m_courseStudents[courseId];
}

void CourseManager::printCourses() const {
    for (const auto& pair : m_courseTeachers) {
        std::println("Course ID: {} -  Teacher: {}", pair.first, pair.second.getLastName());
    }
}

void CourseManager::printStudentsFromCourse(int courseId) const {
    auto it = m_courseStudents.find(courseId);
    if (it == m_courseStudents.end()) {
        std::println("No enrolled student to this course");
        return;
    }

    for (const auto& s : it->second) {
        std::println("Student: {}, {}", s.getFirstName(), s.getLastName());
    }
}

