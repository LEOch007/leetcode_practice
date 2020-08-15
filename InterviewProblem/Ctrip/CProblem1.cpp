//
// Created by linjliang on 2020/8/15.
//

// Sure

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <set>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
vector < int > divingBoard(int a, int b, int k) {
    vector<int> result = {};
    if (k==0) return result;
    if (b==a) {
        result.push_back(a*k);
        return result;
    }

    if (b<a) swap(a,b);
    for (int i = k; i >=0; --i) {
        result.push_back(b*k - (b-a)*i);
    }
    return result;
}
/******************************结束写代码******************************/


int main() {
    int a,b,k;
    cin >> a >> b >> k;

    vector <int> res;
    res = divingBoard(a,b,k);

    if (res.size()==0) cout<<"[]"<<endl;
    else {
        cout << "[";
        for (int i = 0; i < res.size() - 1; i++) cout << res[i] << ",";
        cout << res[res.size() - 1] << "]" << endl;
    }

}

/*
 * Note:
 *
 * 注意输入输出，不要被系统给的输入输出给蒙骗了，要吸取教训
 */
