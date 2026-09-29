class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        queue<int> qu;
        int n = students.size()-1;
        for(int i=0; i<=n; i++){
            qu.push(students[i]);
            st.push(sandwiches[n-i]);
        }
        
        while(!st.empty()){
            int t = qu.size();
            bool flag = true;
            while(t--){
                if(qu.front() == st.top()){
                    qu.pop(); st.pop();
                    flag = false;
                    break;
                }
                else{
                    qu.push(qu.front());
                    qu.pop();
                }
            }
            if(flag){
                break;
            }
        }
        return qu.size();
    }
};