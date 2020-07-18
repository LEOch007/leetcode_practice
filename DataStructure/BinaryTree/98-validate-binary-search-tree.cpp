//
// Created by linjliang on 2020/7/15.
//

/*
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool ans = true;

    bool isValidBST(TreeNode* root) {
        // pre_order_traversal(root);
        // return ans;

        vector<int> result = {};
        mid_order_traversal(root, result);
        for (int i = 0; i < (int)result.size()-1; ++i) {
            if (result[i]>=result[i+1]) { ans = false; break; }
        }
        return ans;
    }

    vector<int> pre_order_traversal(TreeNode* curr){
        vector<int> range;
        if (curr == nullptr) return range;

        range.push_back(curr->val);     // min-value
        range.push_back(curr->val);     // max-value

        if (curr->left != nullptr){
            vector<int> left_range = pre_order_traversal(curr->left);
            if (left_range[0]<range[0]) range[0] = left_range[0];
            if (left_range[1]>range[1]) range[1] = left_range[1];

            // judgement
            if (left_range[1] >= curr->val) ans = false;
        }

        if (curr->right != nullptr){
            vector<int> right_range = pre_order_traversal(curr->right);
            if (right_range[0]<range[0]) range[0] = right_range[0];
            if (right_range[1]>range[1]) range[1] = right_range[1];

            // judgement
            if (right_range[0] <= curr->val) ans = false;
        }

        return range;
    }

    void mid_order_traversal(TreeNode* curr, vector<int>& result){
        if (curr == nullptr) return ;

        mid_order_traversal(curr->left, result);
        result.push_back(curr->val);
        mid_order_traversal(curr->right, result);
    }
};

int main(){
    int nums[] = {10,5,15,-1,-1,6,20};
    int size = 7;
    TreeNode* pnums[size];
    for (int i = 0; i < size; ++i) {
        if (nums[i] == -1) { pnums[i] = nullptr; }
        else{ pnums[i] = new TreeNode(nums[i]); }
    }
    for (int i = 0; i < size; ++i) {
        if (2*i+1<size) pnums[i]->left = pnums[2*i+1];
        if (2*i+2<size) pnums[i]->right = pnums[2*i+2];
    }

    Solution s;
    s.isValidBST(nullptr);
    cout<<s.ans<<endl;
}

/*
 * Note:
 *
 * Divide and Conquer, needs to store the range from min-value to max-value
 *
 * Or
 *
 * Using mid_order_traversal, aka, Inorder traversal to obtain an increasing list
 * ( When using .size(), always remember it is unsigned int, try to avoid overflow problem )
 */