class Solution {
public:
bool can_we(vector<int>&nums,int p,int mid){
    int i=0;
    int j=nums.size()-1;

    int score=0;
    int curr_score=0;
    int curr_p=p;
    while(i<=j){
        while(i<=j && curr_p>=nums[i]){
            curr_p=curr_p-nums[i];
            curr_score++;
            score=max(curr_score,score);
            i++;
        }
        if(curr_score==0)break;
        curr_p+=nums[j];
        j--;
        curr_score--;
          score=max(curr_score,score);
    }
    if(score>=mid)return true;
    return false;
}
    int bagOfTokensScore(vector<int>& nums, int power) {
        int s=0;
        int e=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        while(s<=e){
            int mid=(e-s)/2+s;
            if(can_we(nums,power,mid)){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
    }
};