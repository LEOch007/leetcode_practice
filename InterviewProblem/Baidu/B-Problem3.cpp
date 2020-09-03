//
// Created by linjliang on 2020/9/3.
//

#include <iostream>
#include <vector>
using namespace std;

// UnSure

long long global_cnt = 0;

void find_step(long long step1, long long step2, long long &max_step, long long curr_sum, long long &target){
    curr_sum += step2;
    if (curr_sum == target) global_cnt = global_cnt%(1000000000+7) +1;
    else if (curr_sum > target) return;
    else {
        for (long long s = 1; s <= max_step; ++s) {
            if (s == step1 || s == step2) continue;
            find_step(step2, s, max_step, curr_sum, target);
        }
    }
}

int main(){
    long long n,m; cin>>n>>m;

    for (long long i = 1; i <= m; ++i) {
        find_step(-1, i, m,0, n);
    }
    cout<<global_cnt%(1000000000+7)<<endl;
}