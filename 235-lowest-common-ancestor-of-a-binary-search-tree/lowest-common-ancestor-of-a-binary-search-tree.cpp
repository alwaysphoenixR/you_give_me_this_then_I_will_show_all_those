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
bool get_ans(TreeNode* root,TreeNode* p,TreeNode* q,bool &done,TreeNode* &ans){
    if(root==NULL)return false;
    bool l=get_ans(root->left,p,q,done,ans);
    bool r=get_ans(root->right,p,q,done,ans);
    if((l && r) && !done){
        ans=root;
        done=true;
        return true;
    }
    if(root==p && (l||r) && !done){
        ans=p;
        done=true;
        return true;
    }
    if(root==q && (l||r) && !done){
        ans=q;
        done=true;
        return true;
    }
    if(root==p || root==q)return true;
    return l||r;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        bool done =false;
        get_ans(root,p,q,done,ans);
        return ans;
        
    }
};