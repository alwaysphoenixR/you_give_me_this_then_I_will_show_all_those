class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int less_cnt=0;
        int piv_cnt=0;
        int more_cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                less_cnt++;
            }else if (nums[i]==pivot){
                piv_cnt++;
            }else{
                more_cnt++;
            }
        }
        int i=less_cnt;
        while(piv_cnt){
            // cout<<pivot<<endl;
            ans[i++]=pivot;
            piv_cnt--;
        }
        int j=less_cnt;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==pivot)continue;
            else if(nums[i]<pivot){
                ans[j-less_cnt]=nums[i];
                less_cnt--;
            }else{
                ans[n-more_cnt]=nums[i];
                more_cnt--;
            }
        }
        return ans;
        
    }
};