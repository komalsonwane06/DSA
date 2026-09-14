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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;

        ListNode* first = head;
        while(n--){
            first = first->next;
        }

        if(first == NULL) {
            return head->next;
        }
        
        ListNode* s = head;

        while(first!=NULL && first->next!=NULL){
            first=first->next;
            s= s->next;
        }
        
        s ->next = s->next->next;
        return head;
    }
};