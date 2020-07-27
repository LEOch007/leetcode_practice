//
// Created by linjliang on 2020/7/27.
//

/*
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;

        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;

        ListNode* firstBig = nullptr;
        ListNode* before_firstBig = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = dummy;

        // move on until first Big
        while ((curr != nullptr) && (curr->val < x)){
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr) return dummy->next;
        if (curr->val >= x){
            firstBig = curr;
            before_firstBig = prev;
            // move
            prev = curr;
            curr = curr->next;
        }

        while (curr != nullptr){
            if (curr->val < x) {
                ListNode *temp = curr->next;
                prev->next = curr->next;
                curr->next = firstBig;
                before_firstBig->next = curr;
                before_firstBig = curr;
                // move
                curr = temp;
            } else{
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};

/*
 * Note:
 *
 * 当dummy node参与比较大小时，要确保它的大小不影响正常程序，如这里设置为INI_MIN。
 * 另一种方法是避免dummy node参与比较大小，先move on到它的下一节点开始正常程序。
 */