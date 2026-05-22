class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,pair<int,int>>> vis(26, {0, {INT_MAX,INT_MIN}});
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            // int cnt=vis[x].first;
            int first_idx=vis[x].second.first;
            int last_idx=vis[x].second.second;
            if(i<first_idx){
                first_idx=i;
                 vis[x].second.first=first_idx;
            }
            if(i>last_idx){
                last_idx=i;
                 vis[x].second.second=last_idx;
            }
            // cnt+=1;
            // vis[x].first=cnt;
           
           
        }
        int ans=0;
        for(int i=0;i<26;i++){
            int f=vis[i].second.first;
            int l=vis[i].second.second;
            if(f==INT_MAX && l==INT_MIN)continue;
            set<int>s1;
            for(int j=f+1;j<l;j++){
                if(!s1.count(s[j]-'a')){
                    s1.insert(s[j]-'a');
                }
            }
            ans+=s1.size();
        }
        return ans;
    }
};