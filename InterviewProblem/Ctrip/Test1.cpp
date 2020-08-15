//
// Created by linjliang on 2020/8/15.
//

/*
 * 数列的和：
 * 一个以n为首，下一个元素是上一个元素的平方根的数列，求其前m项和
 */

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n,m;
    while (cin>>n>>m){
        double sum = n;
        double curr = n;
        for (int i = 1; i < m; ++i) {
            sum += sqrt(curr);
            curr = sqrt(curr);
        }
        printf("%.2f\n",sum);
    }
}