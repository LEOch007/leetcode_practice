//
// Created by linjliang on 2020/8/25.
//

/*
 * 给定一个二维矩阵N*N 求最大的子矩阵和：
 *
 * Given a two-dimensional array of positive and negative integers,
 * a sub-rectangle is any contiguous sub-array of size 1*1 or greater located within the whole array.
 * The sum of a rectangle is the sum of all the elements in that rectangle.
 * In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle.

 As an example, the maximal sub-rectangle of the array:

0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

 is in the lower left corner:

9 2
-4 1
-1 8
and has a sum of 15.

Input:

The input consists of an N * N array of integers. The input begins with a single positive integer N
on a line by itself, indicating the size of the square two-dimensional array.
This is followed by N^2 integers separated by whitespace (spaces and newlines). These are the N^2
integers of the array, presented in row-major order. That is, all numbers in the first row, left to right,
then all numbers in the second row, left to right, etc. N may be as large as 100. The numbers in
the array will be in the range [-127,127].

Output:

Output the sum of the maximal sub-rectangle.

Sample Input:
4
0 -2 -7 0 9 2 -6 2 -4 1 -4  1 -1 8  0 -2
Sample Output:
15

Link: http://poj.org/problem?id=1050
 */

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N; cin>>N;
    vector<vector<int>> nums(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin>>nums[i][j];
        }
    }

    vector<vector<int>> sum_nums(N, vector<int>(N));
    for (int k = 0; k < N; ++k) { sum_nums[0][k] = nums[0][k]; }
    for (int i = 1; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            sum_nums[i][k] = sum_nums[i-1][k] + nums[i][k];
        }
    }

    int global_sum = INT_MIN;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            int prev_sum = 0;
            for (int k = 0; k < N; ++k) {
                // 第i行到第j行的和
                if (i==0){
                    arr[k] = sum_nums[j][k];
                } else{
                    arr[k] = sum_nums[j][k] - sum_nums[i-1][k];
                }
                prev_sum = max(arr[k], arr[k]+prev_sum);
                global_sum = max(global_sum, prev_sum);
            }
        }
    }

    cout<<global_sum<<endl;
}

/*
 * Note:
 *
 * 最大子矩阵和 是最大子序列和的二维拓展;
 *
 * 最大子序列和的解法较为明确：
 * prev_sum = max(arr[i], arr[i]+prev_sum)
 * 统计prev_sum里头的最大值
 * 比暴力求解O(n^2) -> O(n)
 *
 * 而最大子矩阵和则可 通过计算i~j行的和化归为arr[k]
 * 以列作为唯一维度的一维最大子序列和
 * 将新问题化归为老问题，同样可解
 * 比暴力求解O(n^4) -> O(n^3)
 */