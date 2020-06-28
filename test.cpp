//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> vec = {{1,2,3},{1},{}};    // initial vector
    for (auto & v : vec){
        cout << "[";
        for(int j=0; j<v.size();j++){
            cout << v[j];
            if (j!=v.size()-1) cout<<" ";
        }
        cout<<"]"<<endl;
    }
}