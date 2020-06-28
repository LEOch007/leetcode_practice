//
// Created by linjliang on 2020/6/27.
//

#include <iostream>
#include <vector>
#include <zconf.h>

using namespace std;

struct BNode{       // The Node of the Binary Tree
    int data;
    BNode *lchild;
    BNode *rchild;
};

int main(){
    BNode *root = new BNode;
    BNode *l = new BNode;
    l->data = 5;
    root->lchild = l;

    cout<<root->data<<" "<<root->lchild->data<<endl;

    int a[] = {1, 2, 3, -1};
    for (int j = 0; j < 4; ++j) {
        cout<<a[j]<<" ";
    }

}