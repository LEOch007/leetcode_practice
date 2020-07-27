//
// Created by linjliang on 2020/7/27.
//

/*
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while ((l1 != nullptr) && (l2 != nullptr)){
            if (l1->val <= l2->val){ curr->next = l1; l1 = l1->next; }
            else{ curr->next = l2; l2 = l2->next; }
            curr = curr->next;
        }
        if (l1 == nullptr){ curr->next = l2; }
        if (l2 == nullptr){ curr->next = l1; }
        return dummy->next;
    }
};

/*
 * Note:
 *
 * 头节点可变的 需要使用dummy node
 */