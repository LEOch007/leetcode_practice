//
// Created by linjliang on 2020/9/10.
//

/*
 * 给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。

示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。

注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        // state
        vector<int> dp(nums.size());
        vector<int> cnt_dp(nums.size());
        // init
        fill(cnt_dp.begin(), cnt_dp.end(), 1);
        fill(dp.begin(), dp.end(), 1);

        // function
        for (int i = 1; i < nums.size(); ++i) {
            int cnt = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;    // update state
                        cnt = cnt_dp[j];
                    }
                    else if (dp[j]+1 == dp[i]) {
                        cnt += cnt_dp[j];
                    }
                }
            }
            cnt_dp[i] = cnt;
        }

        // answer
        int max_l = dp[0];
        for (int i = 1; i < dp.size(); ++i) {
            if (dp[i] > max_l){ max_l = dp[i]; }
        }
        int ans = 0;
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i] == max_l){ ans += cnt_dp[i]; }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,2,2,2,2};

    Solution s;
    cout<<s.findNumberOfLIS(nums)<<endl;
}

/*
 * Note:
 *
 * 定义状态dp[i]为 以i结尾的最长上升子序列的长度
 * 而cnt_dp[i] 则记录以i结尾的最长上升子序列的长度有多少个：
 * 若是更新dp[i] 则更新cnt_dp[i]
 * 若是和之前dp[i]相等 则表明新增了cnt_dp[j]种可能
 */