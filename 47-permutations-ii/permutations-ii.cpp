class Solution {
public:
void f1(vector<vector<int>>&ans,int i,vector<int>&nums,set<vector<int>>&s1){
    if(i==nums.size()){
        if(s1.count(nums))return;
        s1.insert(nums);
        ans.push_back(nums);
        return ;
    }
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        f1(ans,i+1,nums,s1);
        swap(nums[i],nums[j]); 
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>>ans;
         set<vector<int>>s1;
        //  map<pair<int,int>,int>m1;
        f1(ans,0,nums,s1);
        return ans;
    }
};