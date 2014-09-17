
// Lesson 14 - Greedy Algorithms
// TieRopes
// Tie adjacent ropes to achieve the maximum number of ropes of length >= K.

// It works but I have no idea why lol

int solution(int K, vector<int> &A) {
    unsigned count = 0;
    int temp = 0;
    for (int a : A) {
        temp += a;
        if (temp >= K) {
            temp = 0;
            count++;
        }
    }
    return count;
}

