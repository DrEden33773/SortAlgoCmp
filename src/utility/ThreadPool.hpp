/**
 * @file ThreadPool.hpp
 * @author Eden (edwardwang33773@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-01-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

#include <future>
#include <queue>
#include <thread>
#include <vector>

namespace Utility {

class ThreadPool {
public:
    explicit ThreadPool(
        std::size_t numThreads = std::thread::hardware_concurrency()
    ) {
        for (std::size_t i = 0; i < numThreads; ++i) {
            threads.emplace_back([&]() {
                for (;;) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        condition.wait(lock, [&]() { return stop || !tasks.empty(); });
                        if (stop && tasks.empty()) {
                            return;
                        }
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    template <typename T>
    auto enqueue(T task) -> std::future<decltype(task())> {
        auto wrapper = std::make_shared<std::packaged_task<decltype(task())()>>(
            std::move(task)
        );
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            if (stop) {
                throw std::runtime_error("enqueue on stopped ThreadPool");
            }
            tasks.emplace([=]() { (*wrapper)(); });
        }
        condition.notify_one();
        return wrapper->get_future();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for (auto& thread : threads) {
            thread.join();
        }
    }

private:
    std::vector<std::thread>          threads;
    std::queue<std::function<void()>> tasks;
    std::mutex                        queueMutex;
    std::condition_variable           condition;
    bool                              stop = false;
};

} // namespace Utility