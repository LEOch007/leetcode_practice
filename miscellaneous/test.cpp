//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <list>
#include <zconf.h>
#include <string>
#include <cmath>
using namespace std;

struct S{
    float f1;
    char c;
    float f2;
};

bool cmp(string a, string b){
    bool ans;
    if (a.size() < b.size()){ ans = true; }
    else if (a.size() > b.size()){ ans = false; }
    else {
        ans = a < b;
    }
    return ans;
}

int main(){

    string str;
    getline(cin,str);
    cout<<str<<endl;
}