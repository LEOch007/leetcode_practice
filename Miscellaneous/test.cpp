//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <list>
#include <zconf.h>

using namespace std;

struct S{
    float f1;
    char c;
    float f2;
};

int main(){
    cout<<"size: "<<sizeof(S)<<endl;

    string str1 = "abcd";
    int mid = str1.size()/2;
    string s1(str1.begin(),str1.begin()+mid);
    string ss1(str1.begin()+mid,str1.end());

    cout<<s1<<endl;
    cout<<ss1<<endl;

    bool a = true;
    bool b = false;
    bool c = a||b;
    cout<<c;
}