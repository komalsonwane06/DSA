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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        int i = 1;
        while(i<k){
            first = first->next;
            i++;
        }
        ListNode* start = first;
        while(first->next!=NULL){
            first = first->next;
            second =second->next;
        }

        swap(start->val, second->val);
        return head;
    }
};