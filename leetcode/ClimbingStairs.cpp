// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
        // cache the results
        int count[n + 1] = { 0 };
        count[0] = 1;
        count[1] = 1;
        for (int i = 2; i <= n; ++i) {
            count[i] = count[i - 1] + count[i - 2];
        }
        return count[n];
    }
};
