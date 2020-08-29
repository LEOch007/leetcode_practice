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

int main(){
    string s1 = "123.789";
    double num1 = stof(s1);
    cout<<num1<<endl;

    string snum1 = to_string(num1);
    cout<<snum1<<endl;

    float f = abs((stof(s1)-stof(snum1)));
    cout<<f<<endl;
}