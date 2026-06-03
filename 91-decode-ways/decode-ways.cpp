class Solution {
public:
int  f1(string &s,int i,set<string>&st,vector<int>&dp){
    if(i>=s.size()){
        // ans++;
        return 1;
    }
    if(dp[i]!=-1)return dp[i];
    int ans=0;
    for(int j=i;j<s.size();j++){
        string x=s.substr(i,j-i+1);
        // int num=stoi(x);
        if(st.count(x)){
            ans+=f1(s,j+1,st,dp);
        }
    }
    // if(ans!=INT_MIN)ans++;
    return dp[i]=ans;
}
    int numDecodings(string s) {
       set<string> st = {
    "1","2","3","4","5","6","7","8","9","10",
    "11","12","13","14","15","16","17","18","19","20",
    "21","22","23","24","25","26"};

// vector<int>dp(s.size(),-1);
vector<int>dp(s.size(),-1);
        // int ans=0;
        int i=0;
        int ans= f1(s,i,st,dp);
        // if(ans==INT_MIN) return 0;
        return ans;
    }
};