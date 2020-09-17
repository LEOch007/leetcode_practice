//
// Created by linjliang on 2020/9/17.
//

// Sure

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, W; cin>>N>>W;
    vector<int> num(N+1);
    vector<int> w(N+1);
    vector<int> v(N+1);
    for (int i = 1; i <= N; ++i) {
        cin>>num[i]>>w[i]>>v[i];
    }

    // state
    vector<vector<int>> dp(N+1, vector<int>(W+1));
    // init
    for (int i = 0; i < N+1; ++i) {
        for (int j = 0; j < W+1; ++j) { dp[i][j] = 0; }
    }

    // function
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= W; ++j) {
            for (int k = 0; k <= num[i]; ++k) {
                if (j>=k*w[i]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k*w[i]]+k*v[i]);
                }
            }
        }
    }
    // answer
    cout<<dp[N][W]<<endl;

}