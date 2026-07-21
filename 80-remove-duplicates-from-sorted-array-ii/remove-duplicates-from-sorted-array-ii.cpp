class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int non_valid=-1;
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                cnt=0;
                continue;
            }else{
                cnt++;
                if(cnt==2){
                    non_valid=i;
                    break;
                }
            }
        }
        cnt=0;
        if(non_valid==-1)return nums.size();
        int valid=non_valid;
        while(valid<nums.size()){
            if(nums[valid]==nums[valid-1]){
                valid++;
            }else{
                break;
            }
        }
        //    cout<<valid<< " "<<non_valid<<endl;
        while(non_valid<nums.size() && valid <nums.size()){
             if(nums[valid]!=nums[non_valid-1])cnt=0;
            cout<<nums[valid]<<" "<<nums[non_valid-1]<<" "<<cnt<<endl;
         if(nums[valid]!=nums[non_valid-1] || (nums[valid]==nums[non_valid-1] && cnt <2)){
            swap(nums[valid],nums[non_valid]);
            valid++;
            non_valid++;
            cnt++;
         }else{
            int curr=nums[valid];
            while(valid<nums.size() && nums[valid]==curr){
                valid++;
            }
         }
        
        }
        // for(auto i:nums){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // cout<<valid<< " "<<non_valid<<endl;
        return non_valid;
    }
};