class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int curr=0;
        int ts=accumulate(nums.begin(),nums.end(),0);
        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=abs(curr-(ts-(curr+nums[i])));
            curr+=nums[i];
        }
        return ans;
        
    }
};