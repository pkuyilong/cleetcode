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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) {
            return head;
        }
        if (m == n) {
            return head;
        }
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        ListNode* start = dummyNode;
        ListNode* end = dummyNode;
        ListNode* prev = dummyNode;
        ListNode* next = dummyNode;
        int idx = 0;

        while (cur) {
            if (idx == m-1) {
                prev = cur;
                start = cur->next;
            }
            if (idx == n) {
                end = cur;
                next = cur->next;
                break;
            }
            // 如果一下两行放在while的开头，那么会跳过idx==0的情况，这不是期望的操作
            cur = cur->next;
            idx++;
        }

        reverseList(start, end);
        prev->next = end;
        start->next = next;
        return dummyNode->next;
    }

    void reverseList(ListNode* start, ListNode* end) {
        if (start == end) {
            return;
        }
        reverseList(start->next, end);
        start->next->next = start;
        start->next = nullptr;
    }
};
