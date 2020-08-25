//
// Created by linjliang on 2020/8/25.
//

/*
 * 给定一个数字字符串（0～9），以及给出n对数字变换对，问变换后的字符串
 *
 * 输入：0234086525
 *      4
 *      0 2
 *      2 3
 *      5 7
 *      2 4
 * 输出：3334386737
 */

// Sure

#include <iostream>
#include <map>
using namespace std;

int main(){
    string s; cin>>s;
    map<char,char> mp;
    int n; cin>>n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        char sa = a + '0';
        char sb = b + '0';

        // 更新mp
        for (auto iter = mp.begin(); iter != mp.end(); iter++){
            if (iter->second == sa){
                iter->second = sb;
            }
        }
        // 插入新映射
        if (mp.find(sa) == mp.end()) mp[sa] = sb;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (mp.find(s[i]) != mp.end()) s[i] = mp[s[i]];
    }
    cout<<s<<endl;
}

/*
 * Note:
 *
 * 最高效的实现方案是：
 * 更新有限数字的映射 O(n) + 更新字符串 O(m) = O(n+m)
 *
 * 更新有限数字的映射可用map，也可申请一个长度为10的数组即可：
 * 增加一个变换对(a,b):
 * - 遍历数组中的值若有a，替换成b；
 * - 判断数组中索引a的位置是否已有值，如果无，赋值为b；有则无需操作；
 */