// Parallel Computing:
// Write a program which uses two threads to print the numbers from 1 to 100
// in order. One thread can only print odd numbers, the other can only print
// even numbers.

#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <functional>
#include <condition_variable>
using namespace std;

bool                    isOdd = true;
std::mutex              m;  // this mutex guards the 'isOdd' variable
std::condition_variable cv;

void print(bool odd) {
    for (int i = odd ? 1 : 2; i <= 100; i += 2) {
        std::unique_lock<std::mutex> lock(m);   // this locks the mutex
        cv.wait(lock, [odd]{ return odd ? isOdd : !isOdd; });
        cout << i << endl;
        isOdd = !isOdd; // since we own the mutex it is ok to change variable
        lock.unlock();  // must unlock before notifying, otherwise the other
                        // thread wakes up and find that it has nothing to do
        cv.notify_one();
    }
}
int main()
{
    std::thread odd(std::bind(print, true));
    std::thread even(std::bind(print, false));

    odd.join();
    even.join();

    return 0;
}
