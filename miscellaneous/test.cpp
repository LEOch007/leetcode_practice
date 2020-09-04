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
    string data = "-100,$,200";
    string sval;
    int i;
    for (i = 5; i < data.size(); ++i) {
        if (data[i] == ','){
            sval = data.substr(5,i-5);
            break;
        }
    }
    i++;
    cout<<sval<<endl;
    cout<<i<<endl;
    cout<<data.substr(5,6)<<endl;
}