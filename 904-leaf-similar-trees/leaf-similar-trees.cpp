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
bool check_thru(TreeNode* root ,vector<int>& temp,int &idx){
    if(root==NULL)return 1;
    // else if(root==NULL && !temp.empty())return 0;
    if(root->left==NULL && root->right==NULL && root->val==temp[idx]){idx++;return 1;}
    else if (root->left==NULL && root->right==NULL && root->val!=temp[idx])return 0;
    bool a1=check_thru(root->left,temp,idx);
    bool a2=check_thru(root->right,temp,idx);
    return a1&&a2;
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int>nums;
        vector<int>temp;
     go_thru(root1,nums);
     for(auto i:nums){
        cout<<i<<" ";
     }
     cout<<endl;
     int i=0;
     return check_thru(root2,nums,i) && i==nums.size();
    //  go_thru(root2,temp);
    //  return (temp==nums);
        
    }
};