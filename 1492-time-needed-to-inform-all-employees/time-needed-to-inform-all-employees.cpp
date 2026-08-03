class Solution {
public:
int dfs(int node,vector<vector<int>>&adj,vector<int>&dp,vector<int>&time){
    int ans=0;
    for(auto nbr:adj[node]){
        int val=time[node]+dfs(nbr,adj,dp,time);
        ans=max(ans,val);
    }
    return ans;
}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& time) {
        vector<vector<int>>adj(n);
        int root=headID;
        for(int i=0;i<manager.size();i++){
            int v=i;
            int u=manager[i];
            if(u==-1)continue;
            adj[u].push_back(v);
        }
        vector<int>dp(n,0);
    int ans=dfs(root,adj,dp,time);
    return ans;
    }
};