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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* s = head;
        while(s != NULL){
            ans.push_back(s->val);
            s = s->next;
        }
        vector<int> p2(ans.size(), 0);
        stack<int> st;
        for(int i=ans.size()-1; i>=0; i--){
            while(!st.empty() && ans[st.top()] <= ans[i]){
                st.pop();
            }
            if(!st.empty()){
                p2[i] = ans[st.top()];
            }
            st.push(i);
        }
        return p2;
    }
};