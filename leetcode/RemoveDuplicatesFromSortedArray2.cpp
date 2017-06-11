class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int num   = nums[0];
        int count = 1;
        int i     = 1;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[j] != num) {
                num = nums[j];
                count = 1;
                nums[i++] = num;
            }
            else if (++count <= 2) {
                nums[i++] = num;
            }
        }
        return i;
    }
};