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
    void m(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&pt){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *c=q.front(); q.pop();
            if(c->left){
                pt[c->left]=c;
                q.push(c->left);
            }
            if(c->right){
                pt[c->right]=c;
                q.push(c->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        unordered_map<TreeNode*,TreeNode*>pt;
        m(root,pt);
        unordered_map<TreeNode*,bool> v;
        queue<TreeNode*>q;
        q.push(t);
        v[t]=true;
        int l=0;
        while(!q.empty()){
            int n=q.size();
            if(l++==k) break;
            for(int i=0;i<n;i++){
                TreeNode *c=q.front(); q.pop();
                if(c->left and !v[c->left]) {
                    q.push(c->left);
                    v[c->left]=true;
                }
                if(c->right and !v[c->right]) {
                    q.push(c->right);
                    v[c->right]=true;
                }
                if(pt[c] and !v[pt[c]]){
                    q.push(pt[c]);
                    v[pt[c]]=true;
                }
            }
        }
        vector<int>a;
        while(!q.empty()){
            TreeNode *c=q.front(); q.pop();
            a.push_back(c->val);
        }
        return a;
    }
};