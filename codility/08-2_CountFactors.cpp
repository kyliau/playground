
// Lesson 8 - Prime and Composite Numbers
// CountFactors
// Count factors of given number n.

// Both solutions work but last test case time out

// solution 1
int solution(int N) {
    int count = 0;
    int x = 1;
    while (x * x < N) {
        if (N % x == 0) {
            count += 2;
        }
        x++;
    }
    if (x * x == N) count++;
    return count;
}

// solution 2
int solution(int N) {
    int count = 0;
    for (int x = 1; x * x <= N; x++) {
        int y = N / x;
        if (x * y == N) {
            count = (x == y) ? count + 1 : count + 2;
        }
    }
    return count;
}

