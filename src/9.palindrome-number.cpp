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
        
        // Construct palindrome string
        std::vector<int> xVec;
        while (x != 0) {
            xVec.push_back(x % 10);
            x /= 10;
        }

        // Check palindrome
        size_t numDigits = xVec.size();
        for (size_t i = 0; i < numDigits / 2; ++i) {
            if (xVec[i] != xVec[numDigits-1-i]) return false;
        }
        return true;
    }
};
// @lc code=end

