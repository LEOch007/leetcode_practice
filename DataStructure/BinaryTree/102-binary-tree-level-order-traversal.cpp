//
// Created by linjliang on 2020/7/15.
//

/*
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。


示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result = BFS_traversal(root);
        return result;
    }

    vector<vector<int>> BFS_traversal(TreeNode* root){
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> queue_p;
        queue_p.push(root);

        while (!queue_p.empty()){
            int queue_len = queue_p.size();
            vector<int> temp;
            for (int i = 0; i < queue_len; ++i) {
                TreeNode* p = queue_p.front();
                queue_p.pop();
                temp.push_back(p->val);

                if (p->left!= nullptr) queue_p.push(p->left);
                if (p->right!= nullptr) queue_p.push(p->right);
            }
            result.push_back(temp);
        }

        return result;
    }
};

/*
 * Note:
 *
 * the node numbers in each layer can be obtained from
 * the size of queue before putting nodes of next layer in queue.
 */