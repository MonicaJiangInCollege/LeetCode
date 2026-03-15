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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        // 1. 计算两个链表的长度
        int lenA = 0, lenB = 0;
        ListNode* curA = headA, * curB = headB;
        while (curA) {
            lenA++;
            curA = curA->next;
        }
        while (curB) {
            lenB++;
            curB = curB->next;
        }

        // 2. 让较长的链表先走差值步
        curA = headA;
        curB = headB;
        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff--) {
                curA = curA->next;
            }
        }
        else {
            int diff = lenB - lenA;
            while (diff--) {
                curB = curB->next;
            }
        }

        // 3. 同时前进，直到相遇或都为空
        while (curA != curB) {
            curA = curA->next;
            curB = curB->next;
        }
        return curA; // 如果没交点，curA 和 curB 最终都是 nullptr，返回 nullptr
    }
};