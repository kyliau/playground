// You are given coins of different denominations and a total amount of money.
// Write a function to compute the number of combinations that make up that
// amount. You may assume that you have infinite number of each kind of coin.
//
// Note: You can assume that
//
// 0 <= amount <= 5000
// 1 <= coin <= 5000
// the number of coins is less than 500
// the answer is guaranteed to fit into signed 32-bit integer
//
// Example 1:
// Input  : amount = 5, coins = [1, 2, 5]
// Output : 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
//
// Example 2:
// Input  : amount = 3, coins = [2]
// Output : 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
//
// Example 3:
// Input  : amount = 10, coins = [10]
// Output : 1

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
  public:
    int change(int amount, const vector<int>& coins) {
        int rows = amount + 1; // take 0 into account
        int cols = coins.size();
        vector<vector<int>> v(rows, vector<int>(cols));
        for (int j = 0; j < cols; ++j) {
            v[0][j] = 1;    // there is only 1 possible case when value is 0
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int coin = coins[j];
                // We take coin j into account (so the set is coin[0..j])
                int x = i - coin < 0 ? 0 : v[i - coin][j];
                // We don't take coin j into account
                // (so the set is coin[0..j-1])
                int y = j - 1 < 0 ? 0 : v[i][j - 1];
                v[i][j] = x + y;
            }
        }
        return v.back().back();
    }
};

class Solution {
  public:
    int change(int amount, const vector<int>& coins) {
        vector<int> v(amount + 1);
        v[0] = 1;   // there is only 1 possible way when value = 0
        for (int i = 0; i < coins.size(); ++i) {
            for (int val = coins[i]; val <= amount; ++val) {
                v[val] += v[val - coins[i]];
            }
        }
        return v.back();
    }
};

int main() {
    const struct {
        int         n;
        int         amount;
        vector<int> coins;
        int         expected;
    } CASES[] = {
        { 1, 5, { 1, 2, 5 }, 4 }
    };
    const int NUM_CASES = sizeof(CASES) / sizeof(CASES[0]);
    for (int i = 0; i < NUM_CASES; ++i) {
        int   n        = CASES[i].n;
        int   amount   = CASES[i].amount;
        auto& coins    = CASES[i].coins;
        int   expected = CASES[i].expected;
        cout << "Test case " << n << " ... ";
        Solution s;
        int result = s.change(amount, coins);
        if (result == expected) {
            cout << "PASS";
        }
        else {
            cout << "FAIL (Expect " << expected << " but got " << result << ")";
        }
        cout << endl;
    }
    return 0;
}