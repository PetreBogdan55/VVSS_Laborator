#pragma once

#include <string>
#include <print>
#include "LoggerSingleton.h"

class Course {
public:
    // Rule of 6
    Course() = default;
    Course(int id, const std::string& title, const std::string& description);
    Course(const Course& other);
    Course(Course&& other) noexcept;
    Course& operator=(const Course& other);
    Course& operator=(Course&& other) noexcept;
    ~Course() = default;

public:
    int getId() const;
    std::string getTitle() const;
    std::string getDescription() const;

public:
    void setId(int id);
    void setTitle(const std::string& title);
    void setDescription(const std::string& description);

public:
    void printInformation() const;

private:
    int m_id;
    std::string m_title;
    std::string m_description;
};


