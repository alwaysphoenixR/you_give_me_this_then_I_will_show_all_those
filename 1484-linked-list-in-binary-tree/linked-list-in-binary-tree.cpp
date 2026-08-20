/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
bool get_ans(ListNode* head,TreeNode* root){
    if(head==NULL)return true;
    if(root==NULL)return false;
    if(head->val!=root->val)return false;
    return get_ans(head->next,root->left)||get_ans(head->next,root->right);
}
    bool isSubPath(ListNode* head, TreeNode* root) {
      if(root==NULL){
        return get_ans(head,root);
      }
      bool a1=get_ans(head,root);
      bool a2=isSubPath(head,root->left);
      bool a3=isSubPath(head,root->right);
      return a1||a2||a3;
    }
};