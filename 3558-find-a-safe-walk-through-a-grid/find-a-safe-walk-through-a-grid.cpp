class Solution {
public:
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool safe(int x,int y,int n,int m){
    return (x>=0 && x<n && y>=0 && y<m);
}
// bool dfs(int x,int y,int h,vector<vector<int>>&nums,vector<vector<int>>&vis){
//     int n=nums.size();
//     int m=nums[0].size();
//     if(h<=0)return false;
//     if(x==n-1 && y==m-1){
//         if(h>=1)return true;
//         return false;
//     }
//     vis[x][y]=1;
//     bool ans=0;
//     for(int i=0;i<4;i++){
//         int nx=x+dx[i];
//         int ny=y+dy[i];
//         if(safe(nx,ny,vis,n,m)){
//             if(nums[nx][ny]==1){
//                 ans|=dfs(nx,ny,h-1,nums,vis);
//                 if(ans)return ans;
//             }else{
//                 ans|=dfs(nx,ny,h,nums,vis);
//                 if(ans)return ans;
//             }
//         }
       
//     }
//     vis[x][y]=0;
//     return ans;
// }
    bool findSafeWalk(vector<vector<int>>& grid, int h) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
                deque<pair<int,int>>pq;

        if(grid[0][0]){
            pq.push_back({0,0});
            dist[0][0]=1;
        }else{
            pq.push_back({0,0});
            dist[0][0]=0;
        }
        while(!pq.empty()){
            auto [x,y]=pq.front();
            pq.pop_front();
            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=y+dy[i];
                if(safe(nx,ny,n,m)){
                    if(grid[nx][ny]){
                        if(dist[nx][ny]>dist[x][y]+1){
                            dist[nx][ny]=dist[x][y]+1;
                            pq.push_back({nx,ny});
                        }
                    }else{
                        if(dist[nx][ny]>dist[x][y]){
                            dist[nx][ny]=dist[x][y];
                            pq.push_front({nx,ny});
                        }
                    }
                }
            }
           
        }
        cout<<dist[n-1][m-1]<<endl;
        if(dist[n-1][m-1]<=h-1)return true;
        //  if(dist[n-1][m-1]>1+h)return false;
            return false;
    }
};