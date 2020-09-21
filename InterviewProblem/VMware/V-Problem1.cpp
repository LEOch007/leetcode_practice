//
// Created by linjliang on 2020/9/21.
//

// Sure

#include <iostream>
using namespace std;

int main(){
    double n,r; int m;
    cin>>n>>m>>r;

    double curr = 0.0;
    for (int i = 0; i < m; ++i) {
        curr = curr+r;
        while (curr > 4*n) { curr -= 4*n; }

        double x,y;
        if (curr<=n) {
            y = curr;
            x = 0;
        }
        else if (curr>n && curr<=2*n){
            y = n;
            x = curr-n;
        }
        else if (curr>2*n && curr<=3*n){
            y = 3*n-curr;
            x = n;
        }
        else if (curr>3*n && curr<=4*n){
            y = 0;
            x = 4*n-curr;
        }
        printf("%.2f %.2f\n",y,x);
    }
}