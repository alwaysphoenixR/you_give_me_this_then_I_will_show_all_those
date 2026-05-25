class Solution {
public:
bool can_we(vector<int>&nums,int mid,int n){
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<nums.size();i++){
        cnt1+=(nums[i]/mid);
        if(nums[i]%mid)cnt2++;
    }
    int new_n=n-cnt1;
    if(new_n>=cnt2)return true;
    return false;
}
    int minimizedMaximum(int n, vector<int>& nums) {
        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        int ans=e;
        while(s<=e){
            int mid=(e-s)/2+s;
            if(can_we(nums,mid,n)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};