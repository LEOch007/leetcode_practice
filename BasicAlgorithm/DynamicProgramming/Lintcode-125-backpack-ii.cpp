//
// Created by linjliang on 2020/9/22.
//

/*
 * 有 n 个物品和一个大小为 m 的背包. 给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.

问最多能装入背包的总价值是多大?

样例
样例 1:

输入: m = 10, A = [2, 3, 5, 7], V = [1, 5, 2, 4]
输出: 9
解释: 装入 A[1] 和 A[3] 可以得到最大价值, V[1] + V[3] = 9

样例 2:

输入: m = 10, A = [2, 3, 8], V = [2, 5, 8]
输出: 10
解释: 装入 A[0] 和 A[2] 可以得到最大价值, V[0] + V[2] = 10

挑战
O(nm) 空间复杂度可以通过, 不过你可以尝试 O(m) 空间复杂度吗?

注意事项:
A[i], V[i], n, m 均为整数
你不能将物品进行切分
你所挑选的要装入背包的物品的总大小不能超过 m
每个物品只能取一次

 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // state
        const int n = A.size();
        vector<int> dp(m+1);
        // init
        fill(dp.begin(), dp.end(), 0);

        // function
        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= A[i]; --j) {
                dp[j] = max(dp[j], dp[j-A[i]]+V[i]);
            }
        }
        // answer
        return dp[m];
    }
};

/*
 * Note:
 *
 * 和Lintcode-92-backpack 很类似，都属于01背包问题；
 * 可通过倒序遍历容量，实现状态压缩，二维降为一维
 */