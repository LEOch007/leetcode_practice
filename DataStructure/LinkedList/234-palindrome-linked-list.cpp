//
// Created by linjliang on 2020/7/29.
//

/*
 * 请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false

示例 2:

输入: 1->2->2->1
输出: true

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

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
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr) {}
};

class Solution {
public:
    bool compareList(ListNode* p,ListNode* q){
        while ((p!= nullptr)&&(q != nullptr)){
            if (p->val != q->val) return false;
            else{
                p = p->next;
                q = q->next;
            }
        }
        return true;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while ((fast != nullptr)&&(fast->next != nullptr)){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* p){
        ListNode* prev = nullptr;
        ListNode* curr = p;
        while (curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if ((head == nullptr)||(head->next == nullptr)) return true;

        ListNode* mid = findMiddle(head);
        ListNode* rhead = reverseList(mid->next);
        bool ans = compareList(head, rhead);
        return ans;
    }
};

int main(){
    int nums[] = {1,2,2,1};
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
    cout<<s.isPalindrome(parray[0])<<endl;
}

/*
 * 判断回文链表：
 *
 * O(n)时间 O(1)空间：
 * 找到中点，翻转后半段，比较前半段和后半段
 */