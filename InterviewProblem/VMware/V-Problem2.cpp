//
// Created by linjliang on 2020/9/21.
//

// Sure

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        vector<int> nums(n);
        vector<int> target(n);
        for (int i = 0; i < n; ++i) {
            cin>>nums[i];
        }
        for (int i = 0; i < n; ++i) {
            cin>>target[i];
        }

        unordered_map<int,int> mp = {{target[0],1}};
        vector<int> target_core = {target[0]};
        for (int i = 1; i < n; ++i) {
            if (target[i]==target[i-1]) continue;

            target_core.push_back(target[i]);
            mp[target[i]] = 1;
        }

//        for(auto num:target_core) cout<<num<<" ";
//        cout<<endl;

        vector<int> nums_core;
        for (int i = 0; i < n; ++i) {
            if (mp.find(nums[i]) == mp.end()) continue;

            nums_core.push_back(nums[i]);
        }

//        for(auto num:nums_core) cout<<num<<" ";
//        cout<<endl;

        bool flag = true;
        for (int j = 0; j < target_core.size(); ++j) {
            if (target_core[j] != nums_core[j]){
                flag = false;
                break;
            }
        }

        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}