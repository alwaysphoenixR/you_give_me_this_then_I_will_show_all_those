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
TreeNode* build_tree(int val, unordered_map<int, array<int, 2>>& m1){
    TreeNode* root=new TreeNode(val);
    if(m1[val][0]!=0){
        root->left=build_tree(m1[val][0],m1);
    }
    if(m1[val][1]!=0){
        root->right=build_tree(m1[val][1],m1);
    }
    return root;
}
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,array<int,2>>m1;
        unordered_map<int,int>m2;
        for(int i=0;i<descriptions.size();i++){
            m2[descriptions[i][1]]=1;
            int parent=descriptions[i][0];
            int child=descriptions[i][1];
            int flag=descriptions[i][2];
            if(flag==0){
                m1[parent][1]=child;
            }else{
                m1[parent][0]=child;
            }
            }
            int main_root;
        for(int i=0;i<descriptions.size();i++){
            if(m2.find(descriptions[i][0])==m2.end()){
                main_root=descriptions[i][0];
                m2[-1]=main_root;
                break;
            }
        }
        return  build_tree(main_root,m1);
    }
};