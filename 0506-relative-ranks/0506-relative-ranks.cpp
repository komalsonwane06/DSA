class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq(score.begin(), score.end());
        map<int, string> um;
        
        if(!pq.empty()){
            um[pq.top()] = "Gold Medal"; pq.pop();
        }    
        if(!pq.empty()){
            um[pq.top()] = "Silver Medal"; pq.pop();
        }
        if(!pq.empty()){
            um[pq.top()] = "Bronze Medal";
            pq.pop();
        }

        int i = 4;
        while(!pq.empty()){
            um[pq.top()] = to_string(i++);
            pq.pop();
        }

        vector<string> ans;
        for(int i=0; i<score.size(); i++){
            ans.push_back(um[score[i]]);
        }
        return ans;
    }
};