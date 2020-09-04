//
// Created by linjliang on 2020/9/4.
//

/*
 * 请实现两个函数，分别用来序列化和反序列化二叉树。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof
 */

#include <iostream>
#include <string>
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

class Codec {
public:
    // Encodes a tree to a single string.
    void serializeCore(TreeNode* p, string& s){
        if (p == nullptr){
            s += "$,";
            return;
        }

        s += to_string(p->val)+',';
        serializeCore(p->left, s);
        serializeCore(p->right, s);
    }

    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        string s;
        serializeCore(root, s);
        return s;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserializeCore(string& data, int& idx){
        string sval;
        int i;
        for (i = idx; i < data.size(); ++i) {
            if (data[i] == ','){
                sval = data.substr(idx,i-idx);
                break;
            }
        }
        idx = i+1;

        if (sval == "$") {
            return nullptr;
        }

        TreeNode* p = new TreeNode(stoi(sval));
        p->left = deserializeCore(data, idx);
        p->right = deserializeCore(data, idx);

        return p;
    }

    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;

        int idx = 0;
        return deserializeCore(data, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));