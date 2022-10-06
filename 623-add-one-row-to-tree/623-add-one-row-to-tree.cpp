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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int curr_depth=1;
        if(depth==1)
        {
           TreeNode *head=new TreeNode(val);
            head->left=root;
            return head;
        }
        while(q.size())
        {
            curr_depth++;
            bool addnodes=depth==curr_depth;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                TreeNode* left=temp->left,*right=temp->right;
                if(addnodes)
                {
                    TreeNode* addn1=new TreeNode(val),*addn2=new TreeNode(val);
                    temp->left=addn1,addn1->left=left;
                    temp->right=addn2,addn2->right=right;
                }
                if(left)    q.push(left);
                if(right)   q.push(right);
            }
            if(addnodes)
                return root;
        }
        return root;
    }
};