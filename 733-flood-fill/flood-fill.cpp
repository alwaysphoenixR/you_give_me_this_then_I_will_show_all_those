class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc])return image;
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        // vector<vector<int>>vis(n,vector<int>(m,0));
        int val=image[sr][sc];
        while(!q.empty()){
            auto [x,y]=q.front();
            image[x][y]=color;
            // vis[x][y]=1;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && image[nx][ny]==val){
                    q.push({nx,ny});
                }
            }

        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(vis[i][j]){
        //             image[i][j]=color;
        //         }
        //     }
        // }
        return image;
    }
};