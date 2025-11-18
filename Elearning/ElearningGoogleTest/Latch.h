#pragma once

#include <mutex>

class Latch {
public:
    explicit Latch(int count) : count_(count) {}

    void count_down() {
        std::lock_guard<std::mutex> lock(m_);
        if (--count_ == 0)
            cv_.notify_all();
    }

    void wait() {
        std::unique_lock<std::mutex> lock(m_);
        cv_.wait(lock, [&]() { return count_ == 0; });
    }

private:
    int count_;
    std::mutex m_;
    std::condition_variable cv_;
};
