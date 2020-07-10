//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <zconf.h>

using namespace std;

int main(){
    vector<int> v = {1,3,5,7,9};
    int mid = v.size()/2;

    vector<int> tmp (v.begin(),v.begin()+mid);
    vector<int> tmp1 (v.begin()+mid,v.end());

    for (int num: tmp) cout<<num<<" ";
    cout<<endl;
    for (int num: tmp1) cout<<num<<" ";
    cout<<"\n"<<endl;

    srand(time(nullptr));
    for (int i = 0; i < 5; ++i) {
        cout<<rand()%5<<" ";
    }

}