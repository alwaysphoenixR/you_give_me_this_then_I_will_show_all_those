class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long >>dist(26,vector<long long >(26,INT_MAX));
        for(long long  i=0;i<original.size();i++){
            long long  x=original[i]-'a';
            long long  y=changed[i]-'a';
            dist[x][y]=min(dist[x][y],1LL*cost[i]);
        }
        for(long long  i=0;i<26;i++){
            dist[i][i]=0;
        }
        // for(long long  i=0;i<26;i++){
        //     cout<<i<<"->";
        //     for(long long  j=0;j<26;j++){
        //         if(i==j)continue;
        //       cout << ((dist[i][j] != INT_MAX) ? to_string(dist[i][j]) : "INF") << " ";
        //     }
        //     cout<<endl;
        // }
        for(long long  k=0;k<26;k++){
            for(long long  i=0;i<26;i++){
                for(long long  j=0;j<26;j++){
                    dist[i][j]=min(1LL*dist[i][j],1LL*dist[i][k]+1LL*dist[k][j]);
                }
            }
        }
        long long  ans=0;
        for(long long  i=0;i<source.size();i++){
                long long  x=source[i]-'a';
                long long  y=target[i]-'a';
               if(dist[x][y]==INT_MAX)return -1;
               else ans+=dist[x][y];
        }
        return ans;
    }
};