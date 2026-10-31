class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x : nums){
            if(x){
                pq.push(x);
            }
        }
        int count = 0;
        int dif = 0;
        while(!pq.empty()){
            int a = pq.top(); pq.pop();
            if(dif < a){
                dif = a;
                count++;
            }
        }
        return count;
    }
};