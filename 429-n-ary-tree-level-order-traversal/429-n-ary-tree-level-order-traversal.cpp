/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {       
        vector<vector<int>> res;
        queue<Node*> q;
        if(root)    q.push(root);
        while(q.size()){
            int sz=q.size();
            vector<int> currLevel;
            while(sz--){
                Node* curr=q.front();
                q.pop();
                currLevel.push_back(curr->val);
                for(auto& child:curr->children) q.push(child);
            }
            res.push_back(currLevel);
        }
        return res;
        
    }
};