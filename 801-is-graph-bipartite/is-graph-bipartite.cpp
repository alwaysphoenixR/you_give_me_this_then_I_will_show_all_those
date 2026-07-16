class Solution {
public:
bool calc(int node ,int color,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=color;
    bool ans=1;
    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            ans=ans && calc(nbr,color^1^2,adj,vis);
            if(!ans)return false;
        }
    }
    for(auto nbr:adj[node]){
        if(vis[nbr]==vis[node])return false;
    }
    return ans;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        bool ans=1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans=ans && calc(i,1,graph,vis);
            }
        }
        return ans;
    }
};