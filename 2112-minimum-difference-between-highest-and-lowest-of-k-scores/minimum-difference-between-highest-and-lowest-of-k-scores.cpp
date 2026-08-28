class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        ans=min(nums[k-1]-nums[0],ans);
        for(int i=k;i<nums.size();i++){
            ans=min(ans,nums[i]-nums[i-k+1]);
        }
        return ans;
        
    }
};