class Solution {
public:
    bool isPerfectSquare(int num) {
        int s=1;
        int e=num;
        while(s<=e){
            long long  mid=(e-s)/2+s;
            if((mid*mid*1ll)==num)return true;
            if(mid*mid*1ll>num){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return false;
        
    }
};