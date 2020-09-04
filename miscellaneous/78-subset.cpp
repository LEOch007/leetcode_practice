//
// Created by linjliang on 2020/6/27.
//

/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec =  {{}};    // initial vector
        for (int n : nums){
            vector<vector<int>> temp_vec = vec;
            for (const vector<int>& v: vec){
                vector<int> temp = v;
                temp.push_back(n);
                temp_vec.push_back(temp);
            }
            vec = temp_vec;
        }
        return vec;
    }

    void print_vec(vector<vector<int>> vec){
        for (auto & v : vec){
            cout << "[";
            for(int j=0; j<v.size();j++){
                cout << v[j];
                if (j!=v.size()-1) cout<<" ";
            }
            cout<<"]"<<endl;
        }
    }
};

int main(){
    Solution solu;
    vector<int> nums = {1,2,3};
    vector<vector<int>> vvec = solu.subsets(nums);
    solu.print_vec(vvec);

}
