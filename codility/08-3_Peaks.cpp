
// Lesson 8 - Prime and Composite Numbers
// Peaks
// Divide an array into the maximum number of same((-))sized blocks, 
// each of which should contain an index P such that 
// A[P - 1] < A[P] > A[P + 1].

#include <set>
int solution(vector<int> &A) {
    
    int N = A.size();
    if (N < 3) return 0;
    
    int* peak = new int[N];
    peak[0] = 0;
    int prev = 0;
    for (int i = 1; i < N - 1; i++) {
        peak[i] = peak[i-1] + prev;
        if (A[i] > A[i-1] && A[i] > A[i+1]) {
            peak[i]++;
        }
    }
    peak[N-1] = peak[N-2];
    
    set<int> groups;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            groups.insert(i);
            groups.insert(N / i);
        }
    }
    
    // there are i elements in one group
    for (int i : groups) {
        if (i < 3) continue;
        bool is_peak = true;
        int peak_seen = 0;
        for (int j = 0; j < N; j += i) {
            if (peak[j+i-1] == peak_seen) {
                is_peak = false;
                break;
            }
            peak_seen = peak[j+i-1];
        }
        if (is_peak) return N / i;
    }       
    
    return 0;

}

