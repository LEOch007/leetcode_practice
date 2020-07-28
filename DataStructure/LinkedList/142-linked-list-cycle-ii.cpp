//
// Created by linjliang on 2020/7/28.
//

/*
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

 

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。


 

进阶：
你是否可以不用额外空间解决此题？

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
    ListNode *detectCycle(ListNode *head) {
        if ((head == nullptr) || (head->next == nullptr)) return nullptr;

        ListNode* meet = nullptr;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while ((fast != nullptr) && (fast->next != nullptr)){
            if (slow == fast){  // join
                meet = slow;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        if (meet == nullptr) return nullptr; // never join, no cycle
        else{                                // meet & head are going to join
            meet = meet->next;
            while (head != meet){
                head = head->next;
                meet = meet->next;
            }
            return meet;
        }
    }
};

/*
 * Note:
 *
 * 快慢指针的应用：
 * - 找到无环链表的中间节点
 * - 判断链表是否有环：快慢指针相遇
 * - 计算链表的环长度：快慢指针第二次相遇和第一次相遇之间所用的步数
 * - 找到入环的节点：头节点为p，快慢指针第一次相遇点的下一节点为q，p、q同时单步前进，相遇点即为入环点
 *   （注意：找入环点的方法中，q为相遇点的下一节点是因为我喜欢的实现是初始状态快指针比慢指针领先一步，如果快慢同地出发，则
 *   （q为为相遇点，不需要是相遇点的下一节点
 */