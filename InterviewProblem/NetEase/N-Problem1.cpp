//
// Created by linjliang on 2020/9/11.
//

// UnSure

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int N; cin>>N;
    string A,B;
    for (int i = 0; i < N; ++i) {
        char c; cin>>c;
        A += c;
    }
    for (int i = 0; i < N; ++i) {
        char c; cin>>c;
        B += c;
    }

    sort(B.begin(), B.end(),greater<char>());
    if (B<=A) { cout<<-1<<endl; return 0;}

    bool found = true;
    string result;
    sort(B.begin(), B.end());
    for (int i = 0; i < N; ++i) {
        auto iter = lower_bound(B.begin(),B.begin()+B.size(),A[i]);
        int idx = iter-B.begin();

        // 找不到大于等于的 结束
        if (idx==B.size()){
            found = false;
            break;
        }

        if (B[idx] > A[i]){     // 找到大于的
            result += B[idx];
            B.erase(B.begin()+idx);

            result += B;
            break;
        }
        else if (B[idx] == A[i]){   // 继续找
            string tmp = B;
            tmp.erase(tmp.begin()+idx);
            sort(tmp.begin(),tmp.end(),greater<char>());
            if  (tmp <= A.substr(i+1,A.size()-i-1)){
                while(B[idx]==A[i]){idx++;}
                result += B[idx];
                B.erase(B.begin()+idx);

                result += B;
                break;
            }

            result += B[idx];
            B.erase(B.begin()+idx);
        }
    }
    cout<<result<<endl;
}