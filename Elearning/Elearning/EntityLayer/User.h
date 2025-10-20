#pragma once

#include <string>
#include <print>

class User {
public:
	// Rule of 6
	User() = default;
	User(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& address, const std::string& phone, int id = 0);
	User(const User& other);
	User(User&& other) noexcept;
	User& operator=(const User& other);
	User& operator=(User&& other) noexcept;
	virtual ~User() = default;

public:
	int getID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getEmail() const;
	std::string getAddress() const;
	std::string getPhone() const;

public:
	void setID(int id);
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setEmail(const std::string& email);
	void setAddress(const std::string& address);
	void setPhone(const std::string& phone);

public:
	virtual void printInformation() const;

protected:
	int m_id;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_email;
	std::string m_address;
	std::string m_phone;
};