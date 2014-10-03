
// Lesson 8 - Prime and Composite Numbers
// MinPerimeterRectangle
// Find the minimal perimeter of any rectangle whose area equals N.

int solution(int N) {
    int perimeter = 2 * (N + 1);
    for (int x = 1; x * x <= N; x++) {
        int y = N / x;
        if (x * y == N) {
            perimeter = min(2 * (x + y), perimeter);
        }
    }
    return perimeter;
}

