//
// Created by linjliang on 2020/9/1.
//

// UnSure

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> val(n);
    vector<int> weight(n);
    for (int i = 0; i < n; ++i) {
        cin>>weight[i]>>val[i];
    }

    // state
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    // init
    for (int i = 0; i <= n; ++i) {dp[i][0] = 0;}
    for (int j = 0; j <= m; ++j) {dp[0][j] = 0;}
    // function
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (weight[i-1] > j) { dp[i][j] = dp[i-1][j]; }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]]+val[i-1]);
            }
        }
    }

    cout<<dp[n][m]<<endl;
}