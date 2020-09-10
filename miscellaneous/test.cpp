//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <list>
#include <zconf.h>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

struct S{
    float f1;
    char c;
    float f2;
};

int main(){
    /*
    string str;
    cin.ignore();
    getline(cin,str);
    cout<<str<<endl;
     */

    vector<int> arr = {12,12,13,14,19};
    auto idx = lower_bound(arr.begin(), arr.end(),21);
    cout<<idx-arr.begin()<<endl;
}