/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<vector<int>> ans;
map<int, vector<pair<int, int>>> um;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);
        for(auto it : um){
            sort(it.second.begin(), it.second.end());
            vector<int> temp;
            for (auto p : it.second) {
                temp.push_back(p.second);
            }

            ans.push_back(temp);
        }
        return ans;
    }

    void solve(TreeNode* node, int pos, int row){
        if(node == NULL) return;
        um[pos].push_back({row, node->val});

        solve(node->left, pos-1, row+1);
        solve(node->right, pos+1, row+1);
    }
};