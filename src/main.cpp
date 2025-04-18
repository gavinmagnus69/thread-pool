//StaticThreadPool ver 1.0


#include <iostream>
#include <functional>


#include "UnboundedMPMCQueue.h"
#include "StaticThreadPool.h"

int main() {
    stp::UnboundedMPMCQueue<std::function<void(void)>> taskQueue;
    auto task1 = []() { std::cout << "you stupid niiger\n"; };
    auto task2 = []() { std::cout << "you stupid gigger\n"; };
    auto task3 = []() { std::cout << "fasdfkasfl;asfkafs\n"; };
    // taskQueue.put(std::move(task1));
    // taskQueue.put(std::move(task2));
    // taskQueue.put(std::move(task3));
    // for(int i = 0; i < 3; ++i) {
    //     taskQueue.take()();
    // }
    stp::StaticThreadPool threadPool{4};
    threadPool.putTask(std::move(task1));
    threadPool.putTask(std::move(task2));
    threadPool.putTask(std::move(task3));
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "hello thread-pool\n";
    // while(true) {
    //     std::cout << "Enter 1 to load task\n";
    //     int i = 0;
    //     std::cin >> i;
    //     if(i == 1) {
    //         threadPool.putTask(std::move(task1));
    //         std::this_thread::sleep_for(std::chrono::milliseconds(300));
    //     }
    // }
    int sum = 0;
    for(int i = 0; i < 10012310; ++i) {
        threadPool.putTask(std::move([&]() {
            ++sum;
        }));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    std::cout << sum << '\n';
}