//
// Created by linjliang on 2020/9/18.
//

// Sure

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x){}
};

class Solution {
public:
    /**
     * 合并两个升序链表
     * @param l1 ListNode类 链表1
     * @param l2 ListNode类 链表2
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        while (curr1 != nullptr && curr2 != nullptr){
            if (curr1->val < curr2->val){
                curr->next = curr1;
                curr1 = curr1->next;
            }
            else{
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }
        if (curr1 == nullptr) curr->next = curr2;
        else curr->next = curr1;

        return dummy->next;
    }
};