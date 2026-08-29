class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int curr=0;
        int i=0;
        int j=0;
        while(j<n){
            curr+=nums[j];
            while(curr>=target){
                ans=min(ans,j-i+1);
                curr-=nums[i];
                i++;
            }
            j++;
        }
        if(ans==INT_MAX)return 0;
        return ans;
        
    }
};