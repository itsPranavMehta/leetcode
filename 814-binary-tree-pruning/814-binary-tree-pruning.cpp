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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)   return nullptr;
        TreeNode* left=pruneTree(root->left),*right=pruneTree(root->right);
        if(!left)   root->left=nullptr;
        if(!right)  root->right=nullptr;
        if(!left && !right && root->val==0) return nullptr;
        return root;
    }
};