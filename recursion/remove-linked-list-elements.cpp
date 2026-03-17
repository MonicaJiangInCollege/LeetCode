/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 创建一个虚节点，方便处理头节点删除的情况
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->val == val) {
                // 删除当前节点
                prev->next = curr->next;
                delete curr;  // 释放内存（非必须）
                curr = prev->next; // 移动到下一个节点
            }
            else {
                // 正常前进
                prev = curr;
                curr = curr->next;
            }
        }

        // 获取新的头节点
        ListNode* newHead = dummy->next;
        delete dummy;   // 释放虚节点
        return newHead;
    }
};