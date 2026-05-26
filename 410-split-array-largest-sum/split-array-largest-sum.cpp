class Solution {
public:
bool can_we(vector<int>&nums,int k,int mid){
    int cnt=0;
    int run_sum=0;
    if(nums[0]>mid)return false;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid)return false;
        if(run_sum+nums[i]>mid){
            cnt++;
            run_sum=0;
            
        }
        run_sum+=nums[i];
    }
    cout<<cnt<<endl;
    if(cnt<=k-1)return true;
    return false;
}
    int splitArray(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int s=0;
        int e=sum;
        int ans=e;
        while(s<=e){
            int mid=(e-s)/2+s;
            if(can_we(nums,k,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};