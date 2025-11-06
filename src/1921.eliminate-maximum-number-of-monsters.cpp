/*
 * @lc app=leetcode id=1921 lang=cpp
 *
 * [1921] Eliminate Maximum Number of Monsters
 */

// @lc code=start
#include <functional>
#include <queue>
#include <vector>

class Solution
{
public:
    int eliminateMaximum(std::vector<int> &dist, std::vector<int> &speed)
    {
        int numMonsters = dist.size();
        std::priority_queue<int, std::vector<int>, std::greater<int>> latestSuccessfulAttackTimes;

        // Calculate attack times
        for (size_t i = 0; i < numMonsters; ++i)
        {
            int latestSuccessfulAttackTime = dist[i] / speed[i];
            bool isExactDivision = dist[i] % speed[i] == 0;
            if (isExactDivision)
                --latestSuccessfulAttackTime;
            latestSuccessfulAttackTimes.emplace(latestSuccessfulAttackTime);
        }

        // Simulate game
        for (int currTime = 0; currTime < numMonsters; ++currTime)
        {
            int requiredAttackTime = latestSuccessfulAttackTimes.top();
            if (currTime > requiredAttackTime) 
            {
                return currTime;
            }
            latestSuccessfulAttackTimes.pop();
        }

        return numMonsters;
    }
};
// @lc code=end
