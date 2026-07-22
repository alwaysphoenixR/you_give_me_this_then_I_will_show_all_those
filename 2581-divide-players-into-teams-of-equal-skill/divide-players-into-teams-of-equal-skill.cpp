class Solution {
public:
    long long dividePlayers(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());
        int t=nums[0]+nums[n-1];
        while(i<j){
            if(nums[i]+nums[j]==t){
                ans=ans+1LL*nums[i]*nums[j];
                i++;
                j--;
            }else{
                return -1;
            }
        }
        return ans;
        
    }
};