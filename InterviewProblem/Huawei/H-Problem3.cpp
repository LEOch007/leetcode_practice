//
// Created by linjliang on 2020/9/2.
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main(){
    int k,n;
    cin>>k>>n;
    vector<int> w(n+1);
    vector<int> v(n+1);
    for (int i = 1; i <= n; ++i) { cin>>w[i]; }
    for (int i = 1; i <= n; ++i) { cin>>v[i]; }

    // state init
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    for (int i = 0; i <= n; ++i) { dp[i][0] = 0; }
    for (int i = 0; i <= k; ++i) { dp[0][i] = 0; }

    // function
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (j < w[i]) { dp[i][j] = dp[i-1][j]; }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    // answer
    int max_v = dp[n][0];
    for (int i = 1; i <= k; ++i) {
        if (dp[n][i] > max_v) max_v = dp[n][i];
    }
    cout<<max_v<<endl;
}