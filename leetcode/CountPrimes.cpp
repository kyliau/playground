// Count the number of prime numbers less than a non-negative number, n.

// Trying to store only odd numbers
// Added complexity, but doesn't seem to improve performance...

class Prime {
private:
    int          d_num;
    vector<bool> d_sieve;
public:
    inline
    Prime(int n) : d_num(n) {
        d_sieve.resize(n / 2, true);
        if (d_sieve.size() > 0) {
            d_sieve[0] = false;
        }
    }
    inline
    bool isPrime(int n) {
        if (n % 2 == 0) {
            return n == 2;
        }
        return d_sieve[n / 2];
    }
    inline
    void updateSieve(int n) {
        if (n % 2 == 0) {
            return;
        }
        for (int i = n * n; i < d_num; i += n) {
            if (i % 2 == 1) {
                d_sieve[i / 2] = false;
            }
        }
    }
    inline
    int countPrimes() {
        int count = d_num <= 2 ? 0 : 1;
        for (int i = 0; i < d_num / 2; ++i) {
            if (d_sieve[i]) {
                ++count;
            }
        }
        return count;
    }
};

class Solution {
public:
    int countPrimes(int n) {
        Prime prime(n);
        for (int i = 2; i * i < n; ++i) {
            if (prime.isPrime(i)) {
                prime.updateSieve(i);
            }
        }
        return prime.countPrimes();
    }
};
