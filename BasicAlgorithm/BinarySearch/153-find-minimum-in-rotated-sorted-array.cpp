//
// Created by linjliang on 2020/8/3.
//

/*
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1

示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin0(vector<int>& nums) {
        if (nums.size() == 0) return -1;

        int i = 0;
        int j = nums.size()-1;
        while (i+1<j){
            int mid = (i+j)/2;
            if (nums[mid] > nums[i])
                i = mid;
            else if (nums[mid] > nums[mid-1])
                j = mid;
            else
                return nums[mid];
        }
        return min(nums[0],nums[nums.size()-1]);
    }

    // 更优雅通用的解法，把数组最后一个数当成target
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return -1;

        int i = 0;
        int j = nums.size()-1;
        while (i+1<j){
            int mid = (i+j)/2;
            if (nums[mid]<=nums[j])
                j = mid;
            else
                i = mid;
        }
        return min(nums[i],nums[j]);
    }
};

int main(){
    vector<int> nums = {3,4,5,1,2};

    Solution s;
    cout<<s.findMin(nums)<<endl;
}

/*
 * Note:
 *
 * 找最大最小值的题目，一定要注意是返回数值本身，还是返回最大最小值的索引下标
 */