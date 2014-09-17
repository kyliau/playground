
// Lesson 1 - Time Complexity
// FrogJmp
// Count minimal number of jumps from position X to Y.

#include <math.h>
int solution(int X, int Y, int D) {
    return ceil((Y - X) / (double)D);
}

