class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> v (n, INT_MIN);

        for(int i=n-1; i>=0; --i){
            while(!st.empty() && nums[i] >= st.top()){
                st.pop();
            }
            if(!st.empty()) v[i] = st.top();
            st.push(nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (v[i] == INT_MIN) {
                for (int j = 0; j <= i; j++) {
                    if (nums[j] > nums[i]) {
                        v[i] = nums[j];
                        break;
                    }
                    else{
                        v[i] = -1;
                    }
                }
            }
        }

        return v;
    }
};