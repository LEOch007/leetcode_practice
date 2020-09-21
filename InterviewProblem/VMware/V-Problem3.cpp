//
// Created by linjliang on 2020/9/21.
//

// UnSure

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<vector<int>> votes(n,vector<int>(2));
    for (int i = 0; i < n; ++i) {
        cin>>votes[i][0]>>votes[i][1];
    }

    cout<<n-k<<endl;
}