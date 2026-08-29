class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long  dc=0;
        long long  ans=INT_MIN;
        long long  curr=0;
        vector<int>freq(1e5+1,0);
        for(int i=0;i<k;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==1){
                dc++;
            }
            curr+=nums[i];
        }
        if(dc==k)
        ans=max(ans,curr);
        for(int i=k;i<nums.size();i++){
            freq[nums[i-k]]--;
            if(freq[nums[i-k]]==0)dc--;
            curr-=nums[i-k];
            curr+=nums[i];
            freq[nums[i]]++;
            if(freq[nums[i]]==1)dc++;
            if(dc==k)ans=max(ans,curr);
        }
        if(ans==INT_MIN)return 0;
        return ans;
    }
};