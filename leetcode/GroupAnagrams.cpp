// Given an array of strings, group anagrams together.
// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:
// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:
// For the return value, each inner list's elements must follow the lexicographic order.
// All inputs will be in lower-case.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> myMap;
        for (const auto& str : strs) {
            string s(str);
            sort(s.begin(), s.end());
            myMap[s].emplace_back(str);
        }
        for (auto& p : myMap) {
            auto& v = p.second;
            sort(v.begin(), v.end());
            result.emplace_back(v);
        }
        return result;
    }
};
