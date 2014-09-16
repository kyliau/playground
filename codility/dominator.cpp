#include <unordered_map>
int solution(vector<int> &A) {
    // write your code in C++11
    unsigned N = A.size();
    unordered_map<int, unsigned> hash;
    for (unsigned i = 0; i < N; ++i) {
        unsigned count = ++hash[A[i]];
        if (count > N / 2) {
            return i;
        }
    }
    return -1;
}
