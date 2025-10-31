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
        if (x < 10) {
            return true;
        }
        
        // x < 2^31 - 1.
        char xVec[10];
        size_t lastDigit = 0;
        while (x != 0) {
            xVec[lastDigit] = x % 10;
            x /= 10;
            ++lastDigit;
        }

        // Check palindrome
        for (size_t i = 0; i < lastDigit / 2; ++i) {
            if (xVec[i] != xVec[lastDigit-1-i]) return false;
        }
        return true;
    }
};
// @lc code=end

