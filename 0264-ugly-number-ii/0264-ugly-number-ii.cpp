class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        set<long long> us;

        pq.push(1);
        us.insert(1);
        long long current = 1;
        while(n){
            current = pq.top(); pq.pop();
            n--;
            vector<int> fac = {2,3,5};
            for(int i=0; i<3; i++){
                long long next_u = fac[i] * current;
                if(us.find(next_u) == us.end()){
                    pq.push(next_u);
                    us.insert(next_u);
                }
            }
        }
        return static_cast<int>(current);
    }
};