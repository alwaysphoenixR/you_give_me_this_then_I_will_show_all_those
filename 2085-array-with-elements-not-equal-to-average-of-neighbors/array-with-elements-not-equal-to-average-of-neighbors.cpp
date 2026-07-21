class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
       vector<int>ans(n);
       int a=0;
       int b=n-1;
       for(int i=0;i<n;i++){
        if(i%2==0){
            ans[i]=nums[a++];
        }else{
            ans[i]=nums[b--];
        }
       }
       if(n%2==0){
        swap(ans[n-2],ans[n-4]);
       }
       return ans;

        
    }
};