class Solution {
public:
static bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        vector<pair<int,int>>nums(n);
        for(int i=0;i<nums.size();i++){
            int u=envelopes[i][0];
            int v=envelopes[i][1];
            pair<int,int>p1;
            p1.first=u;
            p1.second=v;
            nums[i]=p1;
        }
        sort(nums.begin(),nums.end(),cmp);
        vector<int>lis;
        for(int i=0;i<nums.size();i++){
            if(lis.empty()|| lis.back()<nums[i].second){
                lis.push_back(nums[i].second);
            }
            else{
                auto it=lower_bound(lis.begin(),lis.end(),nums[i].second);
                *it=nums[i].second;
                // lis[it]=nums[i].second;
            }
        }
        return lis.size();
    }
};