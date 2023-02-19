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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool c=true;
        while(!q.empty()){
            int n=size(q);
            vector<int> v(n);
            for(int i=0;i<n;i++){
                TreeNode*t=q.front();
                q.pop();
                int in=(c)?i:n-i-1;
                v[in]=t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            c=!c;
            ans.push_back(v);
        }
        return ans;
    }
};