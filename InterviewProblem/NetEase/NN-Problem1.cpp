//
// Created by linjliang on 2020/9/13.
//

// Sure

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s; cin>>s;

    long long all0 = 0;
    long long all1 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]=='0') all0++;
        else all1++;
    }

    long long global_max = 0;
    global_max = max(global_max, (2*all0+all1));
    global_max = max(global_max, (2*all1+all0));

    long long cnt0 = 0;
    long long cnt1 = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]=='0') cnt0++;
        else cnt1++;

        long long val = (2*cnt0+cnt1) + 2*(all1-cnt1)+(all0-cnt0);
        global_max = max(val,global_max);
    }
    cout<<global_max<<endl;
}