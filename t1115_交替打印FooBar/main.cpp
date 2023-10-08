#include <iostream>
#include "Solution.h"
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <vector>

int main() {
    FooBar fooBar(2);
    function<void(void)> foo = []{ printf("Foo");};
    function<void(void)> bar = []{ printf("Bar");};
    thread t1(&FooBar::foo, &fooBar, foo);
    thread t2(&FooBar::bar, &fooBar, bar);
    t1.join();
    t2.join();

    // 创建生产者和消费者线程
    std::thread newt1(producer);
    std::thread newt2(consumer);

    // main主线程等待所有子线程执行完
    newt1.join();
    newt2.join();
    return 0;
}

