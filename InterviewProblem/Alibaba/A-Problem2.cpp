//
// Created by linjliang on 2020/9/8.
//

// UnSure

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool possible_ans = false;

vector<string> split_words(string s){
    vector<string> ciphers;
    int idx = 0;
    int i = 0;
    for (; i < s.size(); ++i) {
        if (s[i]=='.') break;

        if (s[i]==' '){
            ciphers.push_back( s.substr(idx, i-idx) );
            idx = i+1;
        }
    }
    ciphers.push_back( s.substr(idx, i-idx) );
    return ciphers;
}

bool cmp(string a, string b){
    bool ans;
    if (a.size() < b.size()){ ans = true; }
    else if (a.size() > b.size()){ ans = false; }
    else {
        ans = a < b;
    }
    return ans;
}

void search_match(unordered_map<char,char>& mp, vector<string> &words,int i, vector<string> ciphers,int j, int cnt){
    if (cnt == ciphers.size()) return;

    for (int k = 0; k < words[i].size(); ++k) {
        mp[ words[i][k] ] = ciphers[j][k];
        mp[ ciphers[j][k] ] = words[i][k];
    }

    for (int k = 0; k < ciphers.size(); ++k) {
        for (int l = 0; l < ciphers[k].size(); ++l) {
            ciphers[k][l] = mp[ ciphers[k][l] ];
        }
    }

    for (int k = 0; k < ciphers.size(); ++k) {
        if (k==j) continue;
        for (int l = 0; l < words.size(); ++l) {
            if (l==i) continue;

            if (words[l].size() == ciphers[k].size()){
                search_match(mp, words, l, ciphers, k, cnt++);
            }
        }
    }
}

int main(){
    int n;
    while (cin>>n){
        if (n==0) break;

        vector<string> words(n);
        for (int i = 0; i < n; ++i) {
            cin>>words[i];
        }
        // for(auto s:words) cout<<s<<endl;

        string str;
        cin.ignore();
        getline(cin,str);
        cout<<str<<endl;

        vector<string> ciphers = split_words(str);
        sort(words.begin(),words.end(),cmp);
        sort(ciphers.begin(),ciphers.end(),cmp);

        // search
        cout<<"-."<<endl;
//        unordered_map<char,char> mp;
//        int cnt = 0;
//        for (int j = 0; j < ciphers.size(); ++j) {
//            for (int i = 0; i < words.size(); ++i) {
//                if (words[i].size() == ciphers[j].size()){
//                    search_match(mp, words,i,ciphers,j, cnt);
//                }
//            }
//        }
    }
}