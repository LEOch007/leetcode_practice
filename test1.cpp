//
// Created by linjliang on 2020/9/11.
//

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> func(vector<int> nums, int target){
    vector<int> ans = {};
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); ++i) {
        if (mp.find(target-nums[i]) == mp.end()) mp[nums[i]] = 1;
        else {
            ans = {nums[i], target-nums[i]};
            break;
        }
    }
    return ans;
}

int func1(vector<int>& arr){
    if (arr.empty()) return 0;
    if (arr.size()==1) return 0;

    int global_max = 0;
    int min_v = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        global_max = max(global_max, arr[i]-min_v);
        if (arr[i]<min_v) min_v = arr[i];
    }
    return global_max;
}

int main(){

}