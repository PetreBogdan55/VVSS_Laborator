#pragma once

#include <queue>

template <typename T>
class ThreadSafeQueue {
public:
    void push(const T& value) {
        std::lock_guard<std::mutex> lock(m_);
        q_.push(value);
        cv_.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(m_);
        cv_.wait(lock, [&]() { return !q_.empty(); });
        T val = q_.front();
        q_.pop();
        return val;
    }

private:
    std::queue<T> q_;
    std::mutex m_;
    std::condition_variable cv_;
};
