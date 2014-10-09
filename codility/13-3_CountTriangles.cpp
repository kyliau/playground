
// Lesson 13 - Caterpillar Method
// CountTriangles
// Count the number of triangles that can be built from a given set of edges.

#include <algorithm>
int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int N = A.size();
    int result = 0;
    for (int i = 0; i < N; i++) {
        int k = 0;
        for (int j = i + 1; j < N; j++) {
            while (k < N && A[i] + A[j] > A[k]) {
                k++;
            }
            result += k - j - 1;
        }
    }
    return result;
}
