//
// Created by linjliang on 2020/7/26.
//

/*
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

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
    ListNode* deleteDuplicates(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) return head;

        // introduce dummy node when the head node is possibly deleted
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* curr = dummy;
        int duplicate_num = -2;
        while ((curr->next != nullptr) && (curr->next->next != nullptr)){
            if (curr->next->val == curr->next->next->val){  // begin duplication
                duplicate_num = curr->next->val;
                // skip all duplication
                while((curr->next!=nullptr) && (curr->next->val==duplicate_num)){
                    curr->next = curr->next->next;
                }
            } else{
                curr = curr->next;
            }
        }
        return dummy->next;
    }

};