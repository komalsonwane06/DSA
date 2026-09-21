class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n =nums2.size();
        unordered_map<int, int> um;
        for(auto num: nums2){
            um[num] = -1;
        }
        
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }

            if(!st.empty()) um[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++){
            nums1[i] = um[nums1[i]];
        }

        return nums1;
    }
};