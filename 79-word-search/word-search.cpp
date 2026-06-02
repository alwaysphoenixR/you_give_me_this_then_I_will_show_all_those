class Solution {
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
public:
bool f1(vector<vector<char>>& board,string &word,int x,int y,int k,vector<vector<int>>&vis){
    int n=board.size();
    int m=board[0].size();
    if(k>=word.size())return true;
    if(board[x][y]!=word[k])return false;
    vis[x][y]=1;
    bool ans=false;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if((nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]) || k==word.size()-1){
            ans=ans||(f1(board,word,nx,ny,k+1,vis));
        }
    }
    vis[x][y]=0;
    return ans;
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        // int k=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int k=0;
                // cout<<i<<" "<<j<<" "<<k<<" "<<endl;
                if(board[i][j]==word[k]){
                    bool ans=f1(board,word,i,j,k,vis);
                    if(ans)return true;
                }
            }
        }
        return false;
        
    }
};