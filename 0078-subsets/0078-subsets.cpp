class Solution {
public:
vector<vector<int>> v;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        solve(nums, 0, ans);
        return v;
    }

    void solve(vector<int> arr, int i, vector<int>& ans){
        if(i == arr.size()){
            v.push_back(ans);
            return;
        }

        ans.push_back(arr[i]);
        solve(arr, i+1, ans);

        ans.pop_back();
        solve(arr, i+1, ans);
    }
};