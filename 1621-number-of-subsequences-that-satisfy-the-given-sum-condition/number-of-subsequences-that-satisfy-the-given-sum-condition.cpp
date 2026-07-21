class Solution {
public:
int can_we(vector<int>&nums,int s,int t){
    int st=s;
    int e=nums.size()-1;
    int ans=-1;
    while(st<=e){
        int mid=(e-st)/2+st;
        if(nums[mid]<=t){
            ans=mid;
            st=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;
}
int poww(int x,int p,int M){
    // cout<<x<<" "<<p<<endl;
    if(p==0)return 1;
    if(p%2==0){
        return poww((1LL*x*x)%M,p/2,M);
    }else{
return ((poww((1LL*x * x) % M, p / 2, M) % M) * 1LL*x % M) % M;    }
}
    int numSubseq(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
         int  M=1000000007;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>t)break;
            int j=can_we(nums,i,t-nums[i]);
            int cnt=j-i+1;
            if(j==-1)cnt=0;
            
            // cout<<cnt<<endl;
            if (cnt != 0) {
    ans = (ans + poww(2, cnt - 1, M)) % M;
}
            // cout<<ans<<endl;
        }
        return ans;
    }
};