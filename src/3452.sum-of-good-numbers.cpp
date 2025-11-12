/*
 * @lc app=leetcode id=3452 lang=cpp
 *
 * [3452] Sum of Good Numbers
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (isGood(nums, k, i)) {
                sum += nums[i];
            }
        }
        return sum;
    }

private:
    inline bool isGood(vector<int>& nums, int k, int i) {
        bool leftGood = i - k < 0 || nums[i-k] < nums[i];
        bool rightGood = i + k >= nums.size() || nums[i+k] < nums[i];
        return leftGood && rightGood;
    }
};
// @lc code=end

