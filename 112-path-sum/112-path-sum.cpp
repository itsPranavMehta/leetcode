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
    bool helper(TreeNode* root,int sum,int target)
    {
        sum+=root->val;
        if(sum==target && !root->left && !root->right) return true;
        if(root->left)
            if(helper(root->left,sum,target))   return true;
        if(root->right)
            if(helper(root->right,sum,target))   return true;
        
        return false;        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)   return false;
        return helper(root,0,targetSum);
    }
};