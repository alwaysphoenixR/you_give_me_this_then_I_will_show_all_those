class Solution {
public:
bool f1(int start,set<string>&s1,string &s,vector<int>&dp){
    if(start>=s.size())return 1;
    if(dp[start]!=-1)return dp[start];
    for(int i=start;i<s.size();i++){
        if(s1.count(s.substr(start,i-start+1)) && f1(i+1,s1,s,dp)){
            return dp[start]=1;
        }
    }
    return dp[start]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        set<string>s1(wordDict.begin(),wordDict.end());
        return f1(0,s1,s,dp);
    }
};