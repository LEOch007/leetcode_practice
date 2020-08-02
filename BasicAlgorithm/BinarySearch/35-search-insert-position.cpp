//
// Created by linjliang on 2020/8/2.
//

/*
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
 * 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;

        int i = 0;
        int j = nums.size()-1;
        while (i+1<j){
            int mid = (i+j)/2;
            if (target < nums[mid]){
                j = mid;
                if (target > nums[mid-1]) return mid;
            }
            else if (target > nums[mid]){
                i = mid;
                if (target < nums[mid+1]) return mid+1;
            }
            else
                return mid;
        }
        if (target <= nums[0]) return 0;
        if (target <= nums[nums.size()-1]) return nums.size()-1;
        else return nums.size();
    }
};

/*
 * Note:
 *
 * 运用二分查找来解决问题时，要特别注意数组长度为0、1、2时候的情况
 */