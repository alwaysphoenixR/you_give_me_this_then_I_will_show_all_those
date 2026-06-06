class Solution {
public:
int f1(int n,int i){
    if(n==1){
        return 0;
    }
    int curr=i;
    int prev_idx=ceil((curr*1.0)/2);
    if(f1(n-1,prev_idx)==0){
        if((prev_idx*2-1)==curr){
            return 0;
        }else{
            return 1;
        }

    }else{
          if((prev_idx*2-1)==curr){
            return 1;
        }else{
            return 0;
        }
    }
}
    int kthGrammar(int n, int k) {
        return f1(n,k);
    }
};