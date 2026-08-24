class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool dfs(int x,int y,vector<vector<int>>&vis,int limit,vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    if(x==n-1 && y==m-1)return 1;
    vis[x][y]=1;
    bool yes=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]<=limit){
            yes=yes||dfs(nx,ny,vis,limit,grid);
        }
    }
    return yes;
}
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int s=0;
        int e=INT_MIN;
        
        for(auto row:grid){
            e=max(e,*max_element(row.begin(),row.end()));
        }
        int ans=e;
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(s<=e){
            int mid=(e-s)/2+s;
            for(auto &row : vis)
    fill(row.begin(), row.end(), 0);
            if(grid[0][0]<=mid && dfs(0,0,vis,mid,grid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};