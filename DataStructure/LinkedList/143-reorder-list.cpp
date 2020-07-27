//
// Created by linjliang on 2020/7/27.
//

/*
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.

示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

 */

#include <iostream>
#include <vector>
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
    void reorderList0(ListNode* head) {
        if (head == nullptr) return;

        vector<ListNode*> num_vec;
        ListNode* curr = head;
        while (curr != nullptr){
            num_vec.push_back(curr);
            curr = curr->next;
        }

        curr = head;
        int i = 0; int j = num_vec.size();
        while (true){
            j--;
            if (i>=j) { break;}
            curr->next = num_vec[j];
            curr = curr->next;

            i++;
            if (i>=j) { break;}
            curr->next = num_vec[i];
            curr = curr->next;
        }
        curr->next = nullptr; // add end node
    }

    ListNode* findMiddle(ListNode* p){
        if ((p == nullptr) || (p->next == nullptr)) return p;

        ListNode* slow = p;
        ListNode* fast = p->next;
        while ((fast != nullptr) && (fast->next != nullptr)){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* p){
        if (p == nullptr) return p;

        ListNode* prev = nullptr;
        ListNode* curr = p;
        while (curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            // move on
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void mergeList(ListNode* head, ListNode* rhead){
        if (head == nullptr) return;
        if (rhead == nullptr) return;

        ListNode* curr = head;
        while (true){
            ListNode* temp = curr->next;

            // link reverse list
            curr->next = rhead;
            curr = curr->next;
            if (curr == nullptr) break;
            rhead = rhead->next;

            // link original list
            curr->next = temp;
            curr = curr->next;
            if (curr == nullptr) break;
        }
    }

    void reorderList(ListNode* head){
        if (head == nullptr) return;

        ListNode* mid = findMiddle(head);
        ListNode* rhead = reverseList(mid->next);
        mid->next = nullptr;
        mergeList(head,rhead);
    }
};

int main(){
    int nums[] = {1,2,3,4};
    int size = 4;

    // construct a list
    ListNode* parray[size];
    for (int i = 0; i < size; ++i) {
        parray[i] = new ListNode(nums[i]);
    }
    for (int j = 0; j < size-1; ++j) {
        parray[j]->next = parray[j+1];
    }

    Solution s;
    s.reorderList(parray[0]);
    ListNode* head = parray[0];
    while (head != nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
}

/*
 * Note:
 *
 * 链表重排需要考虑终结点，增加nullptr来终止
 *
 * 方法一：引入了vector来处理，O(n)空间复杂度
 *
 * 方法二：找到中间节点，翻转后半段，依次合并前半段和翻转后的后半段
 *
 *
 */