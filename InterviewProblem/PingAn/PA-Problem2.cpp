//
// Created by linjliang on 2020/9/18.
//

// Sure

#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算数组中任意四个数的和，判断是否等于目标值，返回所有满足条件的四元组
     * @param nums int整型vector 整型数组
     * @param target int整型 目标值
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        if (nums.size()<4) return {};

        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size()-3; ++i) {
            if (i>0 && nums[i]==nums[i-1]) continue;    // 去重

            for (int j = i+1; j < nums.size()-2; ++j) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;  // 去重

                int sub_target = target-nums[i]-nums[j];
                unordered_map<int,int> mp;
                for (int k = j+1; k < nums.size(); ++k) {
                    if (mp.find( sub_target-nums[k] ) != mp.end()){
                        ans.insert( {nums[i],nums[j],sub_target-nums[k],nums[k]} );
                    }

                    mp[nums[k]] = 1;
                }
            }
        }

        vector<vector<int>> result (ans.begin(),ans.end());
        return result;
    }
};