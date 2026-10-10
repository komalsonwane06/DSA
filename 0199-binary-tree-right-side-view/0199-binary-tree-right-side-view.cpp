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
vector<int> ans;
int k = 1;
    vector<int> rightSideView(TreeNode* root) {
       solve(root, 0); 
       return ans;
    }

    void solve(TreeNode* node, int index){
        if(node == nullptr) return;
        if(k == index+1){
            ans.push_back(node->val);
            k++;
        }
        
        solve(node->right, index+1);
        solve(node->left, index+1);
    }
};