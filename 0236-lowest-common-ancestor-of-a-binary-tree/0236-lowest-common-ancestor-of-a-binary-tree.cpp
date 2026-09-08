/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool f = false;
bool s = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root == p || root == q) return root;

        TreeNode* l = lowestCommonAncestor(root->left, p , q);
        TreeNode* r = lowestCommonAncestor(root->right, p , q);

        if(l == NULL && r == NULL) return NULL;
        else if(l != NULL && r == NULL)return l;
        else if(l == NULL && r != NULL)return r;
        else return root;
    }
};