//
// Created by linjliang on 2020/9/18.
//

/*
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
 * 使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size()<4) return {};

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        // O(n^3) 时间复杂度
        for (int i = 0; i < nums.size()-3; ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;    // 去重

            for (int j = i+1; j < nums.size()-2; ++j) {
                if (j>i+1 && nums[j]==nums[j-1]) continue; // 去重

                // 双指针
                int k = j+1;
                int l = nums.size()-1;
                while (k<l){
                    if (nums[i]+nums[j]+nums[k]+nums[l] < target) k++;
                    else if (nums[i]+nums[j]+nums[k]+nums[l] > target) l--;
                    else {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        while (k<l && nums[k]==nums[k-1]) k++; // 去重
                        l--;
                        while (k<l && nums[l]==nums[l+1]) l--; // 去重
                    }
                }
            }
        }

        return ans;
    }
};

/*
 * Note:
 *
 * 1. 四数之和问题 转化为 两数之和问题
 * 2. 排序数组 通过 双指针的方法 解决两数之和问题
 *
 * 四行去重代码也很关键 确保最后结果不会有重复的四元组
 */