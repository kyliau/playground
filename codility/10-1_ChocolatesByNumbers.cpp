
// Lesson 10 - Euclidean Algorithm
// ChocolatesByNumbers
// There are N chocolates in a circle. Count the number of chocolates 
// you will eat.

// greatest common divisor
unsigned gcd(unsigned a, unsigned b) {
    unsigned temp = a % b;
    if (temp == 0) {
        return b;
    }
    return gcd(b, temp);
}

// least common multiple
unsigned lcm(unsigned a, unsigned b) {
    return a * b / gcd(a, b);
}

int solution(int N, int M) {
    return N / gcd(N,M);
}

