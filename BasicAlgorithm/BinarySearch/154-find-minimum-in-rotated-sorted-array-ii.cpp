//
// Created by linjliang on 2020/8/3.
//

/*
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

输入: [1,3,5]
输出: 1
示例 2：

输入: [2,2,2,0,1]
输出: 0

 */

#include <vector>
using namespace std;

class Solution {
public:
    int findMinbySearch(vector<int> &nums, int i, int j){
        int idx_min = i;
        for (i = i+1; i <=j; ++i) {
            if (nums[i]<nums[idx_min]) idx_min = i;
        }
        return idx_min;
    }

    int findMin0(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        else if (nums.size() == 1) return nums[0];

        int i = 0;
        int j = nums.size()-1;
        int mid = i;
        while (nums[i]>=nums[j]){
            if (j-i==1){
                mid = j;
                break;
            }

            mid = (i+j)/2;
            if (nums[mid]==nums[i] && nums[mid]==nums[j]){
                mid = findMinbySearch(nums,i,j);
                break;
            }
            if (nums[mid]>=nums[i])
                i = mid;
            else if (nums[mid]<=nums[j])
                j = mid;
        }
        return nums[mid];
    }

    // 更优雅通用的解法，把数组最后一个数当成target
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return -1;

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
        return min(nums[i],nums[j]);
    }
};

/*
 * Note:
 *
 * 这道题属于困难题，比起Leetcode 153的题，区别在于可以有重复元素；
 *
 * 方法一：
 * 处理的思路为引入两个指针i、j，i永远指向未旋转过的上升序列，j指向旋转后的上升序列，
 * 直到它们相邻，i即指向未旋转过的序列尾，j即指向旋转过的序列头，此时j指向的数即为全局最小值
 *
 * 特别之处在于重复元素，当i、j、mid指向的数值相同时，难以区分mid处于两种序列的哪一个，
 * 此时只能遍历i、j之间的数组元素，去找到最小值
 *
 * -------------------------------------------------------------------------
 *
 * 方法二：更优雅
 * 同样引入两个指针i、j，i永远指向未旋转过的上升序列，j指向旋转后的上升序列，
 * 将数组最后一个数当成target，去判断mid是处于哪个序列
 * 直到它们相邻，i即指向未旋转过的序列尾，j即指向旋转过的序列头，此时返回俩者中的最小值（更通用
 *
 * 对重复数值的特别处理是：跳过重复数字，然后回归到熟悉的问题，较为巧妙
 */