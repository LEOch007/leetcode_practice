//
// Created by linjliang on 2020/8/12.
//

/*
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

 */

#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        if (grid[0].size() == 0) return 0;

        // state
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols));
        // int dp[rows][cols];

        // initialize
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < cols; ++i) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        // function
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }

        // answer
        return dp[rows-1][cols-1];
    }
};

/*
 * Note:
 *
 * 动态规划四要素：
 * - 状态 state
 * - 方程 function
 * - 初始化 initialize
 * - 答案 answer
 */