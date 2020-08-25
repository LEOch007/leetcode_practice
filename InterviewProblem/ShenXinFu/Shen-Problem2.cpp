//
// Created by linjliang on 2020/8/25.
//

#include <iostream>
#include <map>
using namespace std;

int main(){
    string s; cin>>s;
    map<char,char> mp;
    int n; cin>>n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        char sa = a + '0';
        char sb = b + '0';

        // 更新mp
        for (auto iter = mp.begin(); iter != mp.end(); iter++){
            if (iter->second == sa){
                iter->second = sb;
            }
        }
        // 插入新映射
        if (mp.find(sa) == mp.end()) mp[sa] = sb;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (mp.find(s[i]) != mp.end()) s[i] = mp[s[i]];
    }
    cout<<s<<endl;
}