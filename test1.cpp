//
// Created by linjliang on 2020/9/22.
//

#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>& nums, int start, int end){
    srand(time(nullptr));
    int pivot = start + rand()%(end-start+1);
    swap(nums[pivot], nums[end]);

    int small = start-1;
    for (int i = start; i < end; i++){
        if (nums[i] < nums[end]){
            small++;
            swap(nums[i],nums[small]);
        }
    }

    small++;
    swap(nums[end], nums[small]);
    return small;
}

void QuickSort(vector<int>& nums, int start, int end){
    if (start>=end) return;

    int idx = Partition(nums, start, end);
    QuickSort(nums, start, idx-1);
    QuickSort(nums, idx+1, end);
}

// 两个有序数组的交集
vector<int> combine_2vector(vector<int> a, vector<int> b){
    if (a.empty()) return b;
    if (b.empty()) return a;

    vector<int> result;
    int i = 0; int j = 0;
    while (i<a.size() && j<b.size()){
        if (a[i]<=b[j]){
            result.push_back(a[i]);
            i++;
        }
        else {
            result.push_back(b[j]);
            j++;
        }
    }
    if (i>=a.size()){
        for (int l = j; l < b.size(); ++l) {
            result.push_back(b[l]);
        }
    }
    else if (j>=b.size()){
        for (int l = i; l < a.size(); ++l) {
            result.push_back(a[l]);
        }
    }

    // 找出重复数字
    vector<int> ans;
    for (int l = 1; l < result.size(); ) {
        if (result[l]==result[l-1]) {
            int tmp = result[l];
            ans.push_back(result[l]);
            while (result[l]==tmp && l<result.size()){
                l++;
            }
        }
        else{
            l++;
        }
    }
    return ans;
}

// 三个有序数组的交集
// 时间复杂度排序O(nlogn) 遍历O(n+n+n)
bool inputValid = true;
vector<int> find_intersection_3arr(vector<int> A, vector<int> B, vector<int> C){
    if (A.empty() || B.empty() || C.empty()){
        inputValid = false;
        return {};
    }

    QuickSort(A, 0, A.size()-1);
    QuickSort(B, 0, B.size()-1);
    QuickSort(C, 0, C.size()-1);

    // 三个有序数组的交集
    vector<int> result1 = combine_2vector(A,B);
    vector<int> result2 = combine_2vector(A,C);
    vector<int> ans = combine_2vector(result1,result2);
    return ans;
}

int main(){
    vector<int> nums1 = {4,5,6,3,2,1};
    vector<int> nums2 = {44,5,6,33,2,1};
    vector<int> nums3 = {4,15,6,3,2,1};

    vector<int> result = find_intersection_3arr(nums1,nums2,nums3);
    for(auto num:result) cout<<num<<" ";
}