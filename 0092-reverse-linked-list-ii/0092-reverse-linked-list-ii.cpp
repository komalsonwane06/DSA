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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right)
            return head;

        ListNode* s = head;

        // s ko left ke previous node par le jao
        for (int i = 1; i < left - 1; i++) {
            s = s->next;
        }

        ListNode* f;

        if (left == 1)
            f = head;
        else
            f = s->next;

        // Number of nodes to reverse
        int count = right - left + 1;

        ListNode* curr = NULL;
        
        while (count--) {
            ListNode* temp = new ListNode(f->val);
            temp->next = curr;
            curr = temp;
            f = f->next;
        }

        if (left == 1) {
            head = curr;
        } 
        else {
            s->next = curr;
        }

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = f;

        return head;
    }
};