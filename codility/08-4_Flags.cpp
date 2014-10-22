
// Lesson 8 - Prime and Composite Numbers
// Flags
// Find the maximum number of flags that can be set on mountain peaks.

int solution(vector<int> &A) {
    int N = A.size(), min_distance = N;
    vector<int> peaks;
    for (int i = 1; i < N - 1; i++) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            if (!peaks.empty()) {
                min_distance = min(min_distance, i - peaks.back());
            }
            peaks.emplace_back(i);
        }
    }
    if (peaks.empty()) return 0;
    int n = peaks.size(), last = peaks.front(), count = 1;
    for (const int& p : peaks) {
        if (p - last >= n) {
            ++count;
            last = p;
        }
    }
    return count;
}
