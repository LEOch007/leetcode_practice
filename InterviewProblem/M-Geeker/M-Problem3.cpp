//
// Created by linjliang on 2020/8/3.
//

/*
 * 题目忘了 写法没写完 也有问题
 * 请忽略
 */

#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long s;
    long long m;
    cin>>s>>m;

    for (long long k = 1; k <= s; ++k) {
        vector<long long> vec_v;
        for (long long a = 1; a < k; ++a) {
            long long v = a*(k-a);
            vec_v.push_back(v);
        }
    }
}