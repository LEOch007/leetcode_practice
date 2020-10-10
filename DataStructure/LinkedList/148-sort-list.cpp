//
// Created by linjliang on 2020/7/27.
//

/*
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4

示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

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
    // 归并排序
    ListNode* sortList0(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* findMiddle(ListNode* p){
        if (p == nullptr) return p;

        ListNode* fast = p;
        ListNode* slow = p;
        while ((fast->next != nullptr) && (fast->next->next != nullptr)){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* p, ListNode* q){
        if (p == nullptr) return q;
        if (q == nullptr) return p;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while ((p != nullptr) && (q != nullptr)){
            if (p->val <= q->val){
                curr->next = p;
                p = p->next;
            } else{
                curr->next = q;
                q = q->next;
            }
            curr = curr->next;
        }
        if (p == nullptr) curr->next = q;
        if (q == nullptr) curr->next = p;
        return dummy->next;
    }

    ListNode* mergeSort(ListNode* p){
        if ((p == nullptr)||(p->next == nullptr)) return p;

        ListNode* mid = findMiddle(p);
        ListNode* p2 = mid->next;       // the head node of second half
        mid->next = nullptr;            // divide into two lists

        ListNode* first = mergeSort(p);
        ListNode* second = mergeSort(p2);

        ListNode* head = mergeTwoLists(first,second);
        return head;
    }

    // 快速排序
    ListNode* sortList(ListNode* head) {

    }
};

/*
 * Note:
 *
 * 归并排序的链表实现：O(nlogn)时间复杂度 O(1)空间复杂度
 * 而数组实现为： O(nlogn)时间复杂度 O(n)空间复杂度
 *
 * 最大区别在于：链表的实现中 需要使用快慢指针找到中间节点
 *
 * 实现注意点：
 * 归并排序中间节点需要断开
 * 递归终止条件为 单个数据元，故而应是p->next为空
 */