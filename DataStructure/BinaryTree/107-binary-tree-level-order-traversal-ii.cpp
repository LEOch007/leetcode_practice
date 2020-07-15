//
// Created by linjliang on 2020/7/15.
//

/*
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result = BFS_traversal(root);
        return result;
    }

    vector<vector<int>> BFS_traversal(TreeNode* root){
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> queue_p;
        queue_p.push(root);

        while (!queue_p.empty()){
            vector<int> temp;
            int queue_len = queue_p.size();
            for (int i = 0; i < queue_len; ++i) {
                TreeNode* p = queue_p.front();
                queue_p.pop();
                temp.push_back(p->val);

                if (p->left!= nullptr) queue_p.push(p->left);
                if (p->right!= nullptr) queue_p.push(p->right);
            }
            result.insert(result.begin(),temp);
        }

        return result;
    }
};