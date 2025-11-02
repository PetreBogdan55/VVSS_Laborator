#pragma once

#include <unordered_map>
#include <utility>
#include "Student.h"
#include "Course.h"
#include "LoggerSingleton.h"

class Catalog {
public:
    // Rule of 6
    Catalog() = default;
    Catalog(const Catalog& other);
    Catalog(Catalog&& other) noexcept;
    Catalog& operator=(const Catalog& other);
    Catalog& operator=(Catalog&& other) noexcept;
    ~Catalog() = default;

public:
    void addGrade(const Student& student, const Course& course, double grade);
    void updateGrade(const Student& student, const Course& course, double grade);
    double getGrade(const Student& student, const Course& course) const;
    void printAllGrades() const;

private:
    bool validateGrade(double grade) const;
    bool recordExists(const Student& student, const Course& course) const;

private:
    struct StudentCourseKey {
        int studentId;
        int courseId;

        bool operator==(const StudentCourseKey& other) const noexcept {
            return studentId == other.studentId && courseId == other.courseId;
        }
    };

    struct KeyHash {
        std::size_t operator()(const StudentCourseKey& key) const noexcept {
            return std::hash<int>()(key.studentId) ^ (std::hash<int>()(key.courseId) << 1);
        }
    };

    std::unordered_map<StudentCourseKey, double, KeyHash> m_grades;
};


