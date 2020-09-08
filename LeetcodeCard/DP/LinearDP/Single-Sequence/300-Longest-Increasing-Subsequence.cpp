//
// Created by linjliang on 2020/9/8.
//

/*
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

说明:
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2)
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
 */

#include <vector>
using namespace std;

class Solution {
public:
    // O(n^2)
    int lengthOfLIS0(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        // state
        vector<int> dp(nums.size());
        // init
        fill(dp.begin(),dp.end(),1);

        // function
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        // answer: max(dp)
        int ans = dp[0];
        for (int i = 1; i < dp.size(); ++i) {
            if (dp[i] > ans) ans = dp[i];
        }
        return ans;
    }

    // O(nlogn)
    // 找到刚好比num大的数 替换掉
    void replace_arr(vector<int>& arr, int num){
        int idx = -1;
        if (arr.size()==1) { idx = 0; arr[idx] = num; return;}
        if (arr.size()==2) { idx = 1 ?arr[0]<num:0; arr[idx] = num; return; }

        int i = 0;
        int j = arr.size()-1;
        while (true){
            if (i+1==j){
                idx = j;
                break;
            }

            int mid = (i+j) >> 1;
            if (arr[mid]<num){ i = mid; }
            else{ j = mid; }
        }
        // 特例：全都大于等于num
        if (j==1){ idx = 1 ?arr[0]<num:0; }
        arr[idx] = num;
    }

    int lengthOfLIS(vector<int>& nums){
        if (nums.size() == 0) return 0;

        vector<int> arr = {nums[0]};    // 上升序列
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > arr[arr.size()-1]){ arr.push_back(nums[i]); }
            else{
                replace_arr(arr, nums[i]);
            }
        }

        return arr.size();
    }
};

/*
 * Note:
 *
 * 方法一：动态规划，难点在于定义状态、找到状态转移方程，可通过例子分析dp[i]和dp[1]...dp[i-1]的关系
 *
 * 方法二：运用了贪心思想，维护一个递增子序列，且里头的值尽可能的小，
 *       故而每次遇到比递增子序列末尾最大数还要大的数，直接加入子序列，
 *       而小于等于的话，则化解为有序数组找到第一个大于等于num的位置，替换成num
 */