class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int ans = 0;
        int n = mat[0].size();
        vector<int> arr(n, 0);
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == '1'){
                    arr[j] += 1;
                }
                else{
                    arr[j] = 0;
                }
            }
            
            vector<int> p1(n,-1);
            vector<int> p2(n, n);

            smallerLeft(arr, p1);
            smallerRight(arr, p2);

            for(int k=0; k<n; k++){
                int x = p2[k] - p1[k] - 1;
                ans = max(ans, arr[k] * x);
            }
        }
        return ans;
    }


    void smallerLeft(vector<int> arr, vector<int> &p1){
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
    void smallerRight(vector<int> arr, vector<int> &p2){
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