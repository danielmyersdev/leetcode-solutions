/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string& firstString = strs[0];
        size_t longestPrefixSize = firstString.size();

        for (size_t i = 1; i < strs.size() && longestPrefixSize != 0; ++i) 
        {
            std::string& currString = strs[i];

            if (currString.size() < longestPrefixSize) 
            {
                longestPrefixSize = currString.size();
            }

            for (size_t j = 0; j < longestPrefixSize; ++j) 
            {
                if (firstString[j] != currString[j]) 
                {
                    longestPrefixSize = j;
                    break;
                }
            }
        }

        return firstString.substr(0, longestPrefixSize);

    }
};
// @lc code=end

