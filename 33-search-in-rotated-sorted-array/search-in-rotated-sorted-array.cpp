class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int ans=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[0]){
                s=mid+1;
            }else{
                ans=mid;
                e=mid-1;
            }
        }
        cout<<ans<<endl;
        //ans is the pivot index run 2 binary search 
        int s1=0;
        int e1=ans-1;
       
        while(s1<=e1){
             int mid=s1+(e1-s1)/2;
           if(nums[mid]==target){
            return mid;
           }
           else if(nums[mid]>target){
            e1=mid-1;
           }else{
            s1=mid+1;
           }
        }
        int s2=ans;
        int e2=nums.size()-1;
        while(s2<=e2){
             int mid=s2+(e2-s2)/2;
           if(nums[mid]==target){
            return mid;
           }
           else if(nums[mid]>target){
            e2=mid-1;
           }else{
            s2=mid+1;
           }
        }
        return -1;
    }
};