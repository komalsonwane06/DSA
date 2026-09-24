class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> p1(n, -1);
        vector<int> p2(n , n);

        smallerLeft(heights, p1);
        smallerRight(heights, p2);

        long long ans = INT_MIN;
        for(int i=0; i<n; i++){
            long long x = p2[i]-p1[i]-1;
            ans = max(ans,1LL * heights[i]*x);
        }
        return ans;
    }

    void smallerLeft(vector<int> &arr, vector<int> &p1){
        stack<int> st;
        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                p1[i] = st.top();
            }
            st.push(i);
        }
    }

    void smallerRight(vector<int> &arr, vector<int> &p2){
        stack<int> st;
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                p2[i] = st.top();
            }
            st.push(i);
        }
    }
};