//
// Created by linjliang on 2020/7/12.
//

/*
 * 给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6

示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

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
    int global_pathsum;

    int maxPathSum(TreeNode* root) {
        global_pathsum = root->val;
        nodePathSum_simple(root);
        return global_pathsum;
    }

    // the return value indicates the maximum path sum going through the node p
    int nodePathSum(TreeNode* p){
        if (p == nullptr) return INT_MIN;

        long left_sum = nodePathSum(p->left);
        long right_sum = nodePathSum(p->right);

        // max path sum going through the node p
        int node_pathsum = max((long)p->val, max(p->val+left_sum, p->val+right_sum));

        // "locally" max path sum among the subtree rooted at node p
        int local_pathsum = max((long)p->val,max(p->val+left_sum, max(p->val+right_sum,
                        max(p->val+left_sum+right_sum, max(left_sum,right_sum)))));
        // "globally" max path sum recoed
        global_pathsum = max(global_pathsum, local_pathsum);

        return node_pathsum;
    }

    // the same idea as the above function but with simplified implementation
    int nodePathSum_simple(TreeNode* p){
        if (p == nullptr) return 0;

        int left_gain  = max(nodePathSum_simple(p->left),0);    // don't need negative gain
        int right_gain = max(nodePathSum_simple(p->right),0);   // don't need negative gain

        int node_gain = p->val + max(left_gain,right_gain);

        int local_pathsum = p->val + left_gain + right_gain;    // max(left_gain,right_gain) already computed
        global_pathsum = max(global_pathsum,local_pathsum);

        return node_gain;
    }
};

/*
 * Note:
 *
 * bottom-up thinking
 * global recording
 */