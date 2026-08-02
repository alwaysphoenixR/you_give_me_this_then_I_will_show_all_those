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
pair<string, TreeNode*> get_ans(TreeNode* root) {
    if (root == NULL) {
        return {"", NULL};
    }

    auto [left, nl] = get_ans(root->left);
    auto [right, nr] = get_ans(root->right);

    if (nl == NULL && nr == NULL) {
        string temp = to_string(root->val);
        return {temp, root};
    }
    else if (nl != NULL && nr == NULL) {
        string temp = to_string(root->val) + "(" + left + ")";
        return {temp, root};
    }
    else if (nl == NULL && nr != NULL) {
        string temp = to_string(root->val) + "()(" + right + ")";
        return {temp, root};
    }
    else {
        string temp = to_string(root->val) + "(" + left + ")(" + right + ")";
        return {temp, root};
    }
}
    string tree2str(TreeNode* root) {
    auto ans =get_ans(root);
    return ans.first;
    }
};