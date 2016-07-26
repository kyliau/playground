// Given a collection of distinct numbers, return all possible permutations.
// For example,
// [1,2,3] have the following permutations:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

class Solution {
private:
    size_t factorial(int n) {
        size_t result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
    
    void addToResult(vector<vector<int>>& vv,
                     vector<int>&         v,
                     int                  n,
                     int                  size) {
        for (int i = 0; i < v.size(); ++i) {
            vv.emplace_back();
            vv.back().reserve(size);
            for (int j = 0; j < v.size(); ++j) {
                if (i == j) {
                    vv.back().emplace_back(n);
                }
                vv.back().emplace_back(v[j]);
            }
        }
        v.emplace_back(n);
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }
        result.reserve(factorial(nums.size()));
        result.emplace_back();
        result.back().reserve(nums.size());
        result.back().emplace_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            int n = result.size();
            for (int j = 0; j < n; ++j) {
                addToResult(result, result[j], nums[i], nums.size());
            }
        }
        return result;
    }
};
