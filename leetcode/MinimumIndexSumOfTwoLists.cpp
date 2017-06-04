class Solution {
  public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> table;
        table.reserve(list1.size());
        for (int i = 0; i < list1.size(); ++i) {
            table[list1[i]] = i;
        }
        int sum = list1.size() + list2.size();
        for (int j = 0; j < list2.size(); ++j) {
            auto it = table.find(list2[j]);
            if (it != table.end() && it->second + j < sum) {
                sum = it->second + j;
            }
        }
        vector<string> results;
        for (int j = 0; j < list2.size(); ++j) {
            auto it = table.find(list2[j]);
            if (it != table.end() && it->second + j == sum) {
                results.emplace_back(list2[j]);
            }
        }
        return results;
    }
};