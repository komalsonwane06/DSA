class Solution {
public:
    int calculate(string s) {
        stack<char> st;
        stack<int> num;
        int x = 0;
        for(char ch : s) {
            if(ch == ' '){
                continue;
            }
            else if(isdigit(ch)){
                x = x * 10 + (ch - '0');
            }
            else{
                num.push(x);
                x = 0;
                while(num.size() > 1 && !st.empty() && check(ch) <= check(st.top())){
                    calculateTop(st, num);
                }
                st.push(ch);
            }
        }
        num.push(x);

        while(!st.empty() && num.size() > 1){
            calculateTop(st, num);
        }

        return num.top();
    }

    int check(char c){
        if(c == '+' || c == '-') return 1;
        return 2;
    }

    int calculateTop(stack<char> &st, stack<int> &num){
            int a = num.top(); num.pop();
            int b = num.top(); num.pop();
            if(st.top() == '+') num.push(a+b);
            else if(st.top() == '-') num.push(b-a);
            else if(st.top() == '*') num.push(a*b);
            else num.push(b/a);
            st.pop();
            return num.top();
    }
};