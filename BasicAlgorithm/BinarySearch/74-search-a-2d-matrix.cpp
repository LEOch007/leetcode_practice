//
// Created by linjliang on 2020/8/3.
//

/*
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

 示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true

 示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int len = rows*cols;

        int i = 0;
        int j = len-1;
        while (i+1<j){
            int mid = (i+j)/2;
            if (matrix[mid/cols][mid%cols] < target)
                i = mid;
            else if (matrix[mid/cols][mid%cols] > target)
                j = mid;
            else
                return true;
        }
        if (matrix[0][0] == target) return true;
        if (matrix[rows-1][cols-1] == target) return true;
        return false;
    }
};

/*
 * Note:
 *
 * 该题二维数组可转化为一维数组来解决，故而回归到熟悉的原始二分查找问题
 */