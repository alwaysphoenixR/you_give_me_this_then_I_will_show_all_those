class Solution {
public:
int fin(vector<int>&nums,int s,int ele){
    int start=s;
    int e=nums.size()-1;
    int ans=start;
    while(start<=e){
        int mid=(start+e)/2;
        if(nums[mid]>ele){
            e=mid-1;
        }else{
            ans=mid;
            start=mid+1;
        }
    }
    return ans;
}
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int diff, vector<vector<int>>& queries) {
        vector<int>dp(n,-1);
        for(int i=0;i<nums.size();i++){
            int max_reach=fin(nums,i,nums[i]+diff);
            dp[i]=max_reach;
        }
        for(auto i:dp){
            cout<<dp[i]<<" ";
        }
        for(int i=n-2;i>=0;i--){
            dp[i]=dp[dp[i]];
        }

        vector<bool>fans;
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(u==v){fans.push_back(true);continue;}
            if(u>v){
                swap(u,v);
            }
            if(dp[u]>=v){
                fans.push_back(true);
            }else{
                fans.push_back(false);
            }
        }
        return fans;
        
    }
};