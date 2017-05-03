// Given an array S of n integers, are there elements a, b, c in S such that
// a + b + c = 0? Find all unique triplets in the array which gives the sum of
// zero.
//
// Note: The solution set must not contain duplicate triplets.
//
// For example, given array S = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
    stream << "[";
    for (int i = 0; i < v.size(); ++i) {
        stream << (i == 0 ? "" : ", ") << v[i];
    }
    stream << "]";
    return stream;
}

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int i = 0; i < nums.size(); ++i) {
            if (0 < i && nums[i] == nums[i - 1]) {
                continue;
            }
            int x      = nums[i];
            int target = -x;
            int left   = i + 1;
            int right  = nums.size() - 1;
            while (left < right) {
                int y = nums[left];
                int z = nums[right];
                int sum = y + z;
                if (sum == target) {
                    results.push_back({ x, y, z });
                    while (left < right && nums[left] == y) {
                        ++left;
                    }
                    while (left < right && nums[right] == z) {
                        --right;
                    }
                }
                else if (sum < target) {
                    ++left;
                }
                else {  // sum > target
                    --right;
                }
            }
        }
        return results;
    }
};

int main() {
    vector<int> v = { -1, 0, 1, 2, -1, -4 };
    Solution s;
    cout << s.threeSum(v) << endl;
}