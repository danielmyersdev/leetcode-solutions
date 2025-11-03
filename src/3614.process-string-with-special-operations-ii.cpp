/*
 * @lc app=leetcode id=3614 lang=cpp
 *
 * [3614] Process String with Special Operations II
 */

// @lc code=start
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Solution
{
public:
    char processStr(string s, long long k)
    {
        constexpr char outOfBoundsChar = '.';
        if (k < 0)
            return outOfBoundsChar;
        // Find the size of the string
        long long processedStrSize = 0;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (isLowercase(*it))
            {
                ++processedStrSize;
            }
            else if (*it == '*')
            {
                if (processedStrSize > 0) {
                    --processedStrSize;
                }
            }
            else if (*it == '#')
            {
                processedStrSize *= 2;
            }
            // do nothing if *it == '%'
        }

        // Get original char by reversing instructions
        if (k >= processedStrSize)
        {
            return outOfBoundsChar;
        }

        size_t currStringSize = processedStrSize;
        for (auto it = s.end(); it != s.begin(); --it)
        {
            char instruction = *(it - 1);
            if (isLowercase(instruction))
            {
                --currStringSize;
                if (currStringSize == k)
                {
                    return instruction;
                }
            }
            else if (instruction == '*')
            {
                ++currStringSize;
            }
            else if (instruction == '#')
            {
                currStringSize /= 2;
                if (k >= currStringSize)
                {
                    k -= currStringSize;
                }
            }
            else if (instruction == '%')
            {
                k = currStringSize - 1 - k;
            }
        }

        throw runtime_error("This shouldn't ever throw.");
    }

private:
    static inline bool isLowercase(char c)
    {
        int cInt = static_cast<int>(c);
        return static_cast<int>('a') <= cInt && cInt <= static_cast<int>('z');
    }
};
// @lc code=end
