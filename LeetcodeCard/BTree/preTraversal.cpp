//
// Created by linjliang on 2020/6/29.
//

#include <MacTypes.h>
#include <vector>
#include <iostream>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result = {};
        //pre_traversal(root, result);
        pre_order(root, result);
        return result;
    }

    void pre_traversal(TreeNode* curr, vector<int> &result){
        if (curr == nullptr) return;

        result.push_back(curr->val);
        pre_traversal(curr->left, result);
        pre_traversal(curr->right, result);
    }

    void pre_order(TreeNode* p, vector<int> &result){
        if (p == nullptr) return;

        stack<TreeNode*> stack_p;  // store the previous node pointer
        while ((p!= nullptr)||(!stack_p.empty())){
            while (p != nullptr){
                result.push_back(p->val);
                stack_p.push(p);
                p = p->left;
            }
            p = stack_p.top();
            stack_p.pop();
            p = p->right;
        }
    }
};