//
// Created by linjliang on 2020/8/26.
//

#include <iostream>
#include <map>
using namespace std;

/*
 * 给定一个字符串，找到两个子串，要求这俩个子串不能有相同的字母（没有交集），求这俩个子串长度之积的最大值
 *
 */

// UnSure

class Solution {
public:
    /**
     * 获取子串相乘的最大值
     * @param str string字符串 输入的字符串
     * @return int整型
     */
    int getMaxMul(string str) {
        multimap<char,int> mp;
        for (int i = 0; i < str.size(); ++i) {
            mp.insert(make_pair(str[i], i));
        }

        map<char,int> all_char;
        int sum = 0;
        for(auto iter = mp.begin(); iter != mp.end(); iter++){
            if (all_char.find(iter->first) == all_char.end()) {
                all_char[iter->first] = 1;
                sum ++;
            }
        }
        int cnt = 1;
        while (cnt<sum){
            int ano = sum-cnt;
            //

            cnt++;
        }
        return 21;
    }
};