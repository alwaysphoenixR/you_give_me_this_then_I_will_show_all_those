class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        map<int,int>m1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            m1[nums[i]]++;
             if(nums[i]==0)cnt++;
        }
        vector<int>ans;
        if(nums.size()%2!=0)return {};
        for(auto[key,val]:m1){
            if(key==0)continue;
            if(val>0){
                
            int cnt1=val;
            int num1=key;
            int num2=num1*2;
            // cout<<num1<<" "<<num2<<" "<<cnt1;
            int cnt2=0;
            if(m1[num2]>=cnt1){
                while(cnt1){
                    ans.push_back(num1);
                    // cout<<"inserted ";
                    cnt1--;
                    m1[num2]--;
                }
                m1[num1]=0;  
            }
            cout<<endl;
            }
        }
        for(auto [key,val]:m1){
            if(key!=0 && val>0)return {};
        }
        if(cnt%2!=0){
            return {};
        }else{
        int sz=cnt/2;
        while(sz){
            ans.push_back(0);
            sz--;
        }
        }
        return ans;
    }
};