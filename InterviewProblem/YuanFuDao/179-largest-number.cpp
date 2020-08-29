//
// Created by linjliang on 2020/8/29.
//

/*
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(string s1, string s2){
        return s1+s2 > s2+s1;
    }

    string largestNumber(vector<int>& nums) {
        if (nums.size()==0) return "";

        // to str
        vector<string> snums;
        for (int i = 0; i < nums.size(); ++i) {
            snums.push_back(to_string(nums[i]));
        }

        // sort via rule
        sort(snums.begin(),snums.end(), cmp);

        // concate
        string str = "";
        for (int i = 0; i < snums.size(); ++i) {
            str += snums[i];
        }

        // special case
        if (str[0] == '0') str = "0";
        return str;
    }
};

int main(){
    vector<int> nums = {3,8,15,30,79};
    Solution s;
    s.largestNumber(nums);
}

/*
 * Note:
 *
 * 关键在于两个点：
 * - 不是简单的字典序大的字符串就在前面：
 *   比如"30 3"，"30"字典序大，但是"303"组合起来的字典序 小于 "330"的字典序，
 *   故而我们需要自定义一个比较函数： s1+s2 > s2+s1 => true
 *
 * - 另一个点是特例："0000000"的存在
 *   我们需要返回的只有"0"，故而需要检测是否第一个字符都为"0"，是的话说明整个字符串均是"000..."，
 *   此时只返回一个"0"即可
 */