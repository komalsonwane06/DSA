class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i=n-1; i>=0; i--){
            int k = 0;
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
                k++;
            }
            if(st.empty()){
                ans[i] = k;
            }
            else if(!st.empty()){
                ans[i] = k + 1;
            }
        
            st.push(i);
        }
        
        return ans;
    }
};