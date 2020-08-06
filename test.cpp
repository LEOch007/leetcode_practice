//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <list>
#include <zconf.h>

using namespace std;

int main(){
    vector<vector<int>> tmp = {};
    vector<int> t1 = {1};
    vector<int> t2 = {4,5};
    vector<int> t3 = {21,4,8};
    tmp.push_back(t1);
    tmp.push_back(t2);
    tmp.push_back(t3);

    vector<vector<int>> triangle = {{-1},{-2,-3}};

    for(auto v:triangle) {
        for (auto num:v) cout << num << " ";
        cout<<endl;
    }
}