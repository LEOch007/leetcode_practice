//
// Created by linjliang on 2020/9/4.
//

/*
 * 输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof
 */

#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    set<string> result_set;

    void permutationCore(string& s, int idx){
        if (idx == s.size()-1){
            result_set.insert(s);
            return;
        }

        for (int i = idx; i < s.size(); ++i) {
            swap(s[idx], s[i]);        // idx 位置排好了
            permutationCore(s,idx+1); // 递归排接下来的位置
            swap(s[idx],s[i]);         // 换回来
        }
    }

    vector<string> permutation(string s) {
        if (s.size()==0) return {};
        if (s.size()==1) return {s};

        int idx = 0;
        permutationCore(s, idx);

        vector<string> result(result_set.begin(),result_set.end());
        return result;
    }
};

/*
 * Note:
 *
 * 整个思想是递推思想：1）排好当前位置，2）对接下来的元素进行全排列
 * 用set是为了避免 全排列交换位置后 相同的情况
 */