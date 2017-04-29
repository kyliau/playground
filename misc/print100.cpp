// Parallel Computing:
// Write a program which uses two threads to print the numbers from 1 to 100
// in order. One thread can only print odd numbers, the other can only print
// even numbers.

#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <condition_variable>
using namespace std;

bool                    isOdd = true;
std::mutex              m;  // this mutex guards the 'isOdd' variable
std::condition_variable cv;

void printOdd() {
    for (int i = 1; i < 100; i += 2) {
        std::unique_lock<std::mutex> lock(m);   // this locks the mutex
        cv.wait(lock, []{ return isOdd; });
        cout << i << endl;
        isOdd = false;  // since we own the mutex it is ok to change variable
        lock.unlock();  // must unlock before notifying, otherwise the other
                        // thread wakes up and find that it has nothing to do
        cv.notify_one();
    }
}

void printEven() {
    for (int i = 0; i < 100; i += 2) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, []{ return !isOdd; });
        cout << i + 2 << endl;
        isOdd = true;
        lock.unlock();
        cv.notify_one();
    }
}

int main()
{
    std::thread odd(printOdd);
    std::thread even(printEven);

    odd.join();
    even.join();

    return 0;
}
