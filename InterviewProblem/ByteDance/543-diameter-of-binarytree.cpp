//
// Created by linjliang on 2020/8/18.
//

/*
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
 * 这条路径可能穿过也可能不穿过根结点。

 

示例 :
给定二叉树

          1
         / \
        2   3
       / \
      4   5
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。


注意：两结点之间的路径长度是以它们之间边的数目表示。


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
    int global_diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        longleg_of_node(root);
        return global_diameter;
    }

    int longleg_of_node(TreeNode* p){
        if (p == nullptr) return 0;

        int longleg = 0;
        int left_leg = 0;
        int right_leg = 0;

        if (p->left != nullptr) {
            left_leg = 1 + longleg_of_node(p->left);
            longleg = max(longleg, left_leg);
        }
        if (p->right != nullptr) {
            right_leg = 1 + longleg_of_node(p->right);
            longleg = max(longleg, right_leg);
        }

        int local_diameter = left_leg + right_leg;
        global_diameter = max(local_diameter, global_diameter);

        return longleg;
    }
};