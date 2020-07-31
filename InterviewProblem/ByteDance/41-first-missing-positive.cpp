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

#include <iostream>
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

    // O(1) space: Hashing into itself via index
    int firstMissingPositive(vector<int>& nums) {
        // Negative value should be saved for Hash Mark
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]<=0) nums[i] = nums.size()+1;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int abs_num = abs(nums[i]);
            if ((abs_num>0)&&(abs_num<=nums.size())){
                int idx = abs_num-1;
                if (nums[idx]>0) nums[idx] = -nums[idx];
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]>=0) return i+1;
        }
        return nums.size()+1;
    }

    // O(1) space: Continuous Region Sorting by swapping
    int firstMissingPositive2(vector<int>& nums) {
        if (nums.size() == 0) return 1;

        for (int i = 0; i < nums.size(); ) {
            if ((nums[i]>0) && (nums[i]<=nums.size())) {
                int idx = nums[i]-1;
                if (nums[i]!=nums[idx]) swap(nums[i],nums[idx]);
                else i++;
            } else{
                i++;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

int main(){
    vector<int> nums = {1,1};

    Solution s;
    cout<<s.firstMissingPositive(nums)<<endl;
}

/*
 * Note:
 *
 * 利用哈希表，一般可通过O(n)时间高效地处理问题，但会引入O(n)空间，
 * 而原地哈希的思想，可以降为O(1)常数空间复杂度
 *
 * 利用排序来解决问题，一般需要O(nlogn)时间来完成排序的操作，
 * 但针对于连续区间的排序，即该区间内，数据是连续不断开的，可通过交换至其对应位置的方式实现，只需O(n)时间复杂度
 */