//
// Created by linjliang on 2020/8/27.
//

/*
 * 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray0(vector<int>& nums) {
        if (nums.size() == 0) return -1;

        // state
        vector<int> dp(nums.size());
        // initial
        dp[0] = nums[0];

        // function
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = nums[i] + max(dp[i-1],0);
        }
        // answer
        int max_v = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i] > max_v) max_v = dp[i];
        }
        return max_v;
    }

    int maxSubArray(vector<int>& nums){
        if (nums.size() == 0) return -1;

        int pre_max = nums[0];
        int global_max = pre_max;
        for (int i = 1; i < nums.size(); ++i) {
            pre_max = nums[i] + max(pre_max,0);
            global_max = max(global_max, pre_max);
        }
        return global_max;
    }
};

/*
 * Note:
 *
 * 连续子数组的最大和是一道经典题：
 *
 * 1. 可应用Kadane算法：（基于动态规划思想，四要素）
 * - 状态dp[i]：表示以nums[i]结尾的连续子数组的最大值
 * - 转移方程：dp[i] = nums[i] + max(dp[i-1],0)
 *           表明dp[i]肯定要纳入结尾的nums[i]，是否要纳入之前的数据，取绝于之前的最大和是否大于0
 * - 初始化: dp[0] = nums[0]
 * - 返回结果： max(dp) dp数组中的最大值
 *
 * 可将上述过程简化为两个变量，
 * - 用pre_max保存dp[i-1]，更新dp[i]；
 * - 用global_max时刻更新全局最大值
 *
 * 2. 可利用前缀和
 * - 找到 prex[i]-prex[j-1] && i>=j-1 的最大值 即为该问题要求的最大值
 * 具体参考 Leetcode53题:(本工程文档下)
 * InterviewProblem/ByteDance/53-maximum-subarray.cpp
 */