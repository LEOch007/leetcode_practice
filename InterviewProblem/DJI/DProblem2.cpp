//
// Created by linjliang on 2020/8/16.
//

/*
 * 小明喜欢玩游戏，每玩一个游戏需要花掉x天，玩完后能获得v经验，
 * 现在假设小明有N个游戏在X天内要玩，每个游戏只玩一遍，问小明最多能获得多少经验？
 *
 * 输入：N X
 * 接下来N组数据：经验值v 对应的天数d
 *
 * 输出：最大经验值
 */

// UnSure

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N,X;
    cin>>N>>X;

    vector<priority_queue<int>> games(X+1);
    for (int i = 0; i <= X; ++i) {
        games[i].push(0);
    }

    for (int i = 0; i < N; ++i) {
        int val,day;
        cin>>val>>day;
        games[day].push(val);
    }

    vector<int> dp(X+1);
    dp[0] = 0;

    for (int i = 1; i <=X ; ++i) {
        int max_v = 0;
        int max_day = -1;
        for (int j = 0; j<=i-1  ; ++j) {
            if ( dp[j] + games[i-j].top() > max_v ){
                max_v = dp[j] + games[i-j].top();
                max_day = i-j;
            }
        }
        dp[i] = max_v;
        games[max_day].pop();
    }

    cout<<dp[X]<<endl;
}