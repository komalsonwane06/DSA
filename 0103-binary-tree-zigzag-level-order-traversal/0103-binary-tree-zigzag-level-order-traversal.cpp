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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solve(root, 0);
        for(int i=0; i<ans.size(); i++){
            if(i%2){
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        return ans;
    }
    void solve(TreeNode* node, int index){
        if(node==nullptr) return;

        if(index >= ans.size()){
            ans.push_back({});
        }
        
        ans[index].push_back(node->val);

        solve(node->left, index+1);
        solve(node->right, index+1);
    }
};