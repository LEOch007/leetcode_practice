//
// Created by linjliang on 2020/9/5.
//

/*
 * 给你一个整数数组 nums ，
 * 请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。


示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size()==1) return nums[0];

        // state
        vector<int> dp_max(nums.size());    // 以nums[i]结尾的连续数组的 最大乘积
        vector<int> dp_min(nums.size());    // 以nums[i]结尾的连续数组的 最小乘积

        // initial
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];

        // function
        for (int i = 1; i < nums.size(); ++i) {
            dp_max[i] = max(dp_max[i-1]*nums[i], max(dp_min[i-1]*nums[i], nums[i]));
            dp_min[i] = min(dp_max[i-1]*nums[i], min(dp_min[i-1]*nums[i], nums[i]));
        }

        // answer
        int ans = dp_max[0];
        for (int i = 1; i < dp_max.size(); ++i) {
            if (dp_max[i] > ans) ans = dp_max[i];
        }
        return ans;
    }
};

/*
 * Note:
 *
 * 由于乘积最大值 除了之前最大的正整数乘积*当前正数，还有可能是由最小的负整数乘积*当前负数 得到
 * 故而需要两个dp数组来保存两个不同的状态：
 * - dp_max[i] : 以nums[i]结尾的连续数组的 最大乘积
 * - dp_min[i] : 以nums[i]结尾的连续数组的 最小乘积
 */