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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* pos = head;

        while(pos->next != NULL) {
            if(pos->val == pos->next->val) {
                pos->next = pos->next->next;
            }
            else {
                pos = pos->next;
            }
        }

        return head;
    }
};