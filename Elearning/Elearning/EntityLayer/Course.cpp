#include "Course.h"

Course::Course(int id, const std::string& title, const std::string& description)
    : m_id(id), m_title(title), m_description(description) {
    if (m_title.empty()) {
        LoggerSingleton::getLoggerInstance()->log("Invalid course title (empty).",
            Logger::Level::Error);
    }
}

Course::Course(const Course& other)
    : m_id(other.m_id),
    m_title(other.m_title),
    m_description(other.m_description) {
}

Course::Course(Course&& other) noexcept
    : m_id(other.m_id),
    m_title(std::move(other.m_title)),
    m_description(std::move(other.m_description)) {
    other.m_id = 0;
}

Course& Course::operator=(const Course& other) {
    if (this != &other) {
        m_id = other.m_id;
        m_title = other.m_title;
        m_description = other.m_description;
    }
    return *this;
}

Course& Course::operator=(Course&& other) noexcept {
    if (this != &other) {
        m_id = other.m_id;
        m_title = std::move(other.m_title);
        m_description = std::move(other.m_description);
        other.m_id = 0;
    }
    return *this;
}

int Course::getId() const 
{ 
    return m_id; 
}

std::string Course::getTitle() const 
{ 
    return m_title; 
}

std::string Course::getDescription() const 
{ 
    return m_description; 
}

void Course::setId(int id) {
    if (id < 0) {
        LoggerSingleton::getLoggerInstance()->log("Attempted to set invalid course ID (<=0).",
            Logger::Level::Error);
        return;
    }
    m_id = id;
}

void Course::setTitle(const std::string& title) {
    if (title.empty()) {
        LoggerSingleton::getLoggerInstance()->log("Invalid course title (empty).",
            Logger::Level::Error);
        return;
    }
    m_title = title;
}

void Course::setDescription(const std::string& description) {
    m_description = description;
}

void Course::printInformation() const {
    std::println("Course: {}, {}, {}",
        m_id,
        m_title,
        m_description);
}
