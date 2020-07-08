//
// Created by linjliang on 2020/6/30.
//

/*
    分治法应用:  先分别处理局部，再合并结果

    适用场景:
    - 归并排序
    - 快速排序
    - 二叉树相关问题

    分治法模板:
    - 递归返回条件
    - 分段处理
    - 合并结果
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(vector<int> left_nums, vector<int> right_nums) {
    vector<int> result = {};

    // O(n)时间空间复杂度 有序地合并两条有序数组
    int i = 0; int j = 0;
    while ((i<left_nums.size())&&(j<right_nums.size())){
        if(left_nums[i]<=right_nums[j]) { result.push_back(left_nums[i++]); }
        else { result.push_back(right_nums[j++]); }
    }

    if (i>=left_nums.size()){
        vector<int> right_back (right_nums.begin()+j, right_nums.end());
        result.insert(result.end(),right_back.begin(),right_back.end());
    }

    if (j>=right_nums.size()){
        vector<int> left_back (left_nums.begin()+i, left_nums.end());
        result.insert(result.end(),left_back.begin(),left_back.end());
    }

    return result;
}

vector<int> MergeSort(vector<int> nums){
    // 递归返回条件
    if (nums.size()<=1){return nums;}

    // 分段处理
    int mid = nums.size()/2;
    vector<int> left_nums (nums.begin(), nums.begin()+mid);  // left half
    vector<int> right_nums (nums.begin()+mid, nums.end());   // right half

    vector<int> left_result = MergeSort(left_nums);
    vector<int> right_result = MergeSort(right_nums);

    // 合并结果
    vector<int> result = Merge(left_result,right_result);
    return result;
}

int main(){
    //vector<int> nums = {2,4,-77,8,3,1};
    vector<int> nums = {24,-2,3,6,8,5,1,-12,9,88,4};

    vector<int> result = MergeSort(nums);
    for(int n: result) cout<<n<<" ";


}
