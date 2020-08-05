//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <list>
#include <zconf.h>

using namespace std;

int main(){
    vector<int> v = {3,4,5,6};
    list<int> lv (v.begin(),v.end());

    for(auto num:lv) cout<<num<<" ";
    cout<<endl;

    cout<<"size: "<<lv.size()<<endl;

}