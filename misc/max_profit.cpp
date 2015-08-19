// Design an algorithm that determines the maximum profit that could be made
// by buying and then selling a single share over a given day range.

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
using namespace std;

// O(n^2) solution
double maxProfit1(const vector<double>& prices)
{
    double maxProfit = 0;
    for (size_t i = 0; i < prices.size(); ++i) {
        for (size_t j = i + 1; j < prices.size(); ++j) {
            maxProfit = max(maxProfit, prices[j] - prices[i]);
        }
    }
    return maxProfit;
}

// O(nlogn) solution
typedef vector<double>::const_iterator ConstIt;
double helper(ConstIt left, ConstIt right)
{
    if (right - left <= 1) {
        return 0;
    }
    ConstIt middle = left + (right - left) / 2;
    return max(max(helper(left, middle), helper(middle, right)),
               *max_element(middle, right) - *min_element(left, middle));
}
double maxProfit2(const vector<double>& prices)
{
    return helper(prices.begin(), prices.end());
}

// O(n) solution
double maxProfit3(const vector<double>& prices)
{
    double minSoFar  = prices[0];
    double maxProfit = 0;
    for (double price : prices) {
        minSoFar  = min(minSoFar, price);
        maxProfit = max(price - minSoFar, maxProfit);
    }
    return maxProfit;
}

int main()
{
    vector<double> prices = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    random_device rd;
    mt19937 g(rd());
    shuffle(prices.begin(), prices.end(), g);
    cout << "Prices : ";
    copy(prices.begin(), prices.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
    cout << "Max Profit 1 = " << maxProfit1(prices) << endl;
    cout << "Max Profit 2 = " << maxProfit2(prices) << endl;
    cout << "Max Profit 3 = " << maxProfit3(prices) << endl;
}
