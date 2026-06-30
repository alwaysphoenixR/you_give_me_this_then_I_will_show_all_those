class Solution {
public:
int f1(int i,vector<int>&nums,vector<int>&dp){
    if(i>=nums.size())return 0;
    if(dp[i]!=-1)return dp[i];
    return dp[i]=nums[i]+min(f1(i+1,nums,dp),f1(i+2,nums,dp));
}
    int minCostClimbingStairs(vector<int>& nums) {
       vector<int>dp(nums.size()+1,-1);
       int ans=f1(0,nums,dp);
       return min(dp[0],dp[1]);
    }
};