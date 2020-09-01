//
// Created by linjliang on 2020/9/1.
//

// Sure

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;

    vector<vector<int>> nums(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            nums[i][j] = 0;
        }
    }

    int size = nums.size();
    if (N%2==0){    // 偶数
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i<j && j>0 && j<N/2) { nums[i][j] = 2; }
                else if (N-1-i<j && j>0 && j<N/2) {nums[i][j] = 5;}
                else if (i>j && i>0 && i<N/2){ nums[i][j] = 3; }
                else if (i>N-j-1 && i>0 && i<N/2) { nums[i][j] = 8; }

                else if (N-1-i>j && i>=N/2 && i<N-1) { nums[i][j] = 4; }
                else if (j>i && i>=N/2 && i<N-1) {nums[i][j] = 7;}
                else if (i<N-j-1 && j>=N/2 && j<N-1){ nums[i][j] = 1; }
                else if (i>j && j>=N/2 && j<N-1) {nums[i][j] = 6;}
            }
        }
    }
    else{      // 奇数
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i<j && j>0 && j<N/2) { nums[i][j] = 2; }
                else if (N-1-i<j && j>0 && j<N/2) {nums[i][j] = 5;}
                else if (i>j && i>0 && i<N/2){ nums[i][j] = 3; }
                else if (i>N-j-1 && i>0 && i<N/2) { nums[i][j] = 8; }

                else if (N-1-i>j && i>N/2 && i<N-1) { nums[i][j] = 4; }
                else if (j>i && i>N/2 && i<N-1) {nums[i][j] = 7;}
                else if (i<N-j-1 && j>N/2 && j<N-1){ nums[i][j] = 1; }
                else if (i>j && j>N/2 && j<N-1) {nums[i][j] = 6;}
            }
        }
    }

    // 输出
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
}