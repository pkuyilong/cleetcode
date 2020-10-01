//
// Created by 麻艺龙 on 2020/10/1.
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 * 思路
 * 使用快慢指针可以判断出是否有环，当快慢指针相遇的时候，此时，快指针比满指针多走了一个环的长度
 * 所以要想找出换的入口点，可以设置一个指针指向头结点，原来的慢指针继续移动，两者每次都移动一小步
 * 那么下一次相遇的点就是环的入口点
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // cycle  exists
            if (slow == fast) {
                ListNode* cur = head;
                while (cur != slow) {
                    cur = cur->next;
                    slow = slow->next;
                }
                return cur;
            }
        }
        return nullptr;
    }
};