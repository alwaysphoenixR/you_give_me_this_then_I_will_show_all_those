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
bool same_tree(TreeNode* root1,TreeNode*root2 ){
    if(root1==NULL && root2==NULL)return true;
    if(root1==NULL || root2==NULL)return false;
    return (root1->val==root2->val) && same_tree(root1->left,root2->left) && same_tree(root1->right,root2->right);
}
    bool isSubtree(TreeNode* root, TreeNode* sr) {
        bool ans1=same_tree(root,sr);
        bool ans2=(root!=NULL)?isSubtree(root->left,sr):0;
                bool ans3=(root!=NULL)?isSubtree(root->right,sr):0;
                return ans1 || ans2 || ans3;


        // return same_tree(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};