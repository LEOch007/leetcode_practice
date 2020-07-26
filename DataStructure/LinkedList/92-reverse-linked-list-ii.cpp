//
// Created by linjliang on 2020/7/26.
//

/*
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) return head;

        // use dummy node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // move forward until m-th
        ListNode* before = nullptr; // unchanged head node
        ListNode* ctail = nullptr;  // changed tail node
        ListNode* curr = dummy;
        int pos = 0;
        while ((pos<m) && (curr != nullptr)){
            before = curr;
            curr = curr->next;
            pos++;
        }
        ctail = curr;

        // move forward until n-th
        ListNode* prev = nullptr;   // record the previous node
        while ((pos<=n) && (curr != nullptr)){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            pos++;
        }
        before->next = prev;
        ctail->next = curr;
        return dummy->next;
    }
};