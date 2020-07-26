//
// Created by linjliang on 2020/7/26.
//

/*
 * 反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            // two pointers move forward together
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};