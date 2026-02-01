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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL)
            return NULL;
        else if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;
        else {
            ListNode* dummy=new ListNode();
            ListNode* current = dummy;

            ListNode* pointer1 = list1;
            ListNode* pointer2 = list2;

            while (pointer1 != NULL && pointer2 != NULL) {
                if (pointer1->val <= pointer2->val) {
                    current->next = pointer1;
                    pointer1 = pointer1->next;
                    current = current->next;
                }
                else {
                    current->next = pointer2;
                    pointer2 = pointer2->next;
                    current = current->next;
                }
            }

            if (pointer1 == NULL)
                current->next = pointer2;
            else
                current->next = pointer1;

            ListNode* answer = dummy->next;
            delete dummy;
            return answer;
        }
    }
};