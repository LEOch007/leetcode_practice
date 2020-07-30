//
// Created by linjliang on 2020/7/30.
//

/*
 * 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
 

提示：

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。

 */

#include <vector>
using namespace std;

class Solution {
public:
    // O(n) space: Hashing into another array
    int firstMissingPositive0(vector<int>& nums) {
        if (nums.size() == 0) return 1;

        bool cnt[nums.size()];
        for (int i = 0; i < nums.size(); ++i) { cnt[i] = false; }

        for (int i = 0; i < nums.size(); ++i) {
            long idx = (long)nums[i]-1;       // to avoid overflow
            if ((idx>=0) && (idx<nums.size())) cnt[idx] = true;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (cnt[i] == false) return i+1;
        }
        return nums.size()+1;
    }

    // O(1) space: Hashing into itself by swapping
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;

        for (int i = 0; i < nums.size(); ) {
            if ((nums[i]>0) && (nums[i]<=nums.size())) {
                int idx = nums[i]-1;
                if (i!=idx) swap(nums[i],nums[idx]);
                else i++;
            } else{
                i++;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i]<=0) || (nums[i]>nums.size())){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};