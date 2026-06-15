class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        // if(n==1)return true;
        int maxii=0;
        for(int i=0;i<nums.size();i++){
           if(i<=maxii){
            maxii=max(maxii,i+nums[i]);
           }
        }
        if(maxii>=n-1){
            return true;
        }
        return false;
        
    }
};