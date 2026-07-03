class Solution {
public:
int f1(vector<int>&nums,int i,map<int,int>&m1,vector<int>&dp){
    if(i>=nums.size())return 0;
    if(dp[i]!=-1)return dp[i];
    int ans1=f1(nums,i+1,m1,dp);
    int ans2=0;
    if(i<nums.size()-1 && nums[i+1]!=nums[i]+1){
        ans2=f1(nums,i+1,m1,dp)+m1[nums[i]]*nums[i];
    }else{
        ans2=f1(nums,i+2,m1,dp)+m1[nums[i]]*nums[i];
    }
    return dp[i]=max(ans1,ans2);
}
    int deleteAndEarn(vector<int>& nums) {
        vector<int>dp;
        map<int,int>m1;
        vector<int>comp;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
        }
        for(auto it=m1.begin();it!=m1.end();it++){
            comp.push_back(it->first);
        }
        dp.resize(comp.size(),-1);
        return f1(comp,0,m1,dp);
    }
};