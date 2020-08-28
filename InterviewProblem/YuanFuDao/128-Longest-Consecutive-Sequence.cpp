//
// Created by linjliang on 2020/8/28.
//

/*
 * 给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。


链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;

        unordered_map<int, int> mp;     // 哈希表
        for (int i = 0; i < nums.size(); ++i) {
            mp.insert(make_pair(nums[i],1));
        }

        int global_max = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // 确保从最大的连续数值开始往下找
            if (mp.find(nums[i]+1) != mp.end()) continue;

            int tmp = nums[i];
            int cnt = 1;
            while (mp.find(tmp-1) != mp.end()){
                tmp--;
                cnt++;
            }

            global_max = max(global_max, cnt);
        }
        return global_max;
    }
};

/*
 * Note:
 *
 * 利用哈希表O(1)时间来查找数据
 * 特别地，要避免嵌套循环查找O(n^2)，这里是确保从可能的连续数值中最大的数开始往下查找，来确保O(n)线性时间
 */