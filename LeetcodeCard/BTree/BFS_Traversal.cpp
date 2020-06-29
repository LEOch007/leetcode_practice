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
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        BFS_BT(root, result);
        return result;
    }

    void BFS_BT(TreeNode* p, vector<vector<int>> &result){
        if (p== nullptr) return;

        queue<TreeNode*> queue_p;      // store the node in breadth-first order
        queue_p.push(p);

        while (!queue_p.empty()){
            int queue_len = queue_p.size();         // the number of nodes in current level
            vector<int> v;
            for (int i = 0; i < queue_len; ++i) {
                p = queue_p.front();
                queue_p.pop();
                v.push_back(p->val);

                if (p->left != nullptr) queue_p.push(p->left);
                if (p->right != nullptr) queue_p.push(p->right);
            }
            result.push_back(v);
        }
    }
};