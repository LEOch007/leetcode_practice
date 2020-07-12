//
// Created by linjliang on 2020/7/11.
//

/*
 * 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？
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
    bool isSymmetric(TreeNode* root) {
        return double_pointer_traversal(root,root);
    }

    // recursive methods
    bool double_pointer_traversal(TreeNode* p, TreeNode* q){
        if ((p == nullptr) && (q == nullptr)) return true;
        if ((p == nullptr) || (q == nullptr)) return false;

        if (p->val != q->val) return false;
        if (!double_pointer_traversal(p->left,q->right)) return false;
        if (!double_pointer_traversal(p->right,q->left)) return false;

        return true;
    }

    // non-recursive methods
    bool double_direction_BFS(TreeNode* root){
        if (root == nullptr) return true;

        queue<TreeNode*> queue_p, queue_q;
        queue_p.push(root);
        queue_q.push(root);

        while ((!queue_p.empty())&&(!queue_q.empty())){
            TreeNode* p = queue_p.front();
            queue_p.pop();
            TreeNode* q = queue_q.front();
            queue_q.pop();

            if ((p== nullptr)&&(q== nullptr)) continue;
            if ((p== nullptr)||(q== nullptr)||(p->val!=q->val)){ return false;}

            queue_p.push(p->left);
            queue_p.push(p->right);

            queue_q.push(q->right);
            queue_q.push(q->left);
        }
        return true;
    }

    vector<vector<int>> BFS(TreeNode* root){
        vector<vector<int>> result;
        if (root== nullptr) return result;

        queue<TreeNode*> queue_p;
        queue_p.push(root);

        TreeNode* p;
        while (!queue_p.empty()){
            vector<int> temp;
            int queue_len = queue_p.size();
            for (int i = 0; i < queue_len; ++i) {
                p = queue_p.front();
                queue_p.pop();
                if (p == nullptr) { temp.push_back(-1); }
                else {
                    temp.push_back(p->val);
                    queue_p.push(p->left);
                    queue_p.push(p->right);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};


int main(){
    int nums[] = {1,2,2,3,4,4,3};
    TreeNode* pnums[7];
    for (int i = 0; i < 7; ++i) { pnums[i] = new TreeNode(nums[i]); }
    for (int i = 0; i < 7; ++i) {
        if (2*i+1<7) pnums[i]->left = pnums[2*i+1];
        if (2*i+2<7) pnums[i]->right = pnums[2*i+2];
    }

    Solution s;
    vector<vector<int>> result = s.BFS(pnums[0]);
    for (auto v:result) {
        for (auto num:v) cout<<num<<" ";
        cout<<endl;
    }
}

/*
 * Notes:
 *
 * Double pointer
 */