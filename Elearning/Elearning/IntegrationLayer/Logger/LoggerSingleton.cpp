#include "LoggerSingleton.h"

Logger* LoggerSingleton::getLoggerInstance()
{
    if (m_instance == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        static Logger log("log.txt");
        log.setMinimumLevel(Logger::Level::Info); // optional
        m_instance = &log;
    }
    return m_instance;
}
