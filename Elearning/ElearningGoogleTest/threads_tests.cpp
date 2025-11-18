#include <gtest/gtest.h>
#include <thread>
#include <mutex>

TEST(ThreadingTests, MutexProtectedIncrement) {
    const int N = 10'000;
    int counter = 0;
    std::mutex m;

    auto worker = [&]() {
        for (int i = 0; i < N; i++) {
            std::lock_guard<std::mutex> lock(m);
            counter++;
        }
        };

    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    ASSERT_EQ(counter, 2 * N);
}


TEST(ThreadingTests, RaceConditionCausesIncorrectResult) {
    const int N = 200'000;
    int counter = 0;  

    auto worker = [&]() {
        for (int i = 0; i < N; i++) {
            counter++; 
        }
        };

    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    ASSERT_NE(counter, 2 * N);
}

#include <condition_variable>

TEST(ThreadingTests, ConditionVariableSignalsCorrectly) {
    std::mutex m;
    std::condition_variable cv;
    bool ready = false;

    std::thread worker([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        {
            std::lock_guard<std::mutex> lock(m);
            ready = true;
        }
        cv.notify_one();
        });

    std::unique_lock<std::mutex> lock(m);
    bool result = cv.wait_for(lock, std::chrono::milliseconds(200),
        [&]() { return ready; });

    worker.join();

    ASSERT_TRUE(result);
}

#include "ThreadSafeQueue.h"

TEST(ThreadingTests, ThreadSafeQueueWorksUnderConcurrency) {
    ThreadSafeQueue<int> q;

    std::thread producer([&]() {
        for (int i = 0; i < 100; i++)
            q.push(i);
        });

    std::thread consumer([&]() {
        for (int i = 0; i < 100; i++) {
            int val = q.pop();
            ASSERT_EQ(val, i);
        }
        });

    producer.join();
    consumer.join();
}

#include "Latch.h"

TEST(ThreadingTests, LatchSynchronizesThreads) {
    Latch latch(3);
    std::atomic<int> started{ 0 };

    auto worker = [&]() {
        started++;
        latch.count_down();
        latch.wait();
        ASSERT_EQ(started.load(), 3);
        };

    std::thread t1(worker);
    std::thread t2(worker);
    std::thread t3(worker);

    t1.join();
    t2.join();
    t3.join();
}


