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
pair<int, TreeNode*> ans = {0, nullptr};
    int findBottomLeftValue(TreeNode* root) {
        solve(root, 0);
        if(root->left==NULL && root->right==NULL) return root->val;
        if(ans.second == NULL) return NULL;
        return ans.second->val;
    }
    void solve(TreeNode* node, int index){
        if(node == nullptr) return;

        if(ans.first < index){
            ans.second = node;
            ans.first = index;
        }
        solve(node->left, index+1);
        solve(node->right, index+1);
    }
};