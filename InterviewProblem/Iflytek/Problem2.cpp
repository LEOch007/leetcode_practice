//
// Created by linjliang on 2020/7/31.
//

#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int> &nums, int start, int end){
    int pos = start;
    int pivot = nums[pos];
    swap(nums[start], nums[pos]);

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
    if (start >= end) return;

    int idx = Partition(nums, start,end);
    for (auto num: nums) { cout<<num<<" "; }
    cout<<endl;

    QuickSort(nums, start,idx-1);   // left part: < pivot
    QuickSort(nums, idx+1,end);    // right part: > pivot

}

int main(){
    int n;
    vector<int> nums;
    int tmp;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>tmp;
        nums.push_back(tmp);
    }

    QuickSort(nums,0,nums.size()-1);
}