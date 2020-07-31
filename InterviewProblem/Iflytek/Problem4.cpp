//
// Created by linjliang on 2020/7/31.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string str;
    cin>>str;

    long long num = 0;
    bool neg = false;
    bool beg = false;
    for (int i = 0; i < str.size(); ++i) {
        if ((str[i]=='-')&&(!beg)){ neg = true; }
        else if ((str[i] >= '0') && (str[i]<='9')){
            if (num>INT_MAX) {
                num = 0;
                break;
            }
            num *= 10;
            num += str[i]-'0';
            beg = true;
        }
    }

    if (neg) num = -1*num;
    cout<<num<<endl;
}