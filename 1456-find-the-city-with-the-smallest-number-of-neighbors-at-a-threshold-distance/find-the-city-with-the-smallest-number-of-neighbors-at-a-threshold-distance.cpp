class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
       for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int d=edges[i][2];
        dist[u][v]=d;
        dist[v][u]=d;
       }
       for(int i=0;i<n;i++){
        dist[i][i]=0;
       }
       for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(1LL*dist[i][j],1LL*dist[i][k]+1LL*dist[k][j]);
            }
        }
       }
    //    int min_cnt=0;
       vector<int>cnt(n,0);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(dist[i][j]<=t)cnt[i]++;
        }
       }
       for(int i=0;i<n;i++){
        cout<<i<<"-->";
        for(int j=0;j<n;j++){
            if(i==j)continue;
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
       }
       int min_cnt=INT_MAX;
       int ans=-1;
       for(int i=n-1;i>=0;i--){
        if(cnt[i]<min_cnt){
            min_cnt=cnt[i];
            ans=i;
        }
       }
       return ans;

    }
};