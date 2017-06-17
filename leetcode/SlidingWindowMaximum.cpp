class Solution {
  public:
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        const int n = nums.size();
        std::deque<int> deq;
        vector<int> results;
        for (int i = 0; i < n; ++i) {
            while (!deq.empty() && deq.front() < i - k + 1) {
                deq.pop_front();
            }
            while (!deq.empty() && a[deq.back()] < a[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
            if (i >= k - 1) {
                results.emplace_back(a[deq.front()]);
            }
        }
        return results;
    }
};