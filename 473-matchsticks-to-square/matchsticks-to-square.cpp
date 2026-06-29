class Solution {
public:
bool f1(vector<int>&grps,vector<int>&nums,int i,int &sum1,int &sum2,int &sum3,int &sum4,int &t,int &side){
    if(sum1>side || sum2>side|| sum3>side || sum4>side)return false;
    if(i>=nums.size()){
        if(sum1==sum2 && sum2==sum3 && sum3==sum4 && (sum1+sum2+sum3+sum4==t)){
            return true;
        }else{
            return false;
        }
    }
    bool ans=false;
    for(int j=0;j<4;j++){
        if(grps[i]==-1){
            if(j==0){
                sum1+=nums[i];
                grps[i]=j;
                ans=ans||f1(grps,nums,i+1,sum1,sum2,sum3,sum4,t,side);
                sum1-=nums[i];
                grps[i]=-1;
            }else if(j==1){
                 sum2+=nums[i];
                grps[i]=j;
                ans=ans||f1(grps,nums,i+1,sum1,sum2,sum3,sum4,t,side);
                sum2-=nums[i];
                grps[i]=-1;
            }else if(j==2){
                 sum3+=nums[i];
                grps[i]=j;
                ans=ans||f1(grps,nums,i+1,sum1,sum2,sum3,sum4,t,side);
                sum3-=nums[i];
                grps[i]=-1;
            }else{
                 sum4+=nums[i];
                grps[i]=j;
                ans=ans||f1(grps,nums,i+1,sum1,sum2,sum3,sum4,t,side);
                sum4-=nums[i];
                grps[i]=-1;
            }
        }
    }
    return ans;
}
    bool makesquare(vector<int>& nums) {
        int t=accumulate(nums.begin(),nums.end(),0);
        sort(nums.rbegin(),nums.rend());
        if(t%4!=0)return false;
        int side=t/4;
        vector<int>grps(nums.size(),-1);
        int sumA=0;
        int sumB=0;
        int sumC=0;
        int sumD=0;
        bool ans= f1(grps,nums,0,sumA,sumB,sumC,sumD,t,side);
        return ans;
    }
};