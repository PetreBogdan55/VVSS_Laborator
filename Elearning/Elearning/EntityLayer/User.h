#pragma once

#include <string>
#include <print>

class User {
public:
	// Rule of 6
	User() = default;
	User(const std::string& firstName, const std::string& lastName, int id = 0);
	User(const User& other);
	User(User&& other) noexcept;
	User& operator=(const User& other);
	User& operator=(User&& other) noexcept;
	virtual ~User() = default;

public:
	virtual void PrintInformation() const;

private:
	int m_id;
	std::string m_firstName;
	std::string m_lastName;
};
