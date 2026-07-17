class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int sum=0;
        vector<int>dp(n,0);
        for(int i=0;i<nums.size();i++){
            if(i>0){
                dp[i]=nums[i]+max(0,dp[i-1]);
            }else{
                dp[i]=nums[i];
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};