class Solution {
public:
static bool cmp(vector<int>&a,vector<int>&b){
     if(a[0]==b[0]){
        return a[1]>b[1];
    }
    return a[0]<b[0];
   
}
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        vector<vector<int>>temp;
        temp.push_back({nums[0][0],nums[0][1]});
        for(int i=1;i<nums.size();i++){
            vector<int>prev=temp.back();
            int L=prev[0];
            int R=prev[1];
            int c_L=nums[i][0];
            int c_R=nums[i][1];
            cout<<L<<" "<<R<<" "<<c_L<<" "<<c_R<<endl;
            if(L<=c_L && c_R<=R){continue;}
            else{
                temp.push_back({c_L,c_R});
            }

        }
        return temp.size();
    }
};