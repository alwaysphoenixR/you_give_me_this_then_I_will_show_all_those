class Solution {
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};

public:
void f1(vector<vector<int>>&nums,int x,int y,vector<vector<int>>&vis,int &cnt,int total,int &ans){
    int n=nums.size();
    int m=nums[0].size();

    if(nums[x][y]==2 && cnt==total-1){
        ans++;
        return;
    }
    cnt++;
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && nums[nx][ny]!=-1){
            f1(nums,nx,ny,vis,cnt,total,ans);
        }
    }
    vis[x][y]=0;
    cnt--;
}
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x=-1;
        int y=-1;
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1)cnt++;
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        int total=m*n;
        int rem=total-cnt;
        int ans=0;
        vector<vector<int>>vis(n,(vector<int>(m,0)));
        int c=0;
        f1(grid,x,y,vis,c,rem,ans);
        return ans;
    }
};