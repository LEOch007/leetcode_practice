//
// Created by linjliang on 2020/8/15.
//

/*
 * 水仙花数：
 * 判断在[m,n]区间内有多少个数字是水仙花数，
 * 水仙花数为：各个数位的立方和等于其自身，如 153 = 1^3+5^3+3^3
 */

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    int n, m;
    while (cin >> m >> n) {
        vector<int> result = {};
        for (int num = m; num <=n ; ++num) {
            int a = num%10;
            int b = num/10%10;
            int c = num/100;
            if (num == c*c*c+b*b*b+a*a*a)
                result.push_back(num);
        }
        if (result.empty()) cout<<"no"<<endl;
        else {
            for (auto num:result) cout<<num<<" ";
            cout<<endl;
        }
    }
}