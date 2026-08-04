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
void count(TreeNode* root,int &cnt ,int curr_maxii){
    if(root==NULL)return;
    int val=root->val;
    if(curr_maxii<=val)cnt++;
    curr_maxii=max(val,curr_maxii);
    count(root->left,cnt,curr_maxii);
    count(root->right,cnt,curr_maxii);
}
    int goodNodes(TreeNode* root) {
        int cnt=0;
        int curr_maxii=INT_MIN;
        count(root,cnt,curr_maxii);
        return cnt;
    }
};