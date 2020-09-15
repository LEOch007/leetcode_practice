//
// Created by linjliang on 2020/9/15.
//

/*
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()==1) return nums[0];

        int global_max = nums[0];
        int local_max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            local_max = max(nums[i], local_max+nums[i]);
            global_max = max(global_max, local_max);
        }

        return global_max;
    }
};

/*
 * Note:
 *
 * 经典题：可通过动态规划来思考
 * 最后可简化 无需保存所有dp状态 可将空间复杂度O(n)降为O(1)
 */