//
// Created by linjliang on 2020/8/15.
//

// UnSure

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <string>

using namespace std;

struct Node{
    int val;
    vector<Node*> child;
    Node(int x){
        val = x;
        child = {};
    }
};


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
long long cntTimeOut(string s) {
    Node* dummy = new Node(-100);


}
/******************************结束写代码******************************/


int main() {
    bool res;
    string s;
    cin>>s;

    res = cntTimeOut(s);
    cout << res << endl;

    return 0;

}
