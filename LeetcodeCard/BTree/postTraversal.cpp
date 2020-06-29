//
// Created by linjliang on 2020/6/29.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result = {};
        //post_traversal(root, result);
        post_order(root, result);
        return result;
    }

    void post_traversal(TreeNode* curr, vector<int> &result){
        if (curr == nullptr) return;

        post_traversal(curr->left,result);
        post_traversal(curr->right,result);
        result.push_back(curr->val);
    }

    void post_order(TreeNode* p, vector<int> &result){
        if (p == nullptr) return;

        stack<TreeNode*> stack_p;      // store the previous node pointer
        TreeNode* lastvisit = nullptr; // last visited node: determine whether right child has been visited
        while ((p!= nullptr)||(!stack_p.empty())){
            while (p != nullptr){
                stack_p.push(p);
                p = p->left;
            }
            p = stack_p.top();
            // the visited right child is the same as null
            if ((p->right == nullptr)||(p->right == lastvisit)){
                result.push_back(p->val);
                lastvisit = p;          // mark it as visited
                stack_p.pop();
                p = nullptr;            // important: can go back to the parent node
            } else{
                p = p->right;
            }
        }
    }
};