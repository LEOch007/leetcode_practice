//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <list>
#include <zconf.h>
#include <string>
#include <cmath>
using namespace std;

struct S{
    float f1;
    char c;
    float f2;
};

int main(){
    int T; cin>>T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> ppl(n);
        vector<int> jobs(m);
        for (int i = 0; i < n; ++i) {
            cin >> ppl[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> jobs[i];
        }

        for(auto job:jobs)cout<<job<<" ";
    }
}