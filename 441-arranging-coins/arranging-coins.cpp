class Solution {
public:
    int arrangeCoins(int n) {
        int rem=n;
        int ans=0;
        for(int i=1;i<=n;i++){
           
            rem=rem-i;
            if(rem<0)break;
            ans++;
        }
        return ans;
    }
};