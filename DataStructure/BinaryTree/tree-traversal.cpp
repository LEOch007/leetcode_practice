//
// Created by linjliang on 2020/6/28.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct BNode{       // The Node of the Binary Tree
    int data;
    BNode *lchild;
    BNode *rchild;
};

class BTree{
public:
    BNode *root;

    /*
     * Cpp supports array as parameter,
     * otherwise we should use *nums,
     * and get the i-th element with: element = *(nums+i)
     */
    int construct_BT(BNode* &curr, const int nums[], int pos){
        curr = new BNode;           // make sure each pointer is assigned with space
        if (nums[pos] == -1){       // empty
            curr = nullptr;
            return pos;
        }

        curr->data = nums[pos];
        pos = construct_BT(curr->lchild, nums,pos+1);
        pos = construct_BT(curr->rchild, nums,pos+1);
        return pos;
    }

    // recursive methods:
    void pre_traversal(BNode* curr){
        if (curr == nullptr) return;

        cout<<curr->data<<" ";
        pre_traversal(curr->lchild);
        pre_traversal(curr->rchild);
    }

    void mid_traversal(BNode* curr){
        if (curr == nullptr) return;

        mid_traversal(curr->lchild);
        cout<<curr->data<<" ";
        mid_traversal(curr->rchild);
    }

    void post_traversal(BNode* curr){
        if (curr == nullptr) return;

        post_traversal(curr->lchild);
        post_traversal(curr->rchild);
        cout<<curr->data<<" ";
    }

    // non-recursive methods:

};

int main(){
    setbuf(stdout,0);
    //int nums[] = {2,3,5,-1,-1,-1,4,-1,6,-1,-1};
    //int nums[] = {1,-1,4,-1,6,-1,8,-1,-1};
    int nums[] = {2,6,-1,8,-1,-1,7,4,-1,-1,3,5,-1,-1,-1};

    BTree bt;
    bt.construct_BT(bt.root, nums, 0);

    cout<<"pre order: ";
    bt.pre_traversal(bt.root);
    cout<<endl;

    cout<<"mid order: ";
    bt.mid_traversal(bt.root);
    cout<<endl;

    cout<<"post order: ";
    bt.post_traversal(bt.root);
    cout<<endl;
}
