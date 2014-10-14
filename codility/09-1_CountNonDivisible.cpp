
// Lesson 9 - Sieve of Eratosthenes
// CountNonDivisible
// Calculate the number of elements of an array that are not divisors of each element.

// WIP

#include <math.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

// prepare the array F for factorization
int sieve(int n, unordered_multiset<int>& set) {
    cout << "The divisors of " << n << " are: ";
    int result = 1;
    vector<int> F(n + 1, 0);
    int i = 2;
    while (i * i <= n) {
        if (F[i] == 0) {
            int k = i * i;
            while (k <= n) {
                if (F[k] == 0) {
                    F[k] = i;
                    result += set.count(k);
                    cout << k << " ";
                }
                k += i;
            }
        }
        ++i;
    }
    cout << endl;
    return result;
}

/*
int factorization(int x, const unordered_multiset<int>& set) {
    vector<int> F = sieve(x);
    int result = 1;
    while (F[x] > 0) {
        result += set.count(F[x]);
        x /= F[x];
    }
    return result;
}
*/

vector<int> solution(vector<int> &A) {
    vector<int> B(A);
    sort(B.begin(), B.end());
    unordered_map<int, int> hash;
    for (const int& b : B) {
        if (hash.find(b) != hash.end()) continue;
        auto it = lower_bound(B.begin(), B.end(), b + 1);
        int count = B.end() - it;
        for (auto i = B.begin(); i != it; ++i) {
            if (b % *i != 0) {
                count++;
            }
        }
        hash[b] = count;
    }
    
    int N = A.size();
    vector<int> result(N);
    for (int i = 0; i < N; ++i) {
        //result[i] = N - factorization(A[i], set);
        //result[i] = N - sieve(0.5 * A[i], set);
        result[i] = hash[A[i]];
    }
    
    return result;
}
