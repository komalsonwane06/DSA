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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return solve(root->left, root->right);
    }

    bool solve(TreeNode* lefty, TreeNode* righty){
        if(lefty==NULL && righty==NULL) return true;
        if(lefty==NULL || righty==NULL) return false;
        if(lefty->val != righty->val) return false;

        bool a = solve(lefty->left,righty->right);
        bool b = solve(lefty->right,righty->left);

        return a&&b;
    }
};