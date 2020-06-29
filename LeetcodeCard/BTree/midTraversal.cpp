//
// Created by linjliang on 2020/6/29.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result = {};
        //mid_traversal(root, result);
        mid_order(root, result);
        return result;
    }

    void mid_traversal(TreeNode* curr, vector<int> &result){
        if (curr == nullptr) return;

        mid_traversal(curr->left, result);
        result.push_back(curr->val);
        mid_traversal(curr->right, result);
    }

    void mid_order(TreeNode* p, vector<int> &result){
        if (p == nullptr) return;

        stack<TreeNode*> stack_p;  // store the previous node pointer
        while ((p!= nullptr)||(!stack_p.empty())){
            while (p != nullptr){
                stack_p.push(p);
                p = p->left;
            }
            p = stack_p.top();
            stack_p.pop();
            result.push_back(p->val);
            p = p->right;
        }
    }
};