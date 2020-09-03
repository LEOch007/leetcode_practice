//
// Created by linjliang on 2020/9/3.
//

// Sure

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T; cin>>T;
    while (T--){
        int L,n; cin>>L>>n;
        vector<int> nums(L);
        fill(nums.begin(),nums.end(),0);

        for (int i = 0; i < n; ++i) {
            int l,r; cin>>l>>r;
            l = l-1; r = r-1;
            for (int j=l; j<=r; j++) nums[j]++;
        }

        for (int i = 0; i < nums.size(); ++i) {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
}