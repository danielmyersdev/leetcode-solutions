/*
 * @lc app=leetcode id=3222 lang=cpp
 *
 * [3222] Find the Winning Player in Coin Game
 */

// @lc code=start
#include <string>

class Solution {
public:
    std::string winningPlayer(int x, int y) {
        bool leftoverX = 4 * x > y;
        if (leftoverX) {
            if ((y/4) % 2 == 0) return "Bob";
            else return "Alice";
        } else {
            if (x % 2 == 0) return "Bob";
            else return "Alice";
        }
    }
};
// @lc code=end

