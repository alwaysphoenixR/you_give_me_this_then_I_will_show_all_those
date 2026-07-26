/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
void f1(vector<int>&ans,Node * root){
    for(auto child:root->children){
        f1(ans,child);
    }
    ans.push_back(root->val);
}
    vector<int> postorder(Node* root) {
       if(root==NULL)return {};
        vector<int>ans;
        f1(ans,root);
        return ans;
        
    }
};