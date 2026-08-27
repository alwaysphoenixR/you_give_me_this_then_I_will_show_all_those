class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m1;
        int K=k+1;
        bool ans=0;
        for(int i=0;i<min(K,(int)nums.size());i++){
            m1[nums[i]]++;
            if(m1[nums[i]]>1)ans=1;
        }
        if(ans)return true;
        for(int i=K;i<nums.size();i++){
            int add_idx=i;
            int rem_idx=i-K;
            m1[nums[rem_idx]]--;
            m1[nums[add_idx]]++;
            if(m1[nums[add_idx]]>1)ans=1;
            if(ans)return true;
        }
        return false;
        
    }
};