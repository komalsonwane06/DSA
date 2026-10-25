class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> um;
        for(auto x : arr){
            um[x]++;
        }

        priority_queue<int> pq; 
        for(auto x : um){
            pq.push(x.second);
        }
        int n = arr.size();
        int count = 0;
        int ans = pq.size();
        while(!pq.empty()){
            count += pq.top();
            pq.pop();
            if(n/2 <= count){
                break;
            }
        }
        return ans - pq.size();
    }
};