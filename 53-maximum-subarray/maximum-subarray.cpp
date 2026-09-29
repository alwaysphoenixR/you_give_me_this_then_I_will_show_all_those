class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            ans=max(ans,curr_sum);
            if(curr_sum<0){
                curr_sum=0;
            }
        }
        // for full negative
        int tsum=accumulate(nums.begin(),nums.end(),0);
        ans=max(ans,tsum);
        return ans;
        
    }
};