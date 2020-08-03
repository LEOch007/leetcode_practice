//
// Created by linjliang on 2020/8/3.
//

/*
 * 输入n、k，将k个不同的字母放入长度为n的序列，
 * 要求：k个字母必须放入，且相邻的字母不能相同
 * 输出：字典序最小的字符序列，如果不存在，输出-1
 *
 * 示例1：
 * 输入：4 2
 * 输出：abab
 *
 * 示例2：
 * 输入：7 8
 * 输出：-1
 */

// Sure
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    long long n;
    long long k;
    cin>>n>>k;

    string char_set = "abcdefghijklmnopqrstuvwxyz";

    if ((n<k) || ((n>1)&&(k==1))){
        cout<<-1<<endl;
    }
    else{
        char result[n];
        bool gate = true;
        long long i = 0;
        if (n==k){
            for (;i<n;i++) { result[i] = char_set[i];}
        }
        else {
            for (; i < n - k; ++i) {
                result[i] = gate ? char_set[0] : char_set[1];
                gate = !gate;
            }
            if (result[i - 1] != char_set[0]){
                int j = 0;
                for (;i<n;i++) { result[i] = char_set[j++];}
            } else{
                result[i++] = char_set[1];
                if (i<n) result[i++] = char_set[0];
                int j = 2;
                for (;i<n;i++) { result[i] = char_set[j++];}
            }
        }
        // output
        for (int j = 0; j < n; ++j) {
            cout<<result[j];
        }
        cout<<endl;
    }
}

/*
 * Note:
 *
 * 整个算法应用贪心思想，字符串前面尽可能放abab，使整体字典序小
 * 后面将剩余字母放入字符串中，注意要保证相邻不重复
 *
 * 注意边界特例：
 * 3 1 无法保证相邻不重复
 * 但 1 1 可以
 */