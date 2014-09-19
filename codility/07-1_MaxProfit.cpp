
// Lesson 7 - Maximum Slice Problem
// MaxProfit
// Given a log of stock prices compute the maximum possible earning.

#include <algorithm>
int solution(vector<int> &A) {
    if (A.empty()) return 0;
    int min = A[0], profit = 0;
    for (int a : A) {
        if (a < min) {
            min = a;
        }
        profit = max(profit, a - min);
    }
    return profit;
}
