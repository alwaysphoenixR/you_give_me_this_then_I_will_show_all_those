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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long , vector<long long >, greater<long long >> pq;
        // priority_queue<int>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            long long sum=0;
            for(int i=0;i<n;i++){
                auto tp=q.front();
                q.pop();
                sum+=tp->val;
                if(tp->left)q.push(tp->left);
                if(tp->right)q.push(tp->right);
            }
            if(pq.size()<k)pq.push(sum);
            else {
                if(pq.top()<sum){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        if(pq.size()<k)return -1;
        return pq.top();
        
    }
};