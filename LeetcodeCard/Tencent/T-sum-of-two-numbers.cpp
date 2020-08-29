//
// Created by linjliang on 2020/8/28.
//

/*
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。


示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/tencent/xxqfy5/
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // O(n^2) Time; O(1) Space
    vector<int> twoSum0(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {0,0};
    }

    // O(n) Time; O(n) Space
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(target-nums[i]) != mp.end()){ // 找得到之前出现的另一个数加和为target
                int idx = mp[target-nums[i]];
                return {idx,i};
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return {0,0};
    }
};

/*
 * Note:
 *
 * 每当涉及到需要优化数组查找时间复杂度时，应当首先考虑引入 哈希表；
 * 寻找如何利用哈希表优化当前时间复杂度的解决方案；
 */