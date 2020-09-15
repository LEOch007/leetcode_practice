//
// Created by linjliang on 2020/9/15.
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

#include <vector>
using namespace std;

class Solution {
public:
    int Kaneda(vector<int>& A, int start, int end, int sign){
        int global_max = sign*A[start];
        int local = sign*A[start];
        for (int i = start+1; i <= end; ++i) {
            local = max(sign*A[i], sign*A[i]+local);
            global_max = max(global_max, local);
        }
        return global_max;
    }

    int maxSubarraySumCircular(vector<int>& A) {
        if (A.size()==1) return A[0];

        // 单区间
        int max1 = Kaneda(A,0,A.size()-1,1);

        // 双区间
        int sum = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
        }

        int sub_max1 = Kaneda(A,0,A.size()-2,-1);
        int sub_max2 = Kaneda(A, 1, A.size()-1, -1);
        int max2 =  max(sum+sub_max1, sum+sub_max2);

        return max(max1,max2);
    }
};

/*
 * Note:
 *
 * 将环形数组问题分解为 单区间问题（old problem）和 双区间问题（new problem）的最大值
 * 前者老问题可快速解决；
 * 而后者也可转化为整个数组的和 减去某一部分连续子数组和的最小值，即整个数组的和 加上负值的某一部分连续子数组和的最大值；
 * 此外，为了避免整个数组减去整个数组的情况，负值的连续子数组应该按 0～倒数第二个 和 1～倒数最后一个位置 来分别计算
 */