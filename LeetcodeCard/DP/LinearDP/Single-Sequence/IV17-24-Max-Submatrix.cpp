//
// Created by linjliang on 2020/9/16.
//

/*
 * 给定一个正整数和负整数组成的 N × M 矩阵，编写代码找出元素总和最大的子矩阵。

返回一个数组 [r1, c1, r2, c2]，其中 r1, c1 分别代表子矩阵左上角的行号和列号，r2, c2 分别代表右下角的行号和列号。
若有多个满足条件的子矩阵，返回任意一个均可。

注意：本题相对书上原题稍作改动

示例:

输入:
[
   [-1,0],
   [0,-1]
]
输出: [0,1,0,1]
解释: 输入中标粗的元素即为输出所表示的矩阵

说明：
1 <= matrix.length, matrix[0].length <= 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-submatrix-lcci
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 一维数组: 找到最大的连续子数组和 所在区间
    vector<int> getMaxRange(vector<int>& nums){
        if (nums.size()==1) return {0,0, nums[0]};

        vector<int> prex(nums.size());
        prex[0] = nums[0];
        for (int i = 1; i < prex.size(); ++i) {
            prex[i] = prex[i-1]+nums[i];
        }

        int max_idx = 0;
        int min_idx = 0;

        int global_max = INT_MIN;
        int min_v = 0; int min_v_id = -1;
        for (int i = 0; i < prex.size(); ++i) {
            if (prex[i]-min_v > global_max){
                global_max = prex[i]-min_v;
                max_idx = i;
                min_idx = min_v_id+1;
            }

            if (prex[i] < min_v){
                min_v = prex[i];
                min_v_id = i;
            }
        }
        return {min_idx, max_idx, global_max};
    }

    // 二维数组最大子矩阵 转化为 一维数组最大子序列
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() <= 0) return {};
        if (matrix[0].size() <= 0) return {};
        if (matrix.size()==1 && matrix[0].size()==1) return {0,0,0,0};

        const int row = matrix.size();
        const int col = matrix[0].size();

        vector<vector<int>> prex_row(row, vector<int>(col));
        for (int i = 0; i < col; ++i) { prex_row[0][i] = matrix[0][i]; }
        for (int i = 1; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                prex_row[i][j] = prex_row[i-1][j] + matrix[i][j];
            }
        }

        int global_max = INT_MIN;
        int min_rid = 0; int max_rid = 0;
        int min_cid = 0; int max_cid = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = i; j < row; ++j) {
                vector<int> re;
                if (i==j){
                    re = getMaxRange(prex_row[i]);
                    if (re[2] > global_max){
                        global_max = re[2];
                        min_cid = re[0];
                        max_cid = re[1];
                        min_rid = 0;        //  此处不同：不需要减去前面部分
                        max_rid = j;
                    }
                }
                else {
                    vector<int> nums(col);
                    for (int k = 0; k < col; ++k) {
                        nums[k] = prex_row[j][k] - prex_row[i][k];
                    }
                    re = getMaxRange(nums);
                    if (re[2] > global_max){
                        global_max = re[2];
                        min_cid = re[0];
                        max_cid = re[1];
                        min_rid = i+1;
                        max_rid = j;
                    }
                }

            }
        }

        return {min_rid, min_cid, max_rid, max_cid};
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    vector<vector<int>> matrix = {{1},{-7}};

    Solution s;
    vector<int> re = s.getMaxMatrix(matrix);
    for(auto r:re) cout<<r<<" ";
}

/*
 * Note:
 *
 * 将二维子矩阵问题 转化为 一维子序列问题
 */