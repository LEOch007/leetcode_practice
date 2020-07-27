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
    ListNode* partition0(ListNode* head, int x) {
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

    // another way to solve this same problem
    ListNode* partition(ListNode* head, int x){
        if ((head == nullptr) || (head->next == nullptr)) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* bigList_dummy = new ListNode(-2);    // stores the element >= x
        ListNode* bigList_curr = bigList_dummy;

        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        while ((curr != nullptr) && (bigList_curr != nullptr)){
            if (curr->val >= x){
                prev->next = curr->next;
                bigList_curr->next = curr;
                // move on
                curr = curr->next;
                bigList_curr = bigList_curr->next;
            } else{
                prev = curr;
                curr = curr->next;
            }
        }
        bigList_curr->next = nullptr;       // Give an end node to this big list
        prev->next = bigList_dummy->next;
        return dummy->next;
    }
};

int main(){
    int nums[] = {1,4,3,2,5,2};
    int x = 3;
    int size = 6;

    // construct a list
    ListNode* parray[size];
    for (int i = 0; i < size; ++i) {
        parray[i] = new ListNode(nums[i]);
    }
    for (int j = 0; j < size-1; ++j) {
        parray[j]->next = parray[j+1];
    }

    Solution s;
    ListNode* head = s.partition(parray[0],x);
    while (head != nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }

}

/*
 * Note:
 *
 * 当dummy node参与比较大小时，要确保它的大小不影响正常程序，如这里设置为INI_MIN。
 * 另一种方法是避免dummy node参与比较大小，先move on到它的下一节点开始正常程序。
 *
 * 此外，多创一条链表连接数据时，要注意该链表的终结点，往往需要显式地添加终结点nullptr
 */