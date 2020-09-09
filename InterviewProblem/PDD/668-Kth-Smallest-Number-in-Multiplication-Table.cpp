//
// Created by linjliang on 2020/9/9.
//

/*
 * 几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？

给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。

例 1：

输入: m = 3, n = 3, k = 5
输出: 3
解释:
乘法表:
1	2	3
2	4	6
3	6	9

第5小的数字是 3 (1, 2, 2, 3, 3).

例 2：

输入: m = 2, n = 3, k = 6
输出: 6
解释:
乘法表:
1	2	3
2	4	6

第6小的数字是 6 (1, 2, 2, 3, 4, 6).
注意：

m 和 n 的范围在 [1, 30000] 之间。
k 的范围在 [1, m * n] 之间。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-number-in-multiplication-table
 */

#include <vector>
using namespace std;

class Solution {
public:
    bool cnt_rank(int num, int m, int n, int k){
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            cnt += min(num/i, n);
        }
        return cnt >= k;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        while (low<high){
            int mid = (low+high) >> 1;
            if (cnt_rank(mid, m, n, k)) high = mid;
            else low = mid+1;
        }

        return high;
    }
};

/*
 * Note:
 *
 * 这道题难度高，要想能够分析出最佳方案，要注意到这个矩阵是一个有序矩阵，可以利用二分查找的思想
 *
 * 初始化 low = 1; high = m*n;
 * 不停地取中间值，判断该中间值的排位（可通过遍历行/列，计算得到小于等于改值的数的个数，即为该值的排位）
 * 然后若该值排序大于等于k，则 high指向mid； 否则 low指向mid
 *
 * 最终结果是low和high会相遇，由于high一直指向排位大于等于k的数，而low往下比较小的数排位小于k，
 * low high重合则意味着 我们找到了"最紧"的排位大于等于k的数，即排位等于k的数
 */