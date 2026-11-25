class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        unordered_map<char, int> um;
        for(auto x : tasks){
            um[x]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto x : um){
            pq.push({x.second, x.first});
        }

        while(!pq.empty()){
            vector<pair<int, char>> temp;
            int i = n + 1;
            while(i > 0 && !pq.empty()){
                i--;
                ans++;
                temp.push_back({pq.top().first - 1, pq.top().second});
                pq.pop();
            }

            while(temp.size()){
                if(temp.back().first > 0){
                    pq.push({temp.back().first, temp.back().second});
                }
                temp.pop_back();
            }

            if(!pq.empty()){
                ans += i;
            }
        }
        return ans;
    }
};
