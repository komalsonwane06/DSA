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
    ListNode *detectCycle(ListNode *head) {
        ListNode* s = head;
        ListNode* f = head;

        while(f != NULL && f->next != NULL){
            s = s->next;
            f = f->next->next;

            if(s == f){
                s = head;
                int i = 0;
                while(s != f){
                    s = s->next;
                    f = f->next;
                    i++;
                }
                return s;
            }
        }
        return nullptr;
    }
};