//
// Created by linjliang on 2020/9/21.
//

/*
 * 在n个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为m，每个物品的大小为A[i]

样例
样例 1:
	输入:  [3,4,8,5], backpack size=10
	输出:  9

样例 2:
	输入:  [2,3,5,7], backpack size=12
	输出:  12

挑战
O(n x m) 的时间复杂度 and O(m) 空间复杂度
如果不知道如何优化空间O(n x m) 的空间复杂度也可以通过.

注意事项
你不可以将物品进行切割。
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // state
        const int n = A.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        // init
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) { dp[i][j] = 0; }
        }

        // function
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (j>=A[i-1]){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]]+A[i-1]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // answer
        return dp[n][m];
    }
};

int main(){
    int m = 10;
    vector<int> nums = {3,4,8,5};

    Solution s;
    cout<<s.backPack(m,nums)<<endl;
}