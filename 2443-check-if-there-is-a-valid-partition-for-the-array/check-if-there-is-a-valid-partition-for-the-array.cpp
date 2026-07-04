class Solution {
public:
bool f1(vector<int>&nums,int st,vector<int>&dp){
    if(st>=nums.size()){
        return true;
    }
    if(dp[st]!=-1)return dp[st];
    bool ans=0;
    for(int j=st;j<min(st + 3, (int)nums.size());j++){
       if ((j-st+1 == 2 && nums[j] == nums[j-1]) ||
    (j-st+1 == 3 && nums[j] == nums[j-1] &&
     nums[j-1] == nums[j-2]) ||
    (j-st+1 == 3 &&
     nums[j] == nums[j-1] + 1 &&
     nums[j-1] == nums[j-2] + 1)){
            ans=ans|f1(nums,j+1,dp);
        }
    }
    return dp[st]=ans;
}
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f1(nums,0,dp);
        
    }
};