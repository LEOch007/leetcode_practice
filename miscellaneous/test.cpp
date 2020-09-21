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

class S0{
private:
    int i;
    virtual void method(){};
};

class S1: public S0{
private:
    char ch;
};

int main(){
    /*
    string str;
    cin.ignore();
    getline(cin,str);
    cout<<str<<endl;
     */

//    vector<int> arr = {12,12,13,14,19};
//    auto idx = lower_bound(arr.begin(), arr.end(),21);
//    cout<<idx-arr.begin()<<endl;

//    string s = "3245572911";
//    sort(s.begin(),s.end(),greater<char>());
//    cout<<s<<endl;

//    cout<<sizeof(S0)<<endl;
//    cout<<sizeof(S1)<<endl;

    double x = 2.5;
    double y = 3.338889;
    printf("%.2f %.2f",x,y);
}