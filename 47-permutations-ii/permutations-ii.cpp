class Solution {
public:
void dfs(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,unordered_map<int,int>&m1){
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
    }
    for(auto [key,val]:m1){
        if(val!=0){
            temp.push_back(key);
            m1[key]--;
            dfs(ans,temp,nums,m1);
            temp.pop_back();
            m1[key]++;
        }
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int>m1;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
        }
        vector<vector<int>>ans;
        vector<int>temp;
        dfs(ans,temp,nums,m1);
        return ans;
    }
};