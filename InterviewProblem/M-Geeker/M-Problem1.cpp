//
// Created by linjliang on 2020/8/3.
//

/*
 * 对于一个三位数（0<=x<=999)，将其每个数位转化为四位的二进制，如：123 -> 0001 0010 0011
 * 再将其镜像对称，去掉前导的0，得到最后的编码结果
 *
 * 示例：
 * 输入：2
 *      123 1
 * 输出：
 *      110001001000
 *      100000000000
 */

// Sure
#include <iostream>
#include <vector>
using namespace std;

vector<int> ten2twoCore(int num){
    vector<int> result = {0,0,0,0};
    int i = 3;
    while (num>0){
        result[i] = num%2;
        num = num/2;
        i--;
    }
    return result;
}

vector<int> ten2two(int num){
    vector<int> re1 = ten2twoCore(num%10);
    vector<int> re2 = ten2twoCore((num/10)%10);
    vector<int> re3 = ten2twoCore((num/100)%10);

    vector<int> result = re3;
    result.insert(result.end(),re2.begin(),re2.end());
    result.insert(result.end(),re1.begin(),re1.end());

    return result;
}

int main(){
    int n; cin>>n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i]==0){
            cout<<0<<endl;
            continue;
        }

        vector<int> result = ten2two(nums[i]);
        bool start = false;
        for (int j=result.size()-1; j>=0; j--) {
            if (result[j]==0 && !start) continue;
            start = true;
            cout<<result[j];
        }
        cout<<endl;
    }
}

/*
 * Note:
 *
 * 注意边界值特例：
 * 输入0
 * 输出0
 */