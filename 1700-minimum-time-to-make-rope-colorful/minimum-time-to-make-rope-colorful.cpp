class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int i=0;
        int ans=0;
        int maxii=INT_MIN;
        int minii=INT_MAX;
        int curr_sum=0;
        while(i<colors.size()){
            char curr=colors[i];
            if(i+1<colors.size() && colors[i]==colors[i+1]){
                while(i<colors.size() && colors[i]==curr){
                    maxii=max(maxii,time[i]);
                    curr_sum+=time[i];
                    i++;
                }
                ans=ans+curr_sum-maxii;
                curr_sum=0;
                maxii=INT_MIN;
            }else{
                i++;
            }
        }
        return ans;
        
    }
};