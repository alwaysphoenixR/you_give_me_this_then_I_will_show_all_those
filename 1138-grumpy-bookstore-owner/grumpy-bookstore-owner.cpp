class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& grumpy, int M) {
    int ts=0;
    for(int i=0;i<nums.size();i++){
        if(!grumpy[i]){
            ts+=nums[i];
        }
    }
        //maintain  a window of size M minutes
        int ans=ts;
        int sum=0;
        int real_sum=0;
        int diff=0;
        for(int i=0;i<M;i++){
            sum+=nums[i];
            if(!grumpy[i]){
                real_sum+=nums[i];
            }
            diff=sum-real_sum;
            ans=max(ans,ts+diff);
        }
        for(int i=M;i<nums.size();i++){
            int old_min=i-M;
            sum+=nums[i];
            sum-=nums[old_min];
            if(!grumpy[i]){
                real_sum+=nums[i];
            }
            if(!grumpy[old_min]){
                real_sum-=nums[old_min];
            }
            diff=sum-real_sum;
            ans=max(ans,ts+diff);
        }
        return ans;
    }
};