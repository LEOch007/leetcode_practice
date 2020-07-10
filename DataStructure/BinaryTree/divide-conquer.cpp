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

int Partition(vector<int> &nums, int start, int end){
    // 随机选择pivot
    int pos = start + (rand()%(end+1-start));   // select the index from [start, end]
    int pivot = nums[pos];
    swap(nums[start], nums[pos]);

    // 按pivot的大小分左右两边
    int i = start; int j = end+1;
    while (true){
        while ((nums[++i]<pivot) && (i!=end));
        while ((nums[--j]>pivot) && (j!=start));
        if (i>=j) { break;}
        swap(nums[i],nums[j]);
    }
    swap(nums[start],nums[j]);
    return j;
}

void QuickSort(vector<int> &nums, int start, int end){
    // 递归返回条件
    if (start >= end) return;

    // 分段处理
    int idx = Partition(nums, start,end);
    QuickSort(nums, start,idx-1);   // left part: < pivot
    QuickSort(nums, idx+1,end);    // right part: > pivot

    // 直接对传入数组操作 原地排序 不需另外合并
}

int main(){
    srand(time(nullptr));
    //vector<int> nums = {2,4,-77,8,3,1};
    //vector<int> nums = {24,-2,3,6,8,5,1,-12,9,88,4};
    //vector<int> nums = {2,4,-7,8,3,1,2,-7};
    vector<int> nums = {2,2,-4,2,2,3,5,1,2,2,2,1};

    cout<<"Merge Sort:\n";
    vector<int> result = MergeSort(nums);
    for(int n: result) cout<<n<<" ";
    cout<<endl;

    cout<<"Quick Sort:\n";
    QuickSort(nums,0,nums.size()-1);
    for(int n: nums) cout<<n<<" ";
    cout<<endl;
}
