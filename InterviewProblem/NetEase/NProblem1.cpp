//
// Created by linjliang on 2020/8/8.
//

// Sure
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> getNext(string s){
    vector<int> nxt = {};
    nxt.resize(s.size());

    nxt[0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        int tmp = nxt[i-1];
        while (tmp>=1 && s[i]!=s[tmp]) tmp = nxt[tmp-1];
        if (s[i]==s[tmp]) tmp++;
        nxt[i] = tmp;
    }
    return nxt;
}

int main(){
    string s;
    cin>>s;

    string rs = s;
    reverse(rs.begin(),rs.end());

    string comb = rs + "#" + s;
    vector<int> nxt = getNext(comb);
    string result =  s.substr(0, s.size()-nxt[comb.size()-1]) + rs;

    cout<<result<<endl;
}