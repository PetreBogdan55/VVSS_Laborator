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
	int GetID() const;
	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetEmail() const;
	std::string GetAddress() const;
	std::string GetPhone() const;

public:
	void SetID(int id);
	void SetFirstName(const std::string& firstName);
	void SetLastName(const std::string& lastName);
	void SetEmail(const std::string& email);
	void SetAddress(const std::string& address);
	void SetPhone(const std::string& phone);

public:
	virtual void PrintInformation() const;

protected:
	int m_id;
	std::string m_firstName;
	std::string m_lastName;
	std::string m_email;
	std::string m_address;
	std::string m_phone;
};