//
// Created by linjliang on 2020/8/21.
//

/*
 * 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
提示：

0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))

 */

#include <vector>
using namespace std;

class Solution {
public:
    int Partition(vector<int> &arr, int start, int end){
        srand(time(nullptr));
        int pivot = start + rand()%(end-start+1);
        swap(arr[pivot], arr[end]);

        int small = start-1;
        for (int i = start; i < end; ++i) {
            if (arr[i] < arr[end]){
                small++;
                if (i != small) swap(arr[i], arr[small]);
            }
        }

        small++;
        swap(arr[small], arr[end]);
        return small;
    }

    // O(n) time complexity
    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.size() == 0) return {};

        int start = 0;
        int end = arr.size()-1;
        int idx = Partition(arr, start, end);
        while (idx != k){
            if (idx < k){
                start = idx+1;
                idx = Partition(arr, start, end);
            }
            else{
                end = idx-1;
                idx = Partition(arr, start, end);
            }
        }

        vector<int> result(k);
        for (int i = 0; i < idx; ++i) { // should be < , not <=
            result[i] = arr[i];
        }
        return result;
    }
};

/*
 * Note:
 *
 * 利用Partition函数 以idx对应的值划分数组，
 * 如果idx刚好是k 则返回结果即可
 * 如果idx比k小 则对数组idx右侧随机找参照值pivot进行划分
 * 如果idx比k大 则对数组idx左侧随机找参考值pivot进行划分
 *
 * 通过等比数列求和可知整个算法时间复杂度为 O(n)
 */