//
// Created by linjliang on 2020/8/15.
//

/*
 * 一个long类型num二进制中 1的个数
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(){
    long num;
    cin>>num;

    long cnt = 0;
    while (num){
        cnt++;
        num = (num-1) & num;
    }
    cout<<cnt<<endl;
}
