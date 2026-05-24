class Solution {
public:
bool can_give(vector<int>&nums,int mid,long long k){
    if(mid==0)return 1;
    long long  cnt=0;
    for(int i=0;i<nums.size();i++){
        cnt+=(nums[i]*1ll/mid);
    }
    return (cnt>=k);
}
    int maximumCandies(vector<int>& candies, long long k) {
        int s=0;
        int e=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(s<=e){
            int mid=(e-s)/2+s;
            if(can_give(candies,mid,k)){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
};