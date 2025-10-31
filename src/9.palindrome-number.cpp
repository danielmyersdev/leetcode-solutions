/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        long original = x;
        long reverse = 0;
        while (x != 0) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }

        return original == reverse;
    }
};
// @lc code=end

