class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty()){
                ans[i]=0;
                st.push(i);
            }else{
                while(!st.empty() && nums[st.top()]<=nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i]=0;
                    st.push(i);
                }else{
                    auto j=st.top();
                    ans[i]=j-i;
                    st.push(i);
                }
            }
        }
        return ans;
    }
};