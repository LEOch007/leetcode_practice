//
// Created by linjliang on 2020/8/8.
//

// UnSure
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int rela[m][2];
    for (int i = 0; i < m; ++i) {
        cin>>rela[i][0];
        cin>>rela[i][1];
    }

    int arr[n][n];
    memset(arr,0,sizeof(arr));
    for (int i = 0; i < m; ++i) {
        arr[rela[i][0]-1][rela[i][1]-1] = 1;
    }

    int psum = 0;
    while (true) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j] == 1) {
                    for (int k = 0; k < n; ++k) {
                        if (arr[j][k] == 1) arr[i][k] = arr[j][k];
                    }
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr[i][j]==1) sum++;
            }
        }
        if (sum == psum) break;
        psum = sum;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i][j]==1 && arr[j][i]==1) cnt++;
        }
    }
    cout<<cnt<<endl;
}