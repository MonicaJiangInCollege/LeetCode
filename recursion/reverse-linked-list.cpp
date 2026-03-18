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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;  // 前一个节点，初始为 nullptr
        ListNode* curr = head;      // 当前节点，从头开始
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // 保存下一个节点
            curr->next = prev;  // 反转指针方向
            prev = curr;  // 前一个节点后移
            curr = nextTemp; // 当前节点后移
        }
        return prev; // prev 成为新的头节点
    }
};