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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int a=0;
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int s=q.size();
            int mi=q.front().second;
            int f,l;
            for(int i=0;i<s;i++){
                int c=q.front().second-mi;
                TreeNode *p=q.front().first;
                q.pop();
                if(i==0) f=c;
                if(i==s-1) l=c;
                if(p->left) q.push({p->left,(long long)2*c+1});
                if(p->right) q.push({p->right,(long long)2*c+2});
            }
            a=max(a,l-f+1);
        }
        return a;
    }
};