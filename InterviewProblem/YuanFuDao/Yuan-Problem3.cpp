//
// Created by linjliang on 2020/8/22.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    if (n==1) cout<<0<<endl;

    vector<vector<int>> dp(n+1, vector<int>(n+1));
    vector<vector<int>> mon(n+1, vector<int>(n+1));
    fill(mon.begin(), mon.end(), 0);
    for (int i = 0; i <=n; ++i) {
        dp[i][i] = 0;
    }

    for (int j = 2; j <= n; ++j) {
        for (int i = j-1; i >=1 ; --i) {
            for (int l = i+1; l <=j-1; ++l) {
                dp[i][j] = min(l+max(dp[i][l-1], dp[l+1][j]), dp[i][j]);
            }
            dp[i][j] = min(dp[i][j], min(i+dp[i+1][j], j+dp[i][j-1]));
        }
    }
    cout << dp[1][n] <<endl;
}