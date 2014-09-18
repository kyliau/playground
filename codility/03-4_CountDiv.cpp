
// Lesson 3 - Prefix Sums
// CountDiv
// Compute number of integers divisible by k in range [a..b].

#include <math.h>
int solution(int A, int B, int K) {
    double k = K;
    return floor(B/k) - ceil(A/k) + 1;
}
