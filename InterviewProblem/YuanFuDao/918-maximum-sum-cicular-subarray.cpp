//
// Created by linjliang on 2020/8/25.
//

/*
 * 给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。

在此处，环形数组意味着数组的末端将会与开头相连呈环状。
（形式上，当0 <= i < A.length 时 C[i] = A[i]，而当 i >= 0 时 C[i+A.length] = C[i]）

此外，子数组最多只能包含固定缓冲区 A 中的每个元素一次。
（形式上，对于子数组 C[i], C[i+1], ..., C[j]，不存在 i <= k1, k2 <= j 其中 k1 % A.length = k2 % A.length）


示例 1：

输入：[1,-2,3,-2]
输出：3
解释：从子数组 [3] 得到最大和 3
示例 2：

输入：[5,-3,5]
输出：10
解释：从子数组 [5,5] 得到最大和 5 + 5 = 10
示例 3：

输入：[3,-1,2,-1]
输出：4
解释：从子数组 [2,-1,3] 得到最大和 2 + (-1) + 3 = 4
示例 4：

输入：[3,-2,2,-3]
输出：3
解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
示例 5：

输入：[-2,-3,-1]
输出：-1
解释：从子数组 [-1] 得到最大和 -1
 

提示：

-30000 <= A[i] <= 30000
1 <= A.length <= 30000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-sum-circular-subarray
 */

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    // 前缀和 + 单调队列
    // O(n)时间复杂度 O(n)空间复杂度
    int maxSubarraySumCircular0(vector<int>& A) {
        if (A.size() == 1) return A[0];

        int N = A.size();
        // 求前缀和
        vector<int> prex(2*N+1);
        prex[0] = 0;
        for (int i = 1; i < prex.size(); ++i) {
            prex[i] = prex[i-1] + A[(i-1)%N];
        }

        // 利用单调队列得到prex[j]的最小值 且要满足 i-j<=N
        deque<int> dq_idx;
        dq_idx.push_front(0);
        int global_max = INT_MIN;
        for (int i = 1; i < prex.size(); ++i) {
            // j需要满足 i-j<=N
            while (i - dq_idx.front() > N){ dq_idx.pop_front(); }

            int curr_max = prex[i] - prex[dq_idx.front()];
            global_max = max(global_max, curr_max);

            // 保证deque队头的索引对应的是最小值
            while (!dq_idx.empty() && prex[i]<=prex[dq_idx.back()]){
                dq_idx.pop_back();
            }
            dq_idx.push_back(i);
        }
        return global_max;
    }

    int Kadane(vector<int> &A, int start, int end, const int sign){
        int prev_max = sign*A[start];
        int global_max = prev_max;
        for (int i = start+1; i <= end; ++i) {
            prev_max = sign*A[i] + max(prev_max,0);
            global_max = max(global_max, prev_max);
        }
        return global_max;
    }

    // 利用Kadane算法 + 正负号
    int maxSubarraySumCircular(vector<int>& A){
        if (A.size() == 1) return A[0];

        int N = A.size();
        // 单区间
        int ans1 = Kadane(A,0,N-1,1);

        // 双区间: 注意要保证子数组非空
        int sumA = 0;
        for (int i = 0; i < N; ++i) {
            sumA += A[i];
        }
        int ans2 = sumA + Kadane(A, 0, N-2, -1);
        int ans3 = sumA + Kadane(A, 1, N-1, -1);

        int global_max = max(ans1, max(ans2, ans3));
        return global_max;
    }
};

/*
 * Note:
 *
 * 类似求解 最大子数组和，求解 环形最大子数组和，同样有两种思路：
 *
 * - 基于前缀和：
 *   将原数组扩展2倍，数组A变成B=A+A
 *   用一个单调队列保存之前访问过的prex前缀和最小值，并要保证i-j<=N
 *
 * - 基于Kadane：
 *   将环形数组分解为两种情况，一种是单区间[i,j]，另一种是双区间[0,i]+[j,N-1]
 *   对单区间问题采用普通Kadane方法
 *   对双区间问题转化为 整个数组的和sumA - \sum_{k=i+1}^{j-1} A_k, 后者即为负号状态下的单区间Kadane问题
 *   此外要特别注意子数组要求非空，故而如上述代码所示，要分为[0,N-2]和[1,N-1]来避免求出[0,N-1]负号Kadane，则为空集的状态
 */