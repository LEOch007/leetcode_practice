//
// Created by linjliang on 2020/8/4.
//

/*
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true

示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false

进阶:
这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

 */

#include <vector>
using namespace std;

class Solution {
public:
    int findMinIdx(vector<int> &nums){
        int i = 0;
        int j = nums.size()-1;
        while (i+1<j){
            while (i<j && nums[j]==nums[j-1]) j--;
            while (i<j && nums[i]==nums[i+1]) i++;

            int mid = (i+j)/2;
            if (nums[mid]<=nums[j])
                j = mid;
            else
                i = mid;
        }
        return nums[i]<nums[j] ? i:j;
    }

    bool searchCore(vector<int> &nums, int start, int end, int target){
        if (start>end) return false;

        int i = start;
        int j = end;
        while (i+1<j){
            int mid = (i+j)/2;
            if (nums[mid]<target)
                i = mid;
            else if (nums[mid]>target)
                j = mid;
            else
                return true;
        }
        if (nums[start] == target) return true;
        else if (nums[end] == target) return true;
        return false;
    }

    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;

        int idx = findMinIdx(nums);
        bool ans = searchCore(nums,0,idx-1,target) || searchCore(nums,
                idx,nums.size()-1,target);
        return ans;
    }
};

/*
 * Note:
 *
 * 该题和Leetcode 33类似，可划分为两个问题：
 * 1）找到最小值的索引，将其作为拆分点，
 * 2）对其前半部分升序数组和后半部分升序数组 BinarySearch查找目标值target
 *
 * 和Leetcode 33的区别在于：本题的数组允许存在重复值，属于更通用的情况
 * 故而在找最小值的索引环节上，需要做点小调整：跳过重复值，回到原问题
 */