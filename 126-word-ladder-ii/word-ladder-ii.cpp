class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& ans,
             vector<int>& path,
             vector<vector<int>>& adj,
             vector<int>& dist,
             vector<int>& rdist,
             int ss,
             int dest) {

        path.push_back(node);

  
        if (dist[node] + rdist[node] == ss) {

           
            if (node == dest) {
                ans.push_back(path);

                path.pop_back();
                return;
            }

          
            for (auto nbr : adj[node]) {

                if (dist[nbr] == dist[node] + 1 &&
                    dist[nbr] + rdist[nbr] == ss) {

                    dfs(nbr, ans, path, adj,
                        dist, rdist, ss, dest);
                }
            }
        }

        path.pop_back();
    }


    bool can_we(int a, int b, vector<string>& mappings) {

        string x = mappings[a];
        string y = mappings[b];

        if (x.size() != y.size())
            return false;

        int cnt = 0;

        for (int i = 0; i < (int)x.size(); i++) {

            if (x[i] != y[i])
                cnt++;
        }

        return cnt == 1;
    }


    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        int cnt = 0;

        unordered_map<string, int> m1;

      
        m1[beginWord] = cnt++;

        bool is_there = false;

       
        for (int i = 0; i < (int)wordList.size(); i++) {

            if (wordList[i] == endWord)
                is_there = true;

            if (!m1.count(wordList[i])) {
                m1[wordList[i]] = cnt++;
            }
        }
       
      
        if (!is_there)
            return {};


      
        vector<string> mappings(cnt);

        for (auto [key, val] : m1) {
            // cout<<key<<" "<<val;
            mappings[val] = key;
        }
        // cout<<endl;


        vector<vector<int>> adj(cnt);


      
        for (int i = 0; i < (int)wordList.size(); i++) {

            if (can_we(m1[beginWord],
                       m1[wordList[i]],
                       mappings)) {

                int u = m1[beginWord];
                int v = m1[wordList[i]];
                if(u!=v){
                adj[u].push_back(v);
                adj[v].push_back(u);
                }
              
            }
        }
      

      
        for (int i = 0; i < (int)wordList.size(); i++) {
            if(wordList[i]==beginWord)continue;

            for (int j = i + 1;
                 j < (int)wordList.size();
                 j++) {
                    if(wordList[j]==beginWord)continue;
                int u = m1[wordList[i]];
                int v = m1[wordList[j]];

                if (can_we(u, v, mappings)) {

                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
          for(int i=0;i<adj.size();i++){
            cout<<i<<"--->"<<" ";
            for(int j=0;j<adj[i].size();j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }


        
        int src = m1[beginWord];
        int dest = m1[endWord];



        vector<int> dist(cnt, INT_MAX);

        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {

            int tp = q.front();
            q.pop();

            for (auto nbr : adj[tp]) {

                if (dist[nbr] > dist[tp] + 1) {

                    dist[nbr] = dist[tp] + 1;
                    q.push(nbr);
                }
            }
        }


       
        if (dist[dest] == INT_MAX)
            return {};


       

        vector<int> rdist(cnt, INT_MAX);

        rdist[dest] = 0;

        q.push(dest);

        while (!q.empty()) {

            int tp = q.front();
            q.pop();

            for (auto nbr : adj[tp]) {

                if (rdist[nbr] > rdist[tp] + 1) {

                    rdist[nbr] = rdist[tp] + 1;
                    q.push(nbr);
                }
            }
        }


        
        int ss = dist[dest];


   

        vector<vector<int>> paths;
        vector<int> path;

        dfs(src,
            paths,
            path,
            adj,
            dist,
            rdist,
            ss,
            dest);


    

        vector<vector<string>> ans;

        for (auto& p : paths) {

            vector<string> temp;

            for (auto node : p) {
                temp.push_back(mappings[node]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};