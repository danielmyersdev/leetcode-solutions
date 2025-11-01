/*
 * @lc app=leetcode id=3614 lang=cpp
 *
 * [3614] Process String with Special Operations II
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    char processStr(string s, long long k)
    {
        constexpr char outOfBoundsChar = '.';
        if (k < 0)
            return outOfBoundsChar;
        string result = "";
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            if (isLowercase(*it))
            {
                result.push_back(*it);
            }
            else if (*it == '*')
            {
                if (!result.empty())
                {
                    result.pop_back();
                }
            }
            else if (*it == '#')
            {
                result.append(result);
            }
            else
            {
                // assert *it == '%'
                reverse(result);
            }
        }
        if (k < result.size())
        {
            return result[k];
        }
        else
        {
            return outOfBoundsChar;
        }
    }

private:
    static inline bool isLowercase(char c)
    {
        int cInt = static_cast<int>(c);
        return static_cast<int>('a') <= cInt && cInt <= static_cast<int>('z');
    }

    static void reverse(string &str)
    {
        const size_t strLength = str.length();
        for (size_t i = 0; i < strLength / 2; ++i)
        {
            char temp = str[i];
            str[i] = str[strLength - 1 - i];
            str[strLength - 1 - i] = temp;
        }
    }
};
// @lc code=end
