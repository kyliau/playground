
// Lesson 8 - Prime and Composite Numbers
// Flags
// Find the maximum number of flags that can be set on mountain peaks.

vector<bool> create_peaks(const vector<int>& A) {
    vector<bool> peaks(A.size(), false);
    int N = A.size();
    for (int i = 1; i < N - 1; ++i) {
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            peaks[i] = true;
        }
    }
    return peaks;
}

vector<int> next_peak(const vector<int>& A) {
    int N = A.size();
    vector<bool> peaks = create_peaks(A);
    vector<int> next(N, 0);
    next[N - 1] = -1;
    for (int i = N - 2; i >= 0; --i) {
        if (peaks[i]) next[i] = i;
        else next[i] = next[i+1];
    }
    return next;
}

int solution(vector<int> &A) {
    int N = A.size();
    vector<int> next = next_peak(A);
    int i = 1, result = 0;
    while ((i - 1) * i <= N) {
        int pos = 0, num = 0;
        while (pos < N && num < i) {
            pos = next[pos];
            if (pos == -1) break;
            ++num;
            pos += i;
        }
        result = max(result, num);
        ++i
    }
    return result;
}
