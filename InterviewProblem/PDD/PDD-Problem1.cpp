//
// Created by linjliang on 2020/9/26.
//

// Sure

#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#include <algorithm>
using namespace std;

vector<vector<int>> zero = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};
vector<vector<int>> one = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,1,1,1,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};
vector<vector<int>> two = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,1,1,1,1,1,1,0,0},
        {0,0,0,0,0,1,1,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,1,1,0,0,0,0,0},
        {0,0,1,1,1,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};
vector<vector<int>> three = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,0,0,0,0,1,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};
vector<vector<int>> four = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,1,1,1,0,0,0,0},
        {0,0,1,1,1,1,0,0,0,0},
        {0,1,1,0,1,1,0,0,0,0},
        {0,1,1,1,1,1,1,1,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};
vector<vector<int>> five = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1,0,0},
        {0,0,1,1,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};
vector<vector<int>> six = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,1,1,0,0,0,0,0,0},
        {0,0,1,1,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,0,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};
vector<vector<int>> seven = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};
vector<vector<int>> eight = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};
vector<vector<int>> nine = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,1,1,0,0,1,1,0,0},
        {0,0,0,1,1,1,1,1,0,0},
        {0,0,0,0,0,0,1,1,0,0},
        {0,0,0,0,0,0,1,1,0,0},
        {0,0,0,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};

vector<vector<vector<int>>> all_num = {zero,one,two,three,four,five,six,seven,eight,nine};

int main(){
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        vector<vector<int>> nums(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>nums[i][j];
            }
        }

        // 遍历每个数字矩阵
        for (int k = 0; k <= 9; ++k) {
            bool flag = true;
            // 遍历每个01
            for (int i = 0, ii=0; i < n;) {
                for (int j = 0, jj=0; j < n;) {
                    if (nums[i][j] != all_num[k][ii][jj]){
                        flag = false;
                        break;
                    }
                    j += n/10;
                    jj += 1;
                }
                if (!flag) break;
                i += n/10;
                ii += 1;
            }
            if (flag) {
                cout<<k<<endl;
                break;
            }
        }
    }
}
