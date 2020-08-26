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
     * 两个字符串是否相等
     * @param str1 string字符串 第一个字符串
     * @param str2 string字符串 第二个字符串
     * @return bool布尔型
     */
    bool isStrsEqu(string str1, string str2) {
        if (str1.size() != str2.size()) return false;
        bool ans = true;
        for (int i = 0; i < str1.size(); ++i) {
            if (str1[i] != str2[i]) {
                ans = false;
                break;
            }
        }

        if (ans) return ans;
        else {
            if (str1.size() == 1) return false;

            int mid = str1.size()/2;
            string s1(str1.begin(),str1.begin()+mid);
            string ss1(str1.begin()+mid,str1.end());

            string s2(str2.begin(),str2.begin()+mid);
            string ss2(str2.begin()+mid,str2.end());

            ans = (isStrsEqu(s1,s2)&&isStrsEqu(ss1, ss2)) || (isStrsEqu(s1, ss2)&&isStrsEqu(ss1, s2));
            return ans;
        }
    }
};