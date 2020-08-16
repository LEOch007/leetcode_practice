//
// Created by linjliang on 2020/8/16.
//

/*
 * 一串数字删掉k个数字后，最小值是多少？
 *
 * 输入：字符串s 和 要求删掉的个数k
 * 输出：数值最小的数字字符串
 */

// Sure

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    string s; cin>>s;
    int k; cin>>k;

    while (k && !s.empty()){
        bool cut = false;
        int len = s.size();
        for (int i = 0; i < len-1; ++i) {
            // 去掉较大的高位
            if (s[i]>s[i+1]){
                s.erase(i,1);
                cut = true;
                break;
            }
        }
        // 去掉数值最大的低位
        if (!cut){
            s = s.substr(0,s.size()-1);
        }

        // 去掉前面多余0
        int idx = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]!='0'){ idx = i; break; }
        }
        if (idx==-1) s = "0";
        else s = s.substr(idx,s.size()-idx);

        k--;
    }

     cout<<s<<endl;
}