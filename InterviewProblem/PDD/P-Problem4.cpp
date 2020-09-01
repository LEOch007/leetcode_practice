//
// Created by linjliang on 2020/9/1.
//

// UnSure

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int cntMax(vector<vector<int>> nums, vector<int> pos, vector<int> pos1){
    nums[pos1[0]][pos1[1]] = 0;
    nums[pos[0]][pos[1]] = 1;


}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> nums(n, vector<int>(m));
    vector<vector<int>> ones;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp; cin>>tmp;
            nums[i][j] = tmp;
            if (tmp==1) ones.push_back({i,j});
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (nums[i][j] == 0){
                vector<int> pos = {i,j};
                for(auto v: ones){
                    cntMax(nums,pos,v);
                }
            }
        }
    }
}