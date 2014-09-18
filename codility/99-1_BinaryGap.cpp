
// Lesson 99 - Future Training
// BinaryGap
// Find longest sequence of zeros in binary representation of an integer.

#include <bitset>
#include <math.h>

int solution(int N) {
    // write your code in C++11
    unsigned num_bits = log2(N);
    bitset<sizeof(int) * 8> foo(N);
    unsigned max = 0;
    unsigned temp = 0;
    bool start = false;
    for (unsigned i = 0; i <= num_bits; i++) {
        if (!start && foo[i]) {
            start = true;
        }
        if (!start) continue;
        if (foo[i]) {
            if (temp > max) {
                max = temp;
            }
            temp = 0;
        } else {
            temp++;
        }
    }
    return max;
}
