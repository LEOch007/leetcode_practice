//
// Created by linjliang on 2020/9/26.
//

// UnSure

#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#include <algorithm>
using namespace std;

const int INF = 999999999;
int min_v = INF-1;
set<vector<int>> spos;

void dfs(vector<vector<char>>& arr, int i, int j, vector<vector<int>> vis, int length){
    // 回退
    if (i<0 || i>=arr.size() || j<0 || j>=arr[0].size() || arr[i][j]=='1' || vis[i][j]==1) return;

    // 当下
    vis[i][j]=1;
    length++;
    if (arr[i][j]=='X'){
        vector<int> pos = {i,j};
        if (length < min_v){
            min_v = length;
            spos.clear();
            spos.insert(pos);
        }
        else if (length == min_v){
            spos.insert(pos);
        }
    }

    // 前进
    dfs(arr,i+1,j,vis,length);
    dfs(arr,i-1,j,vis,length);
    dfs(arr,i,j+1,vis,length);
    dfs(arr,i,j-1,vis,length);
}

bool cmp(vector<int> a, vector<int> b){
    bool ans;
    if (a[0] < b[0]) ans = true;
    else if (a[0] > b[0]) ans = false;
    else if (a[1] < b[1]) ans = true;
    else ans = false;
    return ans;
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<char>> arr(n, vector<char>(m));
    int T_i, T_j;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin>>c;
            arr[i][j] = c;

            if (c=='T'){
                T_i = i;
                T_j = j;
            }
        }
    }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    vector<vector<int>> vis(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) { vis[i][j] = 0; }
    }
    dfs(arr,T_j,T_j,vis,-1);

    if (min_v == INF-1){
        cout<<0<<endl;
    }
    else {
        vector<vector<int>> vpos(spos.begin(),spos.end());
        sort(vpos.begin(),vpos.end(),cmp);
        cout<<min_v<<endl;
        for(auto pos : vpos) cout<<pos[0]<<" "<<pos[1]<<" ";
        cout<<endl;
    }
}