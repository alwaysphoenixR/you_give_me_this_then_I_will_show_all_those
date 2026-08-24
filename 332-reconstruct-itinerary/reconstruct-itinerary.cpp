class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj, vector<int>& ans){
        while(!adj[node].empty()){
            int nbr = adj[node].back();
            adj[node].pop_back();
            dfs(nbr, adj, ans);
        }
        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int unique_dest = 0;
        unordered_map<string,int> m1;

        for(int i = 0; i < tickets.size(); i++){
            string u = tickets[i][0];
            string v = tickets[i][1];

            if(!m1.count(u))
                m1[u] = unique_dest++;

            if(!m1.count(v))
                m1[v] = unique_dest++;
        }

        vector<string> mappings(unique_dest);

        for(auto [key, val] : m1)
            mappings[val] = key;

        vector<vector<int>> adj(unique_dest);

        for(int i = 0; i < tickets.size(); i++){
            int u = m1[tickets[i][0]];
            int v = m1[tickets[i][1]];

            adj[u].push_back(v);
        }

        for(int i = 0; i < adj.size(); i++){
            sort(adj[i].begin(), adj[i].end(), [&](int a, int b){
                return mappings[a] > mappings[b];
            });
        }

        vector<int> ans;

        dfs(m1["JFK"], adj, ans);

        reverse(ans.begin(), ans.end());

        vector<string> fans;

        for(int x : ans)
            fans.push_back(mappings[x]);

        return fans;
    }
};