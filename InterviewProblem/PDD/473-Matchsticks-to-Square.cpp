//
// Created by linjliang on 2020/9/9.
//

/*
 * 还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。
 * 不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例 1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。

示例 2:

输入: [3,3,3,3,4]
输出: false

解释: 不能用所有火柴拼成一个正方形。
注意:

给定的火柴长度和在 0 到 10^9之间。
火柴数组的长度不超过15。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/matchsticks-to-square
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool dfs(vector<int>& nums, int idx, vector<int>& side, const long long& side_length){
        if (idx >= nums.size()){
            bool ans = side[0]==side_length && side[1]==side_length &&
                    side[2]==side_length && side[3]==side_length;
            return ans;
        }

        for (int i = 0; i < side.size(); ++i) {
            if (side[i]+nums[idx] <= side_length){
                side[i] += nums[idx];
                if (dfs(nums,idx+1,side,side_length)) return true;
                side[i] -= nums[idx];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& nums) {
        if (nums.size() == 0) return false;

        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        bool ans = false;
        if (sum%4 == 0) {
            long long side_length = sum / 4;
            vector<int> side = {0,0,0,0};

            // 对nums从大到小排序 以对回溯剪枝 否则会超时
            sort(nums.begin(),nums.end(),greater<int>());
            ans = dfs(nums, 0, side, side_length);
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {3,3,3,3,4};
    Solution s;
    cout<<s.makesquare(nums)<<endl;
}

/*
 * Note:
 *
 * TODO: 经典回溯问题 目前还不太懂 有空回来看看
 */
