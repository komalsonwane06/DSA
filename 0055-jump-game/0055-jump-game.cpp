class Solution {
public:
    bool canJump(vector<int>& nums) {
        int limit = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(limit < i){
                return false;
            }
            limit = max(limit , nums[i]+i);
        }
        return true;
    }
};