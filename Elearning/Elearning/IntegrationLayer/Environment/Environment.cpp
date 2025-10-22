#include "Environment.h"

Environment* Environment::getInstance()
{
    if (m_instance == nullptr)
    {
        //m_mutex.lock(); // .unlock();
        //std::lock_guard<std::mutex> lock(m_mutex);
        m_instance = new Environment();
    }
    return m_instance;
}

std::string Environment::getValue(const std::string& key) const
{
    std::ifstream file(".env");
    if (!file.is_open()) return "";
    
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        if (line[0] == '#') continue;
        if (line.rfind(key + "=", 0) == 0)
            return line.substr(key.size() + 1);
    }
    return "";
}
