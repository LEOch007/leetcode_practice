//
// Created by linjliang on 2020/8/31.
//

/*
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。

注意:

十六进制中所有字母(a-f)都必须是小写。
十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；
对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 

给定的数确保在32位有符号整数范围内。
不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。

示例 1：

输入:
26

输出:
"1a"

示例 2：

输入:
-1

输出:
"ffffffff"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        string hex = "0123456789abcdef";
        string s = "";
        while (num && s.size() < 8){
             char c = hex[num & 0xF];
             s.insert(s.begin(),c);
             num = num>>4;
        }
        return s;
    }
};

int main(){
    int num = 0;
    Solution s;
    cout<<s.toHex(num)<<endl;
}

/*
 * Note:
 *
 * Num to Hex的最佳实践：
 * 每次按位与 0xF(即1111) 拿到低位对应的值，然后右移4位，直到数值为0或者字符串长度为8停止
 * 当num本身是正数时，右移结束时num为0，故停止；
 * 当num本身是负数时，右移num永不为0，则在字符串长度满了停止（32位int转16进制，最多8位）；
 * 当num本身是零时，需要另行处理，直接返回"0"字符串
 */