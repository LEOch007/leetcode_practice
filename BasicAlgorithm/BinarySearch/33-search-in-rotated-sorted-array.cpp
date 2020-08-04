//
// Created by linjliang on 2020/8/4.
//

/*
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

 */

#include <vector>
using namespace std;

class Solution {
public:
    int findMinIdx(vector<int> &nums){
        int i = 0;
        int j = nums.size()-1;
        while (i+1<j){
            int mid = (i+j)/2;
            if (nums[mid]<nums[j])
                j = mid;
            else
                i = mid;
        }
        return nums[i]<nums[j] ? i:j;
    }

    int searchCore(vector<int> &nums, int start, int end, int target){
        if (start>end) return -1;

        int i = start;
        int j = end;
        while (i+1<j){
            int mid = (i+j)/2;
            if (nums[mid]<target)
                i = mid;
            else if (nums[mid]>target)
                j = mid;
            else
                return mid;
        }
        if (nums[start] == target) return start;
        if (nums[end] == target) return end;
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;

        int idx = findMinIdx(nums);
        int ans1 = searchCore(nums,0,idx-1, target);
        int ans2 = searchCore(nums,idx,nums.size()-1, target);

        if (ans1 == -1) return ans2;
        else return ans1;
    }
};

/*
 * Note:
 *
 * 该题可划分为找到最小值的索引，将其作为拆分点，对其前半部分和后半部分分别查找目标值target，
 * 由于前半部分是升序数组，后半部分也是升序数组，均可采用二分查找，
 * 而找到最小值的索引，也可以通过二分查找，故整体查找效率高，O(logn)时间复杂度
 */