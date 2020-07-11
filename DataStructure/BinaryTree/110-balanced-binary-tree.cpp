//
// Created by linjliang on 2020/7/11.
//

/*
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false

 */

#include <iostream>
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
    int ans;

    bool isBalanced(TreeNode* root) {
        ans = true;
        count_depth(root);
        return ans;
    }

    int count_depth(TreeNode* p){
        if (p== nullptr) return 0;

        int left_depth = count_depth(p->left);
        int right_depth = count_depth(p->right);

        if (abs(left_depth-right_depth)>1) { ans = false; }

        int curr_depth = max(left_depth,right_depth) + 1;

        return curr_depth;
    }
};

