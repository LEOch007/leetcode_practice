//
// Created by linjliang on 2020/9/1.
//

// UnSure

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    long n,m;
    cin>>n>>m;
    vector<long> nums(m);
    for (int i = 0; i < m; ++i) {
        cin>>nums[i];
    }

    vector<bool> flag(m);
    fill(flag.begin(), flag.end(), false);
    sort(nums.begin(),nums.end());
    for (int i = 0; i < m; ++i) {
        if (flag[i]) continue;
        for (int j = i+1; j < m; ++j) {
            if (!flag[j] && nums[j]%nums[i] == 0){
                flag[j] = true;
            }
        }
    }
    vector<int> rnum;
    for (int i = 0; i < m; ++i) {
        if (!flag[i]) rnum.push_back(nums[i]);
    }

    long cnt = 0;
    for (int num = 1; num <= n; ++num) {
        for (int i = 0; i < rnum.size(); ++i) {
            if (num%rnum[i]==0) {
                cnt++;
                break;
            }
        }
    }

    cout<<cnt<<endl;
}