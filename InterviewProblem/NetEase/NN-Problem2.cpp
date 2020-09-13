//
// Created by linjliang on 2020/9/13.
//

// UnSure

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mp = {{"0",1},{"1",1},{"10",1},{"11",1},
                                 {"100",1},{"101",1},{"110",1},{"111",1}};

bool isValid(string str){
    bool ans;
    if (mp.find(str) != mp.end()) ans = true;
    else ans = false;
    return ans;
}

void decode(string s, int& ans){
    if (s.size()==0){
        ans++;
        return;
    }

    for (int i = 1; i <= 3; ++i) {
        if (s.size()>=i && mp.find(s.substr(0,i)) != mp.end()){
            decode(s.substr(i),ans);
        }
    }
}

int main(){
    string s; cin>>s;

    int ans = 0;
    decode(s,ans);
    cout<<ans<<endl;
}