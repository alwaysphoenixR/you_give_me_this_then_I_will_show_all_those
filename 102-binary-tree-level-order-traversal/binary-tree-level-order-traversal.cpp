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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)return {};
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            auto tp=q.front();
            q.pop();
            temp.push_back(tp->val);
            if(tp->left)q.push(tp->left);
            if(tp->right)q.push(tp->right);
        }
       ans.push_back(temp);
    }
        return ans;
    }
};