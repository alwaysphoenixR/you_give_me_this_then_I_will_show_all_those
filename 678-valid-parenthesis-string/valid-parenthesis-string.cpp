class Solution {
public:
bool f1(string &s,int i,int cnt,vector<vector<int>>&dp){
    if(i>=s.size() && cnt==0){
        return true;
    }
    if(i>=s.size() && cnt!=0){
        return false;
    }
    if(cnt<0){
        return  false;
    }
    if(dp[i][cnt]!=-1)return dp[i][cnt];
    
    if(s[i]=='('){
        return dp[i][cnt]=f1(s,i+1,cnt+1,dp);
    }
    else if(s[i]==')'){
        return dp[i][cnt]=f1(s,i+1,cnt-1,dp);
    }else{
        return dp[i][cnt]=((f1(s,i+1,cnt,dp)) || (f1(s,i+1,cnt+1,dp)) || (f1(s,i+1,cnt-1,dp)));
    }
}
    bool checkValidString(string s) {
        int n=s.size();
        int i=0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        bool ans=f1(s,i,0,dp);
        return ans;
    }
};