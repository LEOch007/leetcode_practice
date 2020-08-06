//
// Created by linjliang on 2020/8/6.
//

/*
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

 
例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

 
说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        if (triangle[0].size() == 0) return 0;

        int rows = triangle.size();
        int cols = triangle[rows-1].size()+1;
        long long dp[rows][cols];

        // 初始化
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        dp[0][1] = triangle[0][0];

        // DP
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < triangle[i].size()+1; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j-1];
            }
        }

        // 返回最小值
        long long min_value = dp[rows-1][1];
        for (int j = 2; j < cols; ++j) {
            if (dp[rows-1][j] < min_value) min_value = dp[rows-1][j];
        }
        return min_value;
    }
};

int main(){
    vector<vector<int>> triangle = {{-1},{-2,-3}};

    Solution s;
    cout << s.minimumTotal(triangle) <<endl;
}

/*
 * Note:
 *
 * 关于如何在Debug模式下查看数组元素：
 * 增加查看：*(long long(*)[10])(dp)
 * long long可替换为对应数据类型，10可替换为要查看的内容，dp替换为要查看的数组对象
 *
 */