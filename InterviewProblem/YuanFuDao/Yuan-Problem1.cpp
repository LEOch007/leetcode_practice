//
// Created by linjliang on 2020/8/22.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void printBottom(vector<int> &nums, int curr, vector<int> &result){
    if (2*curr+1 >= nums.size()){
        if (nums[curr] != result[result.size()-1])
            result.push_back(nums[curr]);
        return;
    }

    int left = 2*curr+1;
    int right = 2*curr+2;

    printBottom(nums, left, result);
    printBottom(nums, right, result);
}

int main(){
    int N; cin>>N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin>>nums[i];
    }

    if (nums.size()==1) {
        cout<<nums[0];
        return 0;
    }

    vector<int> result;
    int idx = 0;
    // 左边边界节点
    while (idx<N){
        result.push_back(nums[idx]);
        idx = 2*idx+1;
    }

    // 底部边界节点
    printBottom(nums,0, result);

    // 右边边界节点
    stack<int> s_num;
    idx = 2;
    while (idx<N){
        s_num.push(nums[idx]);
        idx = 2*idx+2;
    }
    while (!s_num.empty()){
        if (s_num.top() != result[result.size()-1])
            result.push_back(s_num.top());
        s_num.pop();
    }

    for (auto num:result) {
        cout<<num<<" ";
    }
    cout<<endl;
}