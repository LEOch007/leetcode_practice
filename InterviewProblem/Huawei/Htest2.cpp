//
// Created by linjliang on 2020/9/12.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    bool ans;
    if (a[0]>b[0]) ans = true;
    else if (b[0]==a[0]) {
        if (a[1]<b[1]) ans = true;
        else ans = false;
    }
    else ans = false;
    return ans;
}

vector<vector<int>> buildQueue(vector<vector<int>> nums){
    sort(nums.begin(), nums.end(),cmp);
    // for(auto re:nums) cout<<"["<<re[0]<<","<<re[1]<<"]"<<" ";

    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
        auto iter = result.begin()+nums[i][1];
        result.insert(iter,nums[i]);
    }

    return result;
}

int main(){
    vector<vector<int>> nums = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};

    vector<vector<int>> result = buildQueue(nums);
    for(auto re:result) cout<<"["<<re[0]<<","<<re[1]<<"]"<<" ";
}