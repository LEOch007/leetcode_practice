//
// Created by linjliang on 2020/8/19.
//

/*
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

进阶:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int pre_sum = 0;
        int min_pre_sum = 0;    // 前缀和 初始既有0这一项
        int max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            pre_sum += nums[i];
            int local_max_sum = pre_sum - min_pre_sum;

            min_pre_sum = min(min_pre_sum, pre_sum);
            max_sum = max(max_sum, local_max_sum);
        }

        return max_sum;
    }
};

/*
 * Note:
 *
 * 利用前缀和 对连续子数组问题建模
 */