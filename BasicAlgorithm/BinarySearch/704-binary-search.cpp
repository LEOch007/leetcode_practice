//
// Created by linjliang on 2020/8/1.
//

/*
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
 * 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

 示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。

 */

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;

        int i = 0;
        int j = nums.size()-1;
        while ( i+1 < j ){
            int mid = (i+j)/2;
            if (nums[mid]>target)
                j = mid;
            else if (nums[mid]<target)
                i = mid;
            else
                return mid;
        }
        int idx = -1;
        if (nums[nums.size()-1]==target) idx = nums.size()-1;
        if (nums[0]==target) idx = 0;
        return idx;
    }
};

/*
 * Note:
 *
 * 要注意，二分查找的终止条件是：start+1 < end，
 * 故而要另外验证数组长度为0、1、2时候算法的正确性
 */