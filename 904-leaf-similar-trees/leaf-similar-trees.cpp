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
void go_thru(TreeNode* root,vector<int>&nums){
    if(root==NULL)return ;
    if(root->left==NULL && root->right==NULL){
        nums.push_back(root->val);
        return ;
    }
    go_thru(root->left,nums);
    go_thru(root->right,nums);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int>nums;
        vector<int>temp;
     go_thru(root1,nums);
     go_thru(root2,temp);
     return (temp==nums);
        
    }
};