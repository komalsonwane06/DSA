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
    vector<vector<int>> levelOrder(TreeNode* root) {
        solve(root , 0);
        return ans;
    }
    void solve(TreeNode* node, int index){
        if(node == nullptr) return;

        if(ans.size() == index){
            ans.push_back({});
        }

        ans[index].push_back(node->val);

        solve(node -> left, index+1);
        solve(node -> right, index+1);
    }
};