class Solution {
public:
bool can_we(int row,int col,vector<int>&placed){
    for(int i=0;i<row;i++){
        if(placed[i]==col || abs(row-i)==abs(col-placed[i])){
            return false;
        }
    }
    return true;
}
void f1(int &ans,vector<int>&placed,int row){
    if(row>=placed.size()){
        ans++;
        return ;
    }
    for(int i=0;i<placed.size();i++){
        if(can_we(row,i,placed)){
            placed[row]=i;
            f1(ans,placed,row+1);
            placed[row]=-1;
        }
    }
}
    int totalNQueens(int n) {
        int ans=0;
        vector<int>placed(n,-1);
        f1(ans,placed,0);
        return ans;
    }
};