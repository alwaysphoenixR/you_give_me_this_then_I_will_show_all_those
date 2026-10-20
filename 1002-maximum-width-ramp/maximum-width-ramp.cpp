class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>suff_max(n,-1);
        suff_max[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff_max[i]=max(nums[i],suff_max[i+1]);
        }
        int ans=0;
        int l=0;
        int r=0;
        while(l<n && r<n){
            if(nums[l]<=suff_max[r]){
                ans=max(ans,r-l);
                r++;
            }else{
                l++;
            }
        }
        return ans;
    }
};