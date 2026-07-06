class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        vector<int>in_deg(n+1,0);
        for(int i=0;i<relations.size();i++){
            int u=relations[i][0];
            int v=relations[i][1];
            adj[u].push_back(v);
            in_deg[v]++;
        } 
        vector<int>dp(n+1,0);
         queue<int>q;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(in_deg[i]==0){
                q.push(i);
                dp[i]=time[i-1];
                cout<<i<<" "<<dp[i]<<endl;
            }
        }
       int prev=-1;
        while(!q.empty()){
            auto tp=q.front();
            prev=tp;
            q.pop();

            for(auto nbr:adj[tp]){
                dp[nbr]=max(dp[nbr],dp[tp]);
                cout<<dp[nbr]<<" ";
                in_deg[nbr]--;
                if(in_deg[nbr]==0){
                    // cout<<"Q "<<dp[nbr]<<endl;
                    dp[nbr]+=time[nbr-1];
                                        cout<<"Q "<<dp[nbr]<<endl;

                    q.push(nbr);
                }
            }
        }
     ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        return ans; 
    }
};