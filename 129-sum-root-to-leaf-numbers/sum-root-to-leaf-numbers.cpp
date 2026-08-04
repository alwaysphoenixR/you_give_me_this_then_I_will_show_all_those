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
void func(TreeNode* root,string &s,int &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        s+=root->val+'0';
        // cout<<s<<endl;
        ans+=stoi(s);
        s.pop_back();
        return ;
    }
    s+=root->val+'0';
    // cout<<s<<endl;
    func(root->left,s,ans);
    func(root->right,s,ans);
    s.pop_back();
    // cout<<s<<endl;
}
    int sumNumbers(TreeNode* root) {
        int ans=0;
        string s="";
        func(root,s,ans);
        return ans; 
    }
};