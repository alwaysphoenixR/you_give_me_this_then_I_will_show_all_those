class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        auto it=lower_bound(nums.begin(),nums.end(),target);
        int s_idx=it-nums.begin();
        auto it2=upper_bound(nums.begin(),nums.end(),target);
        int e_idx=it2-nums.begin();
        vector<int>ans;
        for(int i=s_idx;i<e_idx;i++){
            ans.push_back(i);
        }
        return ans;
    }
};