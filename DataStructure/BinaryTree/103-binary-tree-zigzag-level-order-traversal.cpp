//
// Created by linjliang on 2020/7/15.
//

/*
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> queue_p;
        queue_p.push(root);

        bool gate = true;              // gate indicates the direction; true: left -> right
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
            if (gate){ result.push_back(temp); }
            else {
                vector<int> temp2 (temp.rbegin(),temp.rend());
                result.push_back(temp2);
            }
            gate = !gate;
        }

        return result;
    }
};

/*
 * Note:
 *
 * Using a boolean gate to determine the direction,
 * Using the vector's rbegin & rend to reverse the direction
 */