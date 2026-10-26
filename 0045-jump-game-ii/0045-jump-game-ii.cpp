class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int limit = nums[0], current = limit;
        int jump = 1;
        for(int i=1; i<nums.size()-1; i++){
            limit = max(limit, nums[i]+i);
            if(i == current){
                jump++;
                current = limit;
            }
        }
        return jump;
    }
};