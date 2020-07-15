//
// Created by linjliang on 2020/7/15.
//

/*
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
    bool ans = false;
    int curr_sum = 0;

    bool hasPathSum(TreeNode* root, int sum) {
        pre_order_traversal(root,sum);
        return ans;
    }

    int pre_order_traversal(TreeNode* p, int sum){
        if (p == nullptr) return 0;

        curr_sum += p->val;
        if ((p->left == nullptr) && (p->right == nullptr)){
            if (curr_sum==sum) ans = true;
        }

        curr_sum -= pre_order_traversal(p->left,sum);
        curr_sum -= pre_order_traversal(p->right,sum);

        return p->val;
    }
};

/*
 * Note:
 *
 * Using a global variable: curr_sum to calculate the sum value currently,
 * adding node value into curr_sum when visiting the node,
 * deleting node value from curr_sum when exiting from that node.
 */