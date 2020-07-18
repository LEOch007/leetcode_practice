//
// Created by linjliang on 2020/7/18.
//

/*
 * 给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。
 * 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

例如, 

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
或者这个树也是有效的:

         5
       /   \
      2     7
     / \
    1   3
         \
          4

 */

#include <iostream>
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        root = find_satisfied_nullptr(root,val);
        return root;
    }

    TreeNode* find_satisfied_nullptr(TreeNode* curr, int val){
        if (curr == nullptr){
            curr = new TreeNode(val);   // create a node
            return curr;
        }

        if (curr->val < val) { curr->right = find_satisfied_nullptr(curr->right, val); }
        else { curr->left = find_satisfied_nullptr(curr->left, val); }
        return curr;
    }
};

int main(){
    int nums[] = {4,2,7,1,3};
    int size = 5;
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
    TreeNode* root = s.insertIntoBST(pnums[0],5);

}

/*
 * Note:
 *
 * return the node pointer, in order for its parent node to link it.
 */