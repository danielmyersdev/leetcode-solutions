/*
 * @lc app=leetcode id=3612 lang=cpp
 *
 * [3612] Process String with Special Operations I
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    string processStr(string s)
    {
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
        return result;
    }

private:
    static inline bool isLowercase(char c)
    {
        int cInt = static_cast<int>(c);
        return static_cast<int>('a') <= cInt && cInt <= static_cast<int>('z');
    }

    static void reverse(string& str)
    {
        const size_t strLength = str.length();
        for (size_t i = 0; i < strLength/2; ++i) {
            char temp = str[i];
            str[i] = str[strLength-1-i];
            str[strLength-1-i] = temp;
        }
    }
};
// @lc code=end
