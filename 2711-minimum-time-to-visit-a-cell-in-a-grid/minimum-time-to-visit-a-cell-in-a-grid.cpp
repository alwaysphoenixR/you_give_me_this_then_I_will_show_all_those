class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int N=grid.size();
    int M=grid[0].size();
  if(grid[0][0] != 0) return -1;

if(N == 1 && M == 1) return 0;

if(N == 1) {
    if(grid[0][1] > 1) return -1;
}
else if(M == 1) {
    if(grid[1][0] > 1) return -1;
}
else {
    if(grid[0][1] > 1 && grid[1][0] > 1)
        return -1;
}
    // int curr_time=0;
    vector<vector<int>>dist(N,vector<int>(M,INT_MAX));
    priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>
> pq;
    // priority_queue<pair<pair<int,int>,int>>pq;
   pq.push({0, {0, 0}});
    dist[0][0]=0;
    while(!pq.empty()){
    auto [wt, pos] = pq.top();
    auto [x, y] = pos;
    pq.pop();

    if(wt != dist[x][y]) continue;

    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0 && nx<N && ny>=0 && ny<M){

            int extra;

            if(grid[nx][ny] <= wt){
                extra = wt + 1;
            }
            else{
                extra = grid[nx][ny];

                if(extra % 2 == wt % 2)
                    extra++;
            }

            if(dist[nx][ny] > extra){
                dist[nx][ny] = extra;
                pq.push({extra,{nx,ny}});
            }
        }
    }
}
    return dist[N-1][M-1];
    }
};