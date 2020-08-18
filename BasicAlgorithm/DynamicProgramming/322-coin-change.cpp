//
// Created by linjliang on 2020/8/17.
//

/*
 * 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
 * 如果没有任何一种硬币组合能组成总金额，返回 -1。

 
示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3
解释: 11 = 5 + 5 + 1

示例 2:

输入: coins = [2], amount = 3
输出: -1
 

说明:
你可以认为每种硬币的数量是无限的。

 */

#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (coins.size() == 0) return -1;

        // state
        vector<int> dp(amount+1);

        // intial
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            dp[i] = amount+1;
        }

        // function
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i-coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }

        // answer
        if (dp[amount] >= amount+1) return -1;
        else return dp[amount];
    }
};

/*
 * Note:
 *
 * 背包问题：状态转移方程一定要引入背包元素
 */