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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> p;
            for(int i=0;i<n;i++){
                TreeNode *c=q.front();
                q.pop();
                p.push_back(c->val);
                if(c->left) q.push(c->left);
                if(c->right)q.push(c->right);
            }
            v.push_back(p.back());
        }
        return v;
    }
};