//
// Created by linjliang on 2020/7/26.
//

/*
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

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
        if (head == nullptr) return head;

        ListNode* curr = head;
        while (curr->next != nullptr){
            if (curr->val == curr->next->val){  // duplicate
                curr->next = curr->next->next;
            } else{
                curr = curr->next;
            }
        }
        return head;
    }
};

/*
 * Note:
 *
 * A->B->C 删除 B，A->next = C
 * 访问 X.val, X.next 一定要保证: X不是nullptr
 */