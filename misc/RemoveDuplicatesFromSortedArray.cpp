#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = 1, j = 2;
    while (i < nums.size()) {
        int curr = nums[i];
        int prev = nums[i - 1];
        if (curr <= prev) {
            while (j < nums.size() && nums[j] <= prev) {
                ++j;
            }
            if (j < nums.size()) {
                nums[i] = nums[j];
            } else {
                break;
            }
        }
        ++i;
        ++j;
    }
    return i;
}

int main()
{
    while (1) {
        int x;
        vector<int> v;
        while (cin >> x) {
            v.emplace_back(x);
        }
        cout << "Length of new array = " << removeDuplicates(v) << endl;
        ostream_iterator<int> it(cout, " ");
        copy(v.begin(), v.end(), it);
        cout << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
}
