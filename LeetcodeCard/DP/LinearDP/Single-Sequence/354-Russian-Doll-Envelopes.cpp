//
// Created by linjliang on 2020/9/10.
//

/*
 * 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。
 * 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/russian-doll-envelopes
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        bool ans;
        if (a[0]<b[0]) ans = true;
        else if (a[0]>b[0]) ans = false;
        else{
            if (a[1]<b[1]) ans = true;
            else ans = false;
        }
        return ans;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() <= 1) return envelopes.size();

        sort(envelopes.begin(), envelopes.end(), cmp);

        // state
        vector<int> dp(envelopes.size());
        // init
        fill(dp.begin(), dp.end(), 1);
        // function
        for (int i = 1; i < envelopes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        // answer
        int ans = dp[0];
        for (int i = 1; i < dp.size(); ++i) {
            if (dp[i] > ans) ans = dp[i];
        }
        return ans;
    }
};