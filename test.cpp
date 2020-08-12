//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <list>
#include <zconf.h>

using namespace std;

int main(){
    int a = 1;
    int &a_ = a;
    cout<<a_<<endl;

    a = 2;
    cout<<a_<<endl;
}