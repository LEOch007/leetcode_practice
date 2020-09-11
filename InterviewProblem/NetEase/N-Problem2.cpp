//
// Created by linjliang on 2020/9/11.
//

// Sure

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 使用题目中描述的方法，将 raw_str 压缩后返回
     * @param raw_str string字符串 未压缩的原始字符串
     * @return string字符串
     */
    string numToV = "0000abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string compress(string raw_str) {
        if (raw_str.empty()) return raw_str;

        raw_str += "#";
        string result;
        int i = 0; int j = 0;
        int cnt = 1;
        while ( i < raw_str.size()-1) {
            if (raw_str[i] == raw_str[i+1]) {
                cnt++;
                i++;
            }
            else {
                if (cnt<4) {
                    result += raw_str.substr(j,cnt);
                    i++;
                }
                else if (cnt>=4 && cnt<=55){
                    string tmp = "0";
                    tmp += numToV[cnt];
                    tmp += raw_str[i];
                    //cout<<tmp<<endl;

                    result += tmp;
                    i++;
                }
                else{
                    for(int k=0; k<cnt/55; k++){
                        string tmp = "0Z";
                        tmp += raw_str[i];

                        result += tmp;
                    }

                    cnt = cnt%55;
                    if (cnt>=4){
                        string tmp = "0";
                        tmp += numToV[cnt];
                        tmp += raw_str[i];
                        result += tmp;
                        i++;
                    }
                    else{
                        for(int l=0;l<cnt;l++){ result += raw_str[i]; }
                        i++;
                    }

                }
                // 复位
                j = i;
                cnt = 1;
            }
        }

        return result;
    }
};

int main(){
    string str = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBeeeeeeeeeeFYHHnjHAPQQc";
    string str1 = "hh";
    Solution s;
    cout<<s.compress(str)<<endl;
}