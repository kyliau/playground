
// Lesson 9 - Sieve of Eratosthenes
// CountNonDivisible
// Calculate the number of elements of an array that are not divisors of each element.

#include <unordered_set>
#include <unordered_map>
#include <algorithm>

// this solution is not O(n log n), but it passes the all test cases
// it is O(sqrt(n) * n) thus O(n ^ 1.5)

int count_divisors_in_array(int x, const vector<int>& B) {
    unordered_set<int> divisors {1, x};
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            divisors.insert(i);
            divisors.insert(x / i);
        }
    }
    int result = 0;
    for (const int& d : divisors) {
        result += B[d];
    }
    return result;
}
            
vector<int> solution(vector<int> &A) {
  vector<int> B(*max_element(A.begin(), A.end()) + 1, 0);
  for (const int& a : A) {
      ++B[a];
  }
  int N = A.size();
  vector<int> result(N);
  unordered_map<int, int> cache;
  for (int i = 0; i < N; ++i) {
      auto it = cache.find(A[i]);
      if (it != cache.end()) {
          result[i] = it->second;
      } else {
        result[i] = N - count_divisors_in_array(A[i], B);
        cache[A[i]] = result[i];
      }
  }
  return result;
}

