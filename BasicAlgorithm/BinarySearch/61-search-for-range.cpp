//
// Created by linjliang on 2020/8/2.
//

/* 来自 lintcode九章算法
 *
 * 给定一个包含 n 个整数的排序数组，找出给定目标值 target 的起始和结束位置。

如果目标值不在数组中，则返回[-1, -1]

样例
例1:

输入:
[]
9
输出:
[-1,-1]

例2:

输入:
[5, 7, 7, 8, 8, 10]
8
输出:
[3, 4]

挑战
时间复杂度 O(log n)

 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> result = {-1,-1};
        if (A.size() == 0) return result;

        int i = 0;
        int j = A.size()-1;
        while (i+1<j){
            int mid = (i+j)/2;
            if (target<A[mid])
                j = mid;
            else if (target>A[mid])
                i = mid;
            else {
                int index1 = mid-1;
                int index2 = mid+1;
                while ((A[index1] == target)&&(index1>=0)) index1--;
                while ((A[index2] == target)&&(index2<A.size())) index2++;

                result[0] = index1+1;
                result[1] = index2-1;
                return result;
            }
        }
        if (A[0] == target){
            result[0] = 0;
            result[1] = 0;
            return result;
        }
        if (A[A.size()-1] == target){
            result[0] = A.size()-1;
            result[1] = A.size()-1;
            return result;
        }
        return result;
    }
};

int main(){
    vector<int> A = {-1,0,1,2,2,2,3,3,3,4,4,4,5,5,6,90,92,93,101};
    int target = 2;

    Solution s;
    vector<int> result = s.searchRange(A,target);
    for(auto num: result) cout<<num<<" ";
}

/*
 * Note:
 *
 * 排序数组找到所有target的索引：
 * 先二分查找找到target，然后左右两边扫确定target的索引范围
 */