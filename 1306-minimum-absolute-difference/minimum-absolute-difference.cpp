class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int minii=INT_MAX;
        for(int i=0;i<n-1;i++){
            minii=min(minii,abs(nums[i]-nums[i+1]));
        }
          for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])==minii){
                vector<int>a={nums[i],nums[i+1]};
                ans.push_back(a);
            }
        }
        return ans;
    }
};