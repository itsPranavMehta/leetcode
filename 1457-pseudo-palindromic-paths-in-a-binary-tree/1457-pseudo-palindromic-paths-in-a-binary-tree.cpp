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
private:
    void traverse(int mask,TreeNode* root,int& palindromes){
        mask=mask ^(1<<(root->val));
        if(!root->left && !root->right){
            if(mask==0 || (mask&(mask-1))==0){
                palindromes++;
            }
            return;
        }
        if(root->left){
            traverse(mask,root->left,palindromes);
        }
        if(root->right){
            traverse(mask,root->right,palindromes);
        }
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res=0;
        traverse(0,root,res);
        return res;
        
    }
};