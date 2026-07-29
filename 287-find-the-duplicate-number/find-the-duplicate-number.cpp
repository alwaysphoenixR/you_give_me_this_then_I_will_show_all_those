class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // cyclic sort 
        int i=0;
        
        while(i<nums.size()){
             if(nums[i]==i+1)i++;
              else {
               int v1=nums[i];
               int v2=nums[nums[i]-1];
               if(v1==v2)return nums[i];
               else swap(nums[i],nums[nums[i]-1]);

            }
        }
        return -1;
        
    }
};