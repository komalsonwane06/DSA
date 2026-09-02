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
        if(head == NULL) return NULL;

        // Remove matching nodes from the beginning
        while(head != NULL && head->val == val) {
            head = head->next;
        }

        if(head == NULL) return NULL;

        ListNode* pos = head;

        // Remove matching nodes after head
        while(pos->next != NULL) {
            if(pos->next->val == val) {
                pos->next = pos->next->next;
            }
            else {
                pos = pos->next;
            }
        }

        return head;
    }
};