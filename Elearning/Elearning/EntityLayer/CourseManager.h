#pragma once

#include <unordered_map>
#include <vector>
#include "Course.h"
#include "Teacher.h"
#include "Student.h"
#include "LoggerSingleton.h"

class CourseManager {
public:
    // Rule of 6
    CourseManager() = default;
    CourseManager(const CourseManager& other);
    CourseManager(CourseManager&& other) noexcept;
    CourseManager& operator=(const CourseManager& other);
    CourseManager& operator=(CourseManager&& other) noexcept;
    ~CourseManager() = default;

public:
    void assignTeacher(const Course& course, const Teacher& teacher);
    void enrollStudent(const Course& course, const Student& student);
    Teacher* getTeacherFromCourse(int courseId);
    std::vector<Student>* getStudentsFromCourse(int courseId);
    void printCourses() const;
    void printStudentsFromCourse(int courseId) const;

private:
    bool isValidCourse(const Course& course) const;
    bool isValidTeacher(const Teacher& teacher) const;
    bool isValidStudent(const Student& student) const;

private:
    std::unordered_map<int, Teacher> m_courseTeachers;
    std::unordered_map<int, std::vector<Student>> m_courseStudents;
};

