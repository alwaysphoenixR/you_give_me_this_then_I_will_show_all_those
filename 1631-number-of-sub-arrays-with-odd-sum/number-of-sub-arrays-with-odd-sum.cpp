class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        long long M=1000000007;
        long long  ans=0;
        int sum=0;
        unordered_map<int,int>m1;
        m1[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            // cout<<sum<<" SUM ";
            // if(sum%2==1)ans++;
            int rem=sum%2;
            // cout<<rem<<" REM ";
            int x=abs(rem-1)%2;
            if(rem==0){
                x=1;
            }
            // cout<<x<<"X"<<endl;
            if(m1.find(x)!=m1.end()){
                ans=(ans%M+m1[x]%M)%M;
            }
            m1[rem]++;
        }
        return ans%M;
    }
};