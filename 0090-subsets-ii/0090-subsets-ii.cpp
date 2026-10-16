class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        set<vector<int>> ans;
        solve(nums, 0, temp, ans);
        vector<vector<int>> v;
        for(auto x: ans){
            v.push_back(x);
        }
        return v;
    }

    void solve(vector<int> arr, int i, vector<int> &temp, set<vector<int>> &ans){
        if(i == arr.size()){
            ans.insert(temp);
            return;
        }

        temp.push_back(arr[i]);
        solve(arr, i+1, temp, ans);

        temp.pop_back();
        solve(arr, i+1, temp, ans);
    }
};