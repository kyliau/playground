// Parallel Computing:
// Write a program which uses two threads to print the numbers from 1 to 100
// in order. One thread can only print odd numbers, the other can only print
// even numbers.

#include <thread>
#include <iostream>
#include <mutex>

std::mutex mtx;

void print(int max, bool isEven)
{
    for (int i = isEven ? 0 : 1; i < max; i += 2) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << i + 1 << std::endl;
    }
}

int main()
{
    int MAX = 100;
    std::thread printEven(print, MAX, true);
    std::thread printOdd( print, MAX, false);

    printEven.join();
    printOdd.join();

    return 0;
}
