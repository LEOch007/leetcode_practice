//
// Created by linjliang on 2020/8/19.
//

/*
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // O(n^2) time complexity
    int subarraySum0(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;

        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {     // include i-th element
            int sum = 0;
            for (int j = i; j >= 0; --j) {
                sum += nums[j];
                if (sum == k) cnt++;
            }
        }

        return cnt;
    }

    // O(n) time complexity
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;

        int cnt = 0;    // possible subarrays
        int pre = 0;    // prefix sum
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            pre += nums[i];
            if (mp.find(pre-k) != mp.end()) {
                cnt += mp[pre-k];
            }
            mp[pre] ++;
        }

        return cnt;
    }
};

/*
 * Note:
 *
 * 利用前缀和 对连续子数组问题建模，
 * 引入哈希表加快查找速度
 */