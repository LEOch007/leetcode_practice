//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <zconf.h>

using namespace std;

int main(){
    vector<int> v = {3,4,5,6};
    vector<int> temp (v.rbegin(),v.rend());

    for(auto num:temp) cout<<num<<" ";
    cout<<endl;
}