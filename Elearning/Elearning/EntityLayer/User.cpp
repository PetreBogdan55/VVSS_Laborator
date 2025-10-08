#include "User.h"

User::User(const std::string& firstName, const std::string& lastName, int id)
    :m_firstName{ firstName }, m_lastName{ lastName }, m_id{ id }
{
}

User::User(const User& other)
    : m_firstName { other.m_firstName}, m_lastName {other.m_lastName}, m_id{other.m_id}
{
}

User::User(User&& other) noexcept
    : m_firstName{ std::move(other.m_firstName) }, m_lastName{ std::move(other.m_lastName) }, m_id{ other.m_id }
{
    other.m_id = 0;
}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        m_firstName = other.m_firstName;
        m_lastName = other.m_lastName;
        m_id = other.m_id;
    }
    return *this;
}

User& User::operator=(User&& other) noexcept
{
    if (this != &other)
    {
        m_firstName = std::move(other.m_firstName);
        m_lastName = std::move(other.m_lastName);
        m_id = other.m_id;
        other.m_id = 0;
    }
    return *this;
}

void User::PrintInformation() const
{
    std::println("User: {}, {}, {}", m_firstName, m_lastName, m_id);
}
