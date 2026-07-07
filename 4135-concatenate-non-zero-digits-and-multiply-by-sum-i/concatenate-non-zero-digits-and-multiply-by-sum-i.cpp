class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
        long long sum=0;
        string fans;
        while(n){
            int digit=n%10;
            sum+=digit;
            if(digit!=0)
            fans.push_back(digit+'0');
            n=n/10;
        }
        if(sum==0)return 0;
        reverse(fans.begin(),fans.end());
        // sort(fans.begin(),fans.end());
        long long nn=stoll(fans);
        return nn*sum*1LL;
    }
};