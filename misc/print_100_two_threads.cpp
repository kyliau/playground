// Parallel Computing:
// Write a program which uses two threads to print the numbers from 1 to 100
// in order. One thread can only print odd numbers, the other can only print
// even numbers.

#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

void print(int max, bool isEven)
{
    for (int i = isEven ? 0 : 1; i < max; i += 2) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock);
        std::cout << i + 1 << std::endl;
        lock.unlock();
        cv.notify_one();
    }
}

int main()
{
    int MAX = 100;
    std::thread printEven(print, MAX, true);
    std::thread printOdd( print, MAX, false);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    cv.notify_one();

    printEven.join();
    printOdd.join();

    return 0;
}
