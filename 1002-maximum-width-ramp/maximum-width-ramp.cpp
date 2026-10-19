class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int minii;
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            int val=nums[i];
            int idx=i;
            temp[i]=make_pair(val,idx);
        }
        sort(temp.begin(),temp.end());
        minii=temp[0].second;
        for(int i=1;i<n;i++){
            ans=max(ans,temp[i].second-minii);
            minii=min(minii,temp[i].second);
        }
        return ans;
    }
};