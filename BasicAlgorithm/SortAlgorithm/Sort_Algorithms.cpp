//
// Created by linjliang on 2020/8/5.
//

/*
 * 手写：
 * - 归并排序
 * - 快速排序
 * - 堆排序
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class SortAlgorithm{
private:
    /*
     * 归并排序：
     * 采用链表实现 整体复杂度：时间O(nlogn) 空间O(1)
     * 采用向量实现 整体复杂度：时间O(nlogn) 空间O(n)
     */
    vector<int> MergeTwoVec(vector<int> left_nums, vector<int> right_nums){
        vector<int> result = {};
        int i = 0;
        int j = 0;
        while (i<left_nums.size() && j<right_nums.size()){
            if (left_nums[i]<right_nums[j]){ result.push_back(left_nums[i]); i++; }
            else { result.push_back(right_nums[j]); j++; }
        }

        if (i>=left_nums.size()) {
            while (j<right_nums.size()) { result.push_back(right_nums[j]); j++; }
        } else{
            while (i<left_nums.size()) { result.push_back(left_nums[i]); i++; }
        }
        return result;
    }

public:
    vector<int> MergeSort(vector<int> nums){
        if (nums.size()<=1) return nums;

        int mid = nums.size()/2;
        vector<int> left_nums (nums.begin(),nums.begin()+mid);
        vector<int> right_nums (nums.begin()+mid, nums.end());

        left_nums = MergeSort(left_nums);
        right_nums = MergeSort(right_nums);
        return MergeTwoVec(left_nums,right_nums);
    }

private:
    /*
     * 快速排序 整体复杂度： 时间O(nlogn) 空间O(1)
     * 关键点在于Partition：
     * 用small指针指向比pivot小的数组部分的尾部
     * 遍历数组，找到比pivot小的数，交换至small指针的下一位置
     */
    int ParititionVec(vector<int> &nums, int start, int end){
        srand(time(nullptr));
        int pivot = start + rand()%(end+1-start);
        swap(nums[pivot], nums[end]);

        int small = start-1;
        int i = start;
        for (; i < end; ++i) {
            if (nums[i]<nums[end]){
                small++;
                swap(nums[i],nums[small]);
            }
        }
        small++;
        swap(nums[end],nums[small]);
        return small;
    }

    void QuickSortCore(vector<int> &nums, int start, int end){
        if (start>=end) return;

        int idx = ParititionVec(nums, start, end);
        QuickSortCore(nums, start, idx-1);
        QuickSortCore(nums, idx+1, end);
    }

public:
    vector<int> QuickSort(vector<int> nums){
        QuickSortCore(nums, 0, nums.size()-1);
        return nums;
    }

private:
    /*
     * 堆排序 整体复杂度： 时间O(nlogn) 空间O(1)
     * 分为两个步骤：
     * 第一步 构建大顶堆
     * - 其中从 len/2-1 个节点开始维持大顶堆的特性 是因为后面的均为叶子节点，不必考虑
     * 第二步 利用大顶堆排序
     * - 每次将堆顶最大值放置末端，缩小堆长度-1，重新维持大顶堆
     */
    void HeapMaintain(vector<int> &nums, int start, int len){
        if (len<=1) return;

        while (true){
            int left = 2*start+1;
            int right = 2*start+2;
            int bigIdx = start;

            if (left<len && nums[left] > nums[bigIdx]) bigIdx = left;
            if (right<len && nums[right] > nums[bigIdx]) bigIdx = right;

            if (bigIdx == start) { break; }
            else{
                swap(nums[bigIdx],nums[start]);
                start = bigIdx;
            }
        }
    }

public:
    vector<int> HeapSort(vector<int> nums){
        // 构建大顶堆
        for (int start=nums.size()/2-1; start>=0 ; start--) {
            HeapMaintain(nums, start, nums.size());
        }

        // 利用大顶堆排序
        for (int len=nums.size()-1; len>=1 ; len--) {
            swap(nums[0],nums[len]);
            HeapMaintain(nums, 0, len);
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {5,-1,-2,-2,6,11,9,6,5,2,2,0,181};

    SortAlgorithm sa;
    vector<int> result = sa.MergeSort(nums);
    for(auto num:result) cout<<num<<" ";
    cout<<endl;

    result = sa.QuickSort(nums);
    for(auto num:result) cout<<num<<" ";
    cout<<endl;

    result = sa.HeapSort(nums);
    for(auto num:result) cout<<num<<" ";
    cout<<endl;
}