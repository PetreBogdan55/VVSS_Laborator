#include "User.h"

User::User(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& address, const std::string& phone, int id)
    :m_firstName{ firstName }, m_lastName{ lastName }, m_email{ email }, m_address{ address }, m_phone{ phone }, m_id { id }
{
}

User::User(const User& other)
    : m_firstName{ other.m_firstName}, m_lastName {other.m_lastName}, m_email{ other.m_email }, m_address{ other.m_address }, m_phone{ other.m_phone }, m_id{other.m_id}
{
}

User::User(User&& other) noexcept
    : m_firstName{ std::move(other.m_firstName) }, m_lastName{ std::move(other.m_lastName) }, m_email{ std::move(other.m_email) }, m_address{ std::move(other.m_address) }, m_phone{ std::move(other.m_phone) }, m_id{ other.m_id }
{
    other.m_id = 0;
}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        m_firstName = other.m_firstName;
        m_lastName  = other.m_lastName ;
        m_email     = other.m_email    ;
        m_address   = other.m_address  ;
        m_phone     = other.m_email    ;
        m_id        = other.m_id       ;
    }
    return *this;
}

User& User::operator=(User&& other) noexcept
{
    if (this != &other)
    {
        m_firstName = std::move(other.m_firstName);
        m_lastName  = std::move(other.m_lastName) ;
        m_email     = std::move(other.m_email)    ;
        m_address   = std::move(other.m_address)  ;
        m_phone     = std::move(other.m_email)    ;
        m_id        = other.m_id                  ;
        other.m_id  = 0                           ;
    }
    return *this;
}

int User::GetID() const
{
    return m_id;
}

std::string User::GetFirstName() const
{
    return m_firstName;
}

std::string User::GetLastName() const
{
    return m_lastName;
}

std::string User::GetEmail() const
{
    return m_email;
}

std::string User::GetAddress() const
{
    return m_address;
}

std::string User::GetPhone() const
{
    return m_phone;
}

void User::SetID(int id)
{
    m_id = id;
}

void User::SetFirstName(const std::string& firstName)
{
    m_firstName = firstName;
}

void User::SetLastName(const std::string& lastName)
{
    m_lastName = lastName;
}

void User::SetEmail(const std::string& email)
{
    m_email = email;
}

void User::SetAddress(const std::string& address)
{
    m_address = address;
}

void User::SetPhone(const std::string& phone)
{
    m_phone = phone;
}

void User::PrintInformation() const
{
    std::println("User: {}, {}, {}, {}, {}, {}", m_firstName, m_lastName, m_email, m_address, m_phone, m_id);
}
