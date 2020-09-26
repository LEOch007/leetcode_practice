//
// Created by linjliang on 2020/9/26.
//

// UnSure

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int K; cin>>K;
    while (K--){
        int n,k;
        cin>>n>>k;
        vector<int> vals(n);
        for (int i = 0; i < n; ++i) {
            cin>>vals[i];
        }
        unordered_map<int,int> mp;
        for (int j = 0; j < n-1; ++j) {
            int u,v;
            cin>>u>>v;
        }

        cout<<-1<<endl;
    }
}