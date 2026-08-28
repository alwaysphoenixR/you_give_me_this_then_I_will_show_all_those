class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int>nums;
        for(int i=0;i<colors.size();i++){
            nums.push_back(colors[i]);
        }
        for(int i=0;i<k-1;i++){
            nums.push_back(colors[i]);
        }
        int i=0;
        int j=1;
        int ans=0;
        while(i<nums.size() && j<nums.size()){
            if(nums[j]==nums[j-1]){
                ans=ans+max(0,j-i-k+1);
                i=j;
            }
            j++;
        }
        ans=ans+max(0,j-i-k+1);
        return ans;
    }
};