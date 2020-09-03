//
// Created by linjliang on 2020/9/2.
//

// Sure

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void find(vector<vector<char>> &arr, int i, int j, vector<vector<int>> &vis){
    if (vis[i][j]==1 || arr[i][j] != 'S') return;

    vis[i][j] = 1;
    find(arr, i+1,j,vis);
    find(arr,i-1,j,vis);
    find(arr, i, j+1, vis);
    find(arr, i, j-1, vis);
}

int main(){
    int M,N; char c;
    cin>>M>>c>>N;
    vector<vector<char>> arr(M+2,vector<char>(N+2));
    for (int i = 0; i < M+2; ++i) {
        for (int j = 0; j < N+2; ++j) {
            arr[i][j] = 'H';
        }
    }
    for (int i = 1; i <= M; ++i) {
        string s; cin>>s;
        for (int j = 1; j <= N; ++j) {
            arr[i][j] = s[j-1];
        }
    }

    vector<vector<int>> vis(M+2,vector<int>(N+2));
    for (int i = 0; i < M+2; ++i) {
        for (int j = 0; j < N+2; ++j) { vis[i][j] = 0;}
    }
    int cnt = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (vis[i][j]==0 && arr[i][j] == 'S') {
                find(arr, i, j, vis);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}