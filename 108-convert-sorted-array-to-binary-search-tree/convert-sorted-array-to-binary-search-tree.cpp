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
TreeNode* build_tree(vector<int>&nums,int start,int end){
    if(end<start){
        return NULL;
    }
    if(start==end){
        TreeNode* n1=new TreeNode(nums[start]);
        return n1;
    }
    int mid=(start+end)/2;
    auto l1=build_tree(nums,start,mid-1);
    auto r1=build_tree(nums,mid+1,end);
    TreeNode* n2=new TreeNode(nums[mid]);
    n2->left=l1;
    n2->right=r1;
    return n2;
}
void in_order(TreeNode* root){
    if(root==NULL)return;
    in_order(root->left);
    cout<<root->val<<" ";
    in_order(root->right);
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto root= build_tree(nums,0,nums.size()-1);
        in_order(root);
        return root;
    }
};