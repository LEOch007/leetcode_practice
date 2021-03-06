//
// Created by linjliang on 2020/7/13.
//

/*
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

     3
    /  \
   5    1
  / \  / \
 6  2  0 8
   / \
  7  4


示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。

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
    TreeNode* ancestor;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ancestor = root;
        hasPointer(root,p,q);
        return ancestor;

    }

    bool hasPointer(TreeNode* curr, TreeNode* p, TreeNode* q){
        if (curr == nullptr) return false;

        bool self_has = false;
        if (curr->val == p->val) self_has = true;
        if (curr->val == q->val) self_has = true;

        bool left_has = hasPointer(curr->left,p,q);
        bool right_has = hasPointer(curr->right,p,q);

        if ((self_has&&left_has) || (self_has&&right_has) || (left_has&&right_has))
            ancestor = curr;

        return self_has||left_has||right_has;
    }
};

/*
 * Note:
 * Divide and Conquer
 */

int main(){
    int nums[] = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* pnums[11];
    for (int i = 0; i < 11; ++i) {
        if (nums[i] == -1) { pnums[i] = nullptr; }
        else{ pnums[i] = new TreeNode(nums[i]); }
    }
    for (int i = 0; i < 11; ++i) {
        if (2*i+1<11) pnums[i]->left = pnums[2*i+1];
        if (2*i+2<11) pnums[i]->right = pnums[2*i+2];
    }

    Solution s;
    s.lowestCommonAncestor(pnums[0],pnums[1],pnums[6]);
}