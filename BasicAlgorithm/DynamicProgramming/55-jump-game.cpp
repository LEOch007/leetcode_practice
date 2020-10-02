//
// Created by linjliang on 2020/10/2.
//

/*
 * 给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。

示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
 */

#include <vector>
using namespace std;

class Solution {
public:
    // 动态规划 O(n^2)时间复杂度
    bool canJump0(vector<int>& nums) {
        if (nums.size()==0) return false;
        if (nums.size()==1) return true;

        // state
        vector<bool> dp(nums.size());   // dp[i]: 能否从0跳到i
        // init
        dp[0] = true;

        // function
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && i-j<=nums[j]){ // 能从0跳到j 并且能从j跳到i
                    dp[i] = true;
                    break;
                }
            }
        }
        // answer
        return dp[dp.size()-1];
    }

    // 贪心 O(n)时间复杂度
    bool canJump(vector<int>& nums) {
        if (nums.size()==0) return false;
        if (nums.size()==1) return true;

        int rightmost = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > rightmost) return false;
            rightmost = max(rightmost, i+nums[i]);  // 更新最远可达的位置
        }
        // 表明最后一个位置会小于等于rightmost
        return true;
    }
};