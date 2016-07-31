// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed, the only constraint
// stopping you from robbing each of them is that adjacent houses have
// security system connected and it will automatically contact the police
// if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money
// of each house, determine the maximum amount of money you can rob tonight
// without alerting the police.

/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    var n = nums.length;
    if (n === 0) {
        return 0;
    }
    if (n === 1) {
        return nums[0];
    }
    nums[1] = Math.max(nums[0], nums[1]);
    for (var i = 2; i < n; ++i) {
        nums[i] = Math.max(nums[i] + nums[i - 2], nums[i - 1]);
    }
    return nums[n - 1];
};
