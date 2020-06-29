//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <zconf.h>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    v.resize(1,0);
    v.resize(2,0);
    v[1]++;
    v.resize(2,0);
    v[1]++;
    for (int num: v) cout<<num<<" ";
}