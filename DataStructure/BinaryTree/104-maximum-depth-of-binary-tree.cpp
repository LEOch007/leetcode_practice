//
// Created by linjliang on 2020/7/10.
//

/*
 * 给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7

 返回它的最大深度 3

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
    int depth;

    int maxDepth(TreeNode* root) {
        depth = 0;
        maximum_depth(root,1);
        return depth;
    }

    void maximum_depth(TreeNode* p, int curr_d){
        if (p == nullptr) return;

        if ((p->left == nullptr) && (p->right == nullptr)){
            depth = max(curr_d,depth);
        }

        maximum_depth(p->left,curr_d+1);
        maximum_depth(p->right,curr_d+1);
    }
};

int main(){


}

/*
 * Notes:
 *
 * Top-down or Bottom-up usually helps solve this kind of problems
 */