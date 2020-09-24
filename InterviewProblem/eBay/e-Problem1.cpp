//
// Created by linjliang on 2020/9/24.
//

// Unsure

#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n; cin>>n;
    if (n==1) {
        cout<<0<<endl;
        return 0;
    }

    // state
    vector<long long> dp(n+1);
    // init
    fill(dp.begin(), dp.end(), 0);
    dp[1] = 1;

    // function
    for (long long i = 2; i <= n; ++i) {
        for (long long j = 1; j < n; ) {
            dp[i] = (dp[i]+dp[i-j]);
            j *= 2;
        }
    }
    // answer
    cout<<dp[n]<<endl;
}