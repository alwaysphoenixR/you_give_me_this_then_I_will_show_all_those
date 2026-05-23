class Solution {
public:
    int mySqrt(int x) {
        int s=1;
        int e=x;
        int ans=x;
        while(s<=e){
            int mid=(e-s)/2+s;
            if(1ll*mid*mid>x){
                e=mid-1;
            }else{
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
        
    }
};