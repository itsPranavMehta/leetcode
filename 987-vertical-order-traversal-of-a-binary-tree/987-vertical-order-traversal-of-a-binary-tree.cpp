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
    void traversal(map<int,map<int,vector<int>>>& record,TreeNode* root, int col,int lvl){
        if(!root)   return;
        record[col][lvl].push_back(root->val);
        traversal(record,root->left,col-1,lvl+1);
        traversal(record,root->right,col+1,lvl+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> record;
        traversal(record,root,0,0);
        vector<vector<int>> res;
        for(auto& v:record){
            vector<int> t;
            for(auto& vec: v.second){
                sort(vec.second.begin(),vec.second.end());
                for(auto& i:vec.second)    t.push_back(i);
            }
            res.push_back(t);
        }
        return res;
    }
};