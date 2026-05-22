class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long  sum=0;
        long long  ts=0;
        for(int i=0;i<nums.size();i++){
            ts+=nums[i];
        }
        long long  rem1=abs(ts)%p;
        if(ts<0){
            rem1=(p-rem1)%p;
        }
        if(rem1==0)return 0;
        unordered_map<int,int>m1;
        m1[0] = -1;
        long long  ans=n;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            long long x=abs(sum-ts)%p;
            if(sum-ts<0){
                x=(p-x)%p;
            }
            long long temp=sum;
            temp=abs(temp)%p;
            if(sum<0){
                temp=(p-temp)%p;
            }
            m1[temp]=i;
            if(m1.find(x)!=m1.end()){
                ans=min(1ll*ans,1ll*(i-m1[x]));
            }
           
        }
        if(ans==n)return -1;
        return ans;
    }
};