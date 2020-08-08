//
// Created by linjliang on 2020/8/8.
//

// UnSure
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int T = 1;
    // cin>>T;
    for (int i = 0; i < T; ++i) {

        int n = 5;
        // cin>>n;
        int nums[5] = {30,60,5,15,30};
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
            // cin>>nums[j];
            sum += nums[j];
        }

        long long total = sum;
        sort(nums,nums+n);
        bool ans = false;
        int k = 0;
        long long curr;
        while (!ans && k<n) {
            curr = 0;
            for (int j = k; j < n; ++j) {
                curr += nums[j];
                if (curr == sum / 2) {
                    ans = true;
                    break;
                } else if (curr > sum / 2) { break;}
            }
            if (!ans){
                sum -= nums[k++];
            }
        }

        cout<<total - curr*2<<endl;
    }
}