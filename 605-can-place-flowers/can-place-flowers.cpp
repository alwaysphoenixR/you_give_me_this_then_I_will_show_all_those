class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int cnt=n;
        int N=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(i>0){
                    if(nums[i-1]!=0)continue;
                }
                if(i<N-1){
                    if(nums[i+1]!=0)continue;
                }
                nums[i]=1;
                cnt--;
            }
        }
      if(cnt<=0)return true;
      return false;

    }
};