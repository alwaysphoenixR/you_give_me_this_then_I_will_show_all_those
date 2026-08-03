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
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* px=NULL;
        TreeNode* py=NULL;
        int dx=-1;
        int dy=-1;
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int n=q.size();
            cnt++;
            for(int i=0;i<n;i++){
            auto tp=q.front();
            q.pop();
            if(tp->left){
                q.push(tp->left);
                   if(tp->left->val==x){px=tp;dx=cnt;}
                   if(tp->left->val==y){py=tp; dy=cnt;}
            }
            if(tp->right){
                q.push(tp->right);
                if(tp->right->val==x){px=tp;dx=cnt;}
                if(tp->right->val==y){py=tp;dy=cnt;}
            }
            }
        }
        if(px!=py && dx==dy)return true;
        return false;
        
    }
};