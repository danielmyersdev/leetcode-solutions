/*
 * @lc app=leetcode id=3370 lang=cpp
 *
 * [3370] Smallest Number With All Set Bits
 */

// @lc code=start
#include <cassert>
#include <climits>

class Solution {
public:
    int smallestNumber(int n) {

        // Find largest bit
        int c = 1 << (sizeof(int)*8-2);
        int returnVal = n & c;
        while (returnVal == 0) {
            c >>= 1;
            returnVal = n & c;
        }

        // Fill right of number with 1
        while (c != 0) {
            c >>= 1;
            returnVal |= c;
        }
        
        return returnVal;
    }
};
// @lc code=end

