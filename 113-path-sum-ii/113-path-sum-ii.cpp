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
    void dfs(TreeNode* root, int targetSum,vector<int>& path,vector<vector<int>> & paths, int currentSum=0){
        currentSum+=root->val;
        path.push_back(root->val);
        
        if(!root->left && !root->right){
            if(currentSum==targetSum){
                paths.push_back(path);
            }
            path.pop_back();
            return;
        }
        
        if(root->left)  dfs(root->left,targetSum,path,paths,currentSum);
        if(root->right) dfs(root->right,targetSum,path,paths,currentSum);
        path.pop_back();    
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;
        if(root)    dfs(root,targetSum,path,paths);
        return paths;
    }
};