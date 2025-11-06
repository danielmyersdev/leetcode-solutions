/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
#include <algorithm>
#include <queue>
#include <vector>

class Solution
{
public:
    int eliminateMaximum(std::vector<int> &dist, std::vector<int> &speed)
    {
        int numMonsters = dist.size();
        std::vector<int> latestSuccessfulAttackTimes;

        // Calculate attack times
        for (size_t i = 0; i < numMonsters; ++i)
        {
            int latestSuccessfulAttackTime = dist[i] / speed[i];
            bool isExactDivision = dist[i] % speed[i] == 0;
            if (isExactDivision)
                --latestSuccessfulAttackTime;
            latestSuccessfulAttackTimes.push_back(latestSuccessfulAttackTime);
        }
        std::sort(latestSuccessfulAttackTimes.begin(), latestSuccessfulAttackTimes.end());

        // Simulate game
        for (int currTime = 0; currTime < numMonsters; ++currTime)
        {
            int requiredAttackTime = latestSuccessfulAttackTimes[currTime];
            if (currTime > requiredAttackTime) 
            {
                return currTime;
            }
        }

        return numMonsters;
    }
};
// @lc code=end
