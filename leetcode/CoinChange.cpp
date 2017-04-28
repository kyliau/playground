// You are given coins of different denominations and a total amount of money
// amount. Write a function to compute the fewest number of coins that you need
// to make up that amount. If that amount of money cannot be made up by any
// combination of the coins, return -1.
//
// Example 1:
// coins = [1, 2, 5], amount = 11
// return 3 (11 = 5 + 5 + 1)
//
// Example 2:
// coins = [2], amount = 3
// return -1.
//
// Note:
// You may assume that you have an infinite number of each kind of coin.

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int coinChange(const vector<int>& coins, int amount) {
        vector<int> v(amount + 1, -1);
        v[0] = 0;
        for (int i = 1; i < amount + 1; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    int prev = v[i - coins[j]];
                    if (prev >= 0) {
                        int result = 1 + prev;
                        v[i] = v[i] < 0 ? result : std::min(v[i], result);
                    }
                }
            }
        }
        return v[amount];
    }
};

int main() {
    const struct {
        int         n;
        vector<int> coins;
        int         amount;
        int         expected;
    } CASES[] = {
        { 1, { 1, 5, 10, 25 }, 33,  5 },
        { 2, {            1 }, 10, 10 },
        { 3, {         3, 5 },  7, -1 },
    };
    int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int                n        = CASES[i].n;
        const vector<int>& coins    = CASES[i].coins;
        int                amount   = CASES[i].amount;
        int                expected = CASES[i].expected;
        Solution s;
        cout << "Test case " << n << " ... ";
        int result = s.coinChange(coins, amount);
        if (result == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expected " << expected << " but got " << result
                 << ")";
        }
        cout << endl;
    }
    return 0;
}