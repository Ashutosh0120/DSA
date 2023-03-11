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
    bool isSymmetric(TreeNode* root) {
        return (!root) or (g(root->left,root->right));
    }
    bool g(TreeNode *a,TreeNode *b){
        if(a==NULL or b==NULL) return a==b;
        if(a->val != b->val) return 0;
        return g(a->left,b->right) and g(a->right,b->left);
    }
};