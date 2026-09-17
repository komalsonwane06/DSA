class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (char ch : s) {
            if (!st.empty() && st.top().first == ch) {
                st.top().second++;

                if (st.top().second == k) {
                    st.pop();
                }
            }
            else {
                st.push({ch, 1});
            }
        }

        string ans = "";

        while (!st.empty()) {
            auto [ch, count] = st.top();
            st.pop();

            ans.append(count, ch);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};