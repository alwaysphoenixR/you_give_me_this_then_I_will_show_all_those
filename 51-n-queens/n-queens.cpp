class Solution {
public:
bool can_we(int row,int col,vector<int>&placed){
    for(int i=0;i<row;i++){
        if(col==placed[i] || (abs(col-placed[i])==abs(i-row))){
            return false;
        }
    }
    return true;
}
void f1(vector<string> &temp,int row,vector<int>&placed,vector<vector<string>>&ans){
    if(row>=placed.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<placed.size();i++){
        if(can_we(row,i,placed)){
            placed[row]=i;
            temp[row][i]='Q';
            f1(temp,row+1,placed,ans);
            temp[row][i]='.';
            placed[row]=-100;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> temp(n, string(n, '.'));
        vector<int>placed(n,-100);
        f1(temp,0,placed,ans);
        return ans;
    }
};