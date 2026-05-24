class Solution {
public:
bool can_we(vector<int>&nums,int mid,int p){
    int n=nums.size();

    int cnt=0;
    int i=0;
    // int j=nums.size()-1;
   for(int i=0;i<n-1;i++){
    int diff=abs(nums[i]-nums[i+1]);
    if(diff<=mid){
        cnt++;
        i++;
    }
   }
   if(cnt>=p)return true;
   return false;
}
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0)return 0;
        sort(nums.begin(),nums.end());
        int s=0;
        int e=abs(*max_element(nums.begin(),nums.end())-(*min_element(nums.begin(),nums.end())));
        int ans=e;
        while(s<=e){
            int mid=(e-s)/2+s;
            if(can_we(nums,mid,p)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;

        
    }
};