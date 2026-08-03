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
void dfs(TreeNode * root,map<int,vector<int>>&m1,int level){
    if(root==NULL)return;
    m1[level].push_back(root->val);
    dfs(root->left,m1,level+1);
    dfs(root->right,m1,level+1);
}
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        map<int,vector<int>>m1;

        if(root==NULL)return {};
        vector<vector<int>>f_ans;
        dfs(root,m1,0);
        for(auto [key,val]:m1){
            f_ans.push_back(val);
        }
        reverse(f_ans.begin(),f_ans.end());
        return f_ans;
    
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     vector<vector<int>>ans;

    //     while(!q.empty()){
    //         int n=q.size();
    //         vector<int>temp;
    //         for(int i=0;i<n;i++){
    //              auto tp=q.front();
    //              q.pop();
    //              temp.push_back(tp->val);
    //              if(tp->left)q.push(tp->left);
    //              if(tp->right)q.push(tp->right);
    //         }
    //         ans.push_back(temp);
    //     }
    //   reverse(ans.begin(),ans.end());
    //   return ans;
    }
};