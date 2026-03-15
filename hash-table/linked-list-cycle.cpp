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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) 
            return false; // 空链表无环

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; // 慢指针走一步
            fast = fast->next->next;  // 快指针走两步

            if (slow == fast) { // 相遇则存在环
                return true;
            }
        }

        return false; // 快指针到达末尾，无环
    }
};