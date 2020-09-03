//
// Created by linjliang on 2020/9/2.
//

// UnSure

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

vector<int> findIdx(vector<vector<int>> &arr){
    if (arr.size()<3) return {};
    if (arr.size()==3) return {arr[0][0],arr[1][0],arr[2][0], arr[0][1]+arr[1][1]+arr[2][1]};

    int max_sum = -1;
    vector<int> idx(3);
    for (int i = 0; i < arr.size()-2; ++i) {
        for (int j = i+1; j < arr.size()-1; ++j) {
            for (int k = j+1; k < arr.size(); ++k) {
                if (arr[i][1]+arr[j][1]+arr[k][1] > max_sum){
                    max_sum = arr[i][1]+arr[j][1]+arr[k][1];
                    idx = {arr[i][0],arr[j][0],arr[k][0]};
                }
                else if (arr[i][1]+arr[j][1]+arr[k][1] == max_sum){
                    if (arr[i][0] < idx[0]) {
                        max_sum = arr[i][1]+arr[j][1]+arr[k][1];
                        idx = {arr[i][0],arr[j][0],arr[k][0]};
                    }
                }
            }
        }
    }
    return {idx[0],idx[1],idx[2],max_sum};
}

int main(){
    int n; cin>>n;
    vector<vector<int>> one;
    vector<vector<int>> two;
    for (int i = 0; i < n; ++i) {
        int num, color;
        cin>>num>>color;
        if (color==1) one.push_back({i+1,num});
        else two.push_back({i+1,num});
    }

    vector<int> re;
    bool one_flag = true;
    vector<int> one_re = findIdx(one);
    vector<int> two_re = findIdx(two);
    if (one_re.empty() && two_re.empty()) re = {};
    else if (one_re.empty()) { re = two_re; one_flag = false; }
    else if (two_re.empty()) { re = one_re; one_flag = true; }
    else {
        if (one_re[3] > two_re[3]){
            re = one_re;
            one_flag = true;
        }
        else if (one_re[3] < two_re[3]){
            re = two_re;
            one_flag = false;
        }
        else{
            if (one_re[0] < two_re[0]){
                re = one_re;
                one_flag = true;
            } else{
                re = two_re;
                one_flag = false;
            }
        }
    }

    if (re.empty()) cout<<"null"<<endl;
    else {
        for (int i = 0; i < 3; ++i) { cout<<re[i]<<" "; }
        cout<<endl;
        if (one_flag) cout<<1<<endl;
        else cout<<2<<endl;
        cout<<re[3]<<endl;
    }
}