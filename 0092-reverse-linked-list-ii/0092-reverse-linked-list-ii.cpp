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

    ListNode* reverse(ListNode* head){

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* frwd=NULL;
        while(curr){
            frwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=frwd;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr=head;
        int i=1;
        ListNode* prev=NULL;
        ListNode* frwd=NULL;
        ListNode* temp=head;
        while(i<right){
            if(i<left){
               prev=curr;
               curr=curr->next;
            }
            temp=temp->next;
            i++;
        }
        if(temp->next){
            frwd=temp->next;
            temp->next=NULL;
        }
        ListNode* rev=reverse(curr);

        if(prev!=NULL){
            prev->next=rev;
        }
        else{
            head=rev;
        }
        curr->next=frwd;
        return head;

    }
};