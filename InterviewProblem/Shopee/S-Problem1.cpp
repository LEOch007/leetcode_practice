//
// Created by linjliang on 2020/8/26.
//

#include <iostream>
#include <map>
using namespace std;

// Sure

class Solution {
public:
    /**
     * 获取满足条件的最长子串的长度
     * @param str string字符串 输入的字符串
     * @return int整型
     */
    int getMaxSubstringLen(string str) {
        if (str.size() == 0) return 0;

        int global_max = 0;
        for (int i = 0; i < str.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                bool legal = true;
                map<char,int> mp;
                for (int k = j; k <= i; ++k) {
                    if (str[k]>='a' && str[k]<='z'){
                        if (str[k]=='a' || str[k]=='b' || str[k]=='c' || str[k]=='d' || str[k]=='e'){
                            if (mp.find(str[k]) == mp.end()) mp[str[k]] = 1;
                            else mp[str[k]] ++;
                        }
                    }
                    else{
                        legal = false;
                        break;
                    }
                }
                int sum = 0;
                for (auto iter = mp.begin(); iter != mp.end(); iter++) {
                    sum += iter->second;
                    if (iter->second%2==1) {
                        legal = false;
                        break;
                    }
                }
                if (sum == 0) legal = false;
                // update
                if (legal) global_max = max(global_max, i-j+1);
            }
        }
        return global_max;
    }
};

int main(){
    string str0 = "aabbffced";
    string str = "asdfajskfbb";
    Solution s;
    cout<<s.getMaxSubstringLen(str0);
}