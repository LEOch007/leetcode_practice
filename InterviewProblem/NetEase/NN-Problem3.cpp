//
// Created by linjliang on 2020/9/13.
//

// Sure

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int M; cin>>M;
    vector<int> nums; int num;
    while (cin>>num){
        nums.push_back(num);

        char c = cin.get();
        if (c=='\n') break;
    }

    // state
    vector<int> dp(nums.size());
    // init
    fill(dp.begin(),dp.end(),-1);
    if (M>=2) dp[0] = M-2 + nums[0];

    if (dp[0]>=2) dp[1] = max(dp[1],dp[0]-2 + nums[1]);
    if (M>=3) dp[1] = max(dp[1], M-3 + nums[1]);

    // function
    for (int i = 2; i < dp.size(); ++i) {
        if (dp[i-1]>=2) dp[i] = max(dp[i], dp[i-1]-2 + nums[i]);
        if (dp[i-2]>=3) dp[i] = max(dp[i], dp[i-2]-3 + nums[i]);
    }
    // answer
    int max_v = dp[0];
    for (int i = 1; i < dp.size(); ++i) {
        if (dp[i]>max_v) max_v = dp[i];
    }
    if (max_v==-1) cout<<M<<endl;
    else cout<<max_v<<endl;
}