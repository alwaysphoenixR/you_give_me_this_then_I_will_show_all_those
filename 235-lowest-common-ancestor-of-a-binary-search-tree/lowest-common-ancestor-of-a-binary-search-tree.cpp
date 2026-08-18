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
TreeNode* get_ans(TreeNode* root,TreeNode* p,TreeNode* q){
    if((root->val>p->val && root->val<q->val )|| (root->val>q->val && root->val<p->val))return root;
    if((root==p && root->val<q->val) || (root==p && root->val>q->val))return p;
    if((root==q && root->val<p->val) || (root==q && root->val>p->val))return q;
    if(root->val >p->val && root->val>q->val)return get_ans(root->left,p,q);
    else return get_ans(root->right,p,q);
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return get_ans(root,p,q);
        
    }
};