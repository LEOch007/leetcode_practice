//
// Created by linjliang on 2020/6/27.
//

/*
 * 实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // special case: needle is an empty string
        if (needle.length() == 0){ return 0; }

        // return value
        int ans = -1;
        // double for-loop
        int i = 0; int j = 0;
        for(i = 0; i < (int)haystack.length()-(int)needle.length()+1; i++){
            if (haystack[i] == needle[0]){
                ans = i;        // hopefully the answer
                for (j = 1; j < needle.length(); j++) {
                    if (haystack[i+j] != needle[j]) { // not satisfied
                        ans = -1;
                        break;
                    }
                }
                if (j == needle.length()) {     // satisfied
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution solu;
    cout<<"first:\n";
    cout<<solu.strStr("hello","o")<<endl;
    cout<<"second:\n";
    cout<<solu.strStr("abb","abaaa")<<endl;
}