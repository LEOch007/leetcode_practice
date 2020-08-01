//
// Created by linjliang on 2020/7/31.
//

/*
 * 分别有1,5,10,50,100元，
 * 对应有num1,num2,num3,num4,num5张纸币,
 * 问若要支付k元，则最少需要多少张纸币？
 */

// Unsure
#include <iostream>
#include <vector>
using namespace std;

/*
 * incorrect!
 */
long long cnt_method(long long k, vector<long long> num){
    if (k<0) return LONG_LONG_MAX;
    else if (k==0) return 0;

    vector<long long> num_tmp = num;
    long long ans1, ans2, ans3, ans4, ans5;

    num_tmp[0]--;
    if (num_tmp[0]>0) {
        ans1 = cnt_method(k-1,num_tmp);
        if (ans1 != LONG_LONG_MAX) ans1++;
    }
    else ans1 = LONG_LONG_MAX;

    num_tmp[0]++; num_tmp[1]--;
    if (num_tmp[1]>0) {
        ans2 = cnt_method(k-5,num_tmp);
        if (ans2 != LONG_LONG_MAX) ans2++;
    }
    else ans2 = LONG_LONG_MAX;

    num_tmp[1]++; num_tmp[2]--;
    if (num_tmp[2]>0) {
        ans3 = cnt_method(k-10,num_tmp);
        if (ans3 != LONG_LONG_MAX) ans3++;
    }
    else ans3 = LONG_LONG_MAX;

    num_tmp[2]++; num_tmp[3]--;
    if (num_tmp[3]>0) {
        ans4 = cnt_method(k-50,num_tmp);
        if (ans4 != LONG_LONG_MAX) ans4++;
    }
    else ans4 = LONG_LONG_MAX;

    num_tmp[3]++; num_tmp[4]--;
    if (num_tmp[4]>0) {
        ans5 = cnt_method(k-100,num_tmp);
        if (ans5 != LONG_LONG_MAX) ans5++;
    }
    else ans5 = LONG_LONG_MAX;

    return min(ans1, min( ans2, min(ans3, min(ans4,ans5))));
}

long long greedy_method(long long k, vector<long long> num){
    long long values[] = {1,5,10,50,100};

    long long all_cnt = 0;
    for (int i=4; i>=0; i--) {      // 从大到小 贪心地取
        long long cnt = min(k/values[i], num[i]);
        k = k- cnt*values[i];
        all_cnt += cnt;

        if (k==0) return all_cnt;
    }
    return -1;
}

int main(){
    vector<long long> num = {5,2,2,3,5};
    long long k = 55;
    long long tmp;
//    for (int i = 0; i < 5; ++i) {
//        cin>>tmp;
//        num.push_back(tmp);
//    }
//    cin>>k;

    cout<<greedy_method(k,num)<<endl;

}